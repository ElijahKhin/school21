create or replace view get_base as
	select *
	from checks 
	left join transactions using(transaction_id) 
	left join cards using(customer_card_id)
	left join product_grid using(sku_id)
	where transactions.transaction_datetime <= (select * from date_of_analysis order by 1 desc);

create or replace view get_check as
	with 
	av_bill as (
		select 
			t.customer_id, 
			avg(transaction_summ)::numeric(11, 2) as av_check 
		from (
			select distinct 
				base.customer_id, 
				transaction_id, 
				transaction_summ
			from get_base as base) as t
		group by t.customer_id),

	av_bill_segments as (
		select 
			*,
			case
				when av_check >= (select percentile_disc(0.90) within group(order by av_check) from av_bill) then 'High'
				when av_check < (select percentile_disc(0.65) within group(order by av_check) from av_bill) then 'Low'
				else 'Medium'
			end as segment_split
		from av_bill
	)
	select * from av_bill_segments;

create or replace view get_frequency as
	with 
	frequency as (
		select 
			freq_base.customer_id, 
			(((extract(epoch from max(transaction_datetime)) - 
			extract(epoch from min(transaction_datetime))) / 60 / 60 / 24) / count(*))::numeric(11,4) as frequency
		from ( 
			select distinct 
				base.customer_id, transaction_id, transaction_datetime
			from get_base as base
			order by customer_id, transaction_datetime) as freq_base
		group by freq_base.customer_id
	),
	freq_segments as (
		select 
			*,
			case
				when frequency <= (select percentile_disc(0.10) within group(order by frequency) from frequency) then 'Often'
				when frequency > (select percentile_disc(0.35) within group(order by frequency) from frequency) then 'Rarely'
				else 'Occasionally'
			end as segment_frequency
		from frequency
	)
	select * from freq_segments;

create or replace view last_deal as 
	with 
	last_deal as (
		select 
			freq_base.customer_id,
			((extract(epoch from (select * from date_of_analysis order by 1 desc)) - 
			extract(epoch from max(transaction_datetime))) / 60 / 60 / 24)::numeric(11,4) as last_deal
		from ( 
			select distinct 
				base.customer_id, transaction_id, transaction_datetime
			from get_base as base
			order by customer_id, transaction_datetime) as freq_base
		group by freq_base.customer_id
	)
	select * from last_deal;

create or replace view get_churn as 
	with 
	churn_rate as (
		select last_deal.customer_id, (last_deal / freq.frequency)::numeric(11, 4) as churn_rate 
		from last_deal
		left join get_frequency as freq on freq.customer_id = last_deal.customer_id
	),
	churn_segments as (
		select 
			*,
			case
				when churn_rate <= 2 then 'Low'
				when churn_rate > 5 then 'High'
				else 'Medium'
			end as segment_churn
		from churn_rate
	)
	select * from churn_segments;

create or replace view segment_view as 
	with
	av_check as (
		select distinct segment_split as check_seg
		from get_check
	),
	freq as (
		select distinct segment_frequency as freq
		from get_frequency
	),
	churn as (
		select distinct segment_churn as churn
		from get_churn
	),
	segment as (
		select
			check_seg as customer_average_check_segment,
			freq as customer_frequency_segment,
			churn as customer_churn_segment
		from av_check 
		cross join freq
		cross join churn
		order by 
			array_position(array['Low', 'Medium', 'High'], check_seg),  
			array_position(array['Rarely', 'Occasionally', 'Often'], freq),
			array_position(array['Low', 'Medium', 'High'], churn)
	),
	segment_number as (
		select row_number() over() as segment, * from segment
	)
	select * from segment_number;


create or replace view customer_primary_list as
	with
	main_list as (
		select 
			customer_id,
			transaction_store_id,
			max(transaction_datetime) as latest_transaction,
			count(transaction_id) as qty_transaction,
			(count(transaction_id) / sum(count(transaction_id)) over(partition by customer_id))::numeric(5, 4) as store_share
		from get_base 
		group by 
			customer_id,
			transaction_store_id
		order by 
			customer_id,
			count(transaction_id) desc
	),
	store_ranking as (
		select 
			*,
			rank() over(partition by customer_id order by transaction_datetime desc)
		from (
			select distinct 
				customer_id,
				transaction_store_id,
				transaction_id,
				transaction_datetime
			from
				get_base
			order by customer_id, transaction_datetime
		) as top_base
	),
	first_criteria as (
		select customer_id, transaction_store_id
		from (
			select 
				customer_id,
				transaction_store_id,
				max(first_criteria_marker) as first_criteria_marker
			from (
				select 
					customer_id, 
					transaction_store_id, 
					count(transaction_datetime) as first_criteria_marker 
				from store_ranking where rank <= 3
				group by customer_id, transaction_store_id
				order by customer_id
			) tmp
			group by customer_id, transaction_store_id
			order by customer_id
		) tmp2
		where first_criteria_marker = 3
	),
	second_criteria as (
		select 
			*,
			rank() over(partition by customer_id order by store_share desc) rank_share,
			rank() over(partition by customer_id order by latest_transaction desc) rank_date
		from main_list
	),
	third_criteria as (
		select customer_id, transaction_store_id
		from (
			select 
				*, 
				lag(latest_transaction, 1) over w
				from second_criteria 
			where rank_share = 1
			window w as (partition by customer_id order by latest_transaction desc) 
		) tmp
		where lag is null
	)
	select * 
	from first_criteria
	union
	select *
	from third_criteria
	where customer_id not in (select customer_id from first_criteria);

create or replace view customers_view as
	select 
		customer_id,
		av_check as customer_average_check,
		segment_split as customer_average_check_segment,
		frequency as customer_frequency,
		segment_frequency as customer_frequency_segment,
		last_deal as customer_inactive_period,
		churn_rate as customer_churn_rate,
		segment_churn as customer_churn_segment,
		segment as customer_segment,
		transaction_store_id as customer_primary_store
	
	from personal_info
	left join get_check using(customer_id)
	left join get_frequency using(customer_id)
	left join last_deal using(customer_id)
	left join get_churn using(customer_id)
	left join 
		segment_view sv on 
		get_check.segment_split = sv.customer_average_check_segment and
		get_frequency.segment_frequency = sv.customer_frequency_segment and 
		get_churn.segment_churn = sv.customer_churn_segment
	left join customer_primary_list using(customer_id)
	order by customer_id;
