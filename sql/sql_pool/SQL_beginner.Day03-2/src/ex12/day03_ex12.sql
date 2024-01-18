with
	template(id, person_id, menu_id, order_date) as (
		select 
			person_id + (select max(id) from person_order) as id, 
			person_id, 
			(select id from menu where pizza_name = 'greek pizza' limit 1) as menu_id,
			'2022-02-25'::date as order_date
		from (
			select person_id
			from generate_series(1, (select max(id) from person)) as person_id
		) as person_id
	)

insert into person_order (id, person_id, menu_id, order_date)
select * from template;
