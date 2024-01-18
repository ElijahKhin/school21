drop view if exists group_base cascade;
create view group_base as 
	select distinct 
		customer_id,
		group_id,
		transaction_id,
		transaction_datetime,
		row_number() over(partition by customer_id, group_id order by transaction_datetime desc) as date_rank,
		sum(sku_purchase_price * sku_amount)::numeric(11,4) cost,
		sum(sku_summ_paid) revenue,
		sum(sku_summ_paid) - sum(sku_purchase_price * sku_amount) abs_margin
	from (
		select 
			g.*,
			sku_purchase_price 
		from get_base g 
		left join stores using(transaction_store_id, sku_id)
	) base
	group by
		customer_id,
		group_id,
		transaction_id,
		transaction_datetime
	order by 1,2,4 desc;

drop view if exists affinity_index cascade;
create view affinity_index as 
	select 
		customer_id, 
		group_id, 
		count(transaction_id) / sum(count(transaction_id)) over(partition by customer_id)::numeric(11, 4) as group_affinity_index
	from group_base 
	group by 
	customer_id, group_id;

drop view if exists group_churn_rate;
create view group_churn_rate as
with 
	days_from_last_deal as (
		select
			customer_id,
			group_id,
			((extract(epoch from (select * from date_of_analysis order by 1 desc)) - 
			extract(epoch from max(transaction_datetime))) / 60 / 60 / 24)::numeric(11,4) as last_deal
		from group_base
		group by 
			customer_id,
			group_id
		order by 1,2
	),
	frequency as (
		select
			customer_id,
			group_id,
			((extract(epoch from max(transaction_datetime)) - 
			extract(epoch from min(transaction_datetime))) / 60 / 60 / 24 / count(transaction_id))::numeric(11,4) as frequency
		from group_base
		group by 
			customer_id,
			group_id
	),
	churn_rate as (
		select 
			f.customer_id,
			f.group_id,
			f.frequency,
			(d.last_deal / nullif(f.frequency, 0))::numeric(11,4) as group_churn_rate
		from frequency f
		left join days_from_last_deal d using(customer_id, group_id)
	)
	select * from churn_rate;


drop view if exists stability;
create view stability as
with
	intervals as (
		select 
			customer_id,
			group_id,
			transaction_datetime,
			(
				(
					extract(epoch from transaction_datetime) - 
					extract(epoch from 
						lag(transaction_datetime, 1) over (partition by customer_id, group_id order by transaction_datetime)
					)
				) / 60 / 60 / 24
			)::numeric(11,4) as intervals
		from group_base
		order by 1,2,3
	),
	abs_dev as (
		select
			i.customer_id,
			i.group_id,
			intervals,
			f.frequency,
			case
				when (intervals - f.frequency) < 0 then (intervals - f.frequency) * (-1)
				else (intervals - f.frequency)
			end as abs_dev
		from intervals i
		left join group_churn_rate f using(customer_id, group_id)
	),
	rel_dev as (
		select *,
			abs_dev / frequency as rel_dev
		from abs_dev
	),
	stability as (
		select
			customer_id,
			group_id,
			avg(rel_dev)::numeric(11,4) as group_stability_index
		from rel_dev
		group by customer_id, group_id
	)
	select * from stability;
	
drop function if exists fun_margin;
create function fun_margin(days int default 0, tran_num int default 0) 
returns table(customer_id bigint, group_id bigint, some_int int ,group_margin numeric(11,4)) as $$
declare
	ref_date date;
begin
	execute format(
		'select analysis_formation - interval ''%s days'' from date_of_analysis order by analysis_formation desc limit 1', days) into ref_date;
	if days = 0 and tran_num = 0 then
		return query
			select 
				g.customer_id,
				g.group_id,
				count(g.transaction_id)::int,
				sum(abs_margin)
			from group_base g
			group by g.customer_id, g.group_id;
	elsif days = 0 and tran_num <> 0 then
		if tran_num < 0 then
			raise exception 'Arguments can''t be less than zero';
		end if;
		return query
			select 
				g.customer_id,
				g.group_id,
				count(g.transaction_id)::int,
				sum(abs_margin)
			from (select * from group_base where date_rank <= tran_num) g
			group by g.customer_id, g.group_id;
	elsif days <> 0 and tran_num = 0 then
		if days < 0 then
			raise exception 'Arguments can''t be less than zero';
		end if;
		return query
			select 
				g.customer_id,
				g.group_id,
				count(g.transaction_id)::int,
				sum(abs_margin)
			from (select * from group_base where transaction_datetime >= ref_date) g
			group by g.customer_id, g.group_id;
	end if;
end;
$$ language plpgsql;

drop view if exists discounts;
create view discounts as
	with 
	all_transactions as (
		select 
			customer_id, 
			group_id, 
			min(case when sku_discount = 0 then null else sku_discount / sku_summ end)::numeric(11,4) min_discount,
			(sum(sku_summ_paid) / sum(sku_summ))::numeric(11,4) group_average_discount,
			count(transaction_id)::numeric(11, 4) all_transactions
		from get_base 
		group by customer_id, group_id
	),
	with_discount as (
		select 
			customer_id, 
			group_id, 
			count(transaction_id)::numeric(11, 4) with_discount
		from get_base 
		where sku_discount > 0 
		group by customer_id, group_id
	),
	share_discounts as (
		select
			customer_id,
			group_id,
			all_transactions,
			with_discount,
			(with_discount / all_transactions)::numeric(11, 4) group_discount_share,
			min_discount group_min_discount,
			group_average_discount
		from all_transactions
		left join with_discount using(customer_id, group_id)
	)
	select * from share_discounts order by 1,2;

create or replace view groups_view as
	select 
		customer_id,
		group_id,
		group_affinity_index::numeric(11,4),
		group_churn_rate,
		group_stability_index,
		group_margin,
		group_discount_share,
		group_min_discount,
		group_average_discount
	from affinity_index
	left join group_churn_rate using(customer_id, group_id)
	left join stability using(customer_id, group_id)
	left join fun_margin() using(customer_id, group_id)
	left join discounts using(customer_id, group_id)
	order by customer_id, group_id;
	
