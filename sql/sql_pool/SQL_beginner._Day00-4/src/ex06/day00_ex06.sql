select ex05.name, ex05.name = 'Denis' as check_name from (
	select (
		select person.name 
		from person 
		where person.id = person_order.person_id
	) as NAME
	from person_order
	where (
		person_order.menu_id = 13 or
		person_order.menu_id = 14 or
		person_order.menu_id = 18
	) and person_order.order_date = '2022-01-07'
) as ex05;
