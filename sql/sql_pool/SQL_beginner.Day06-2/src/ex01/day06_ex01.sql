insert into person_discounts
select
	row_number() over () as id,
	person_id,
	pizzeria_id,
	case
		when count(person_order.id) = 1 then 10.5
		when count(person_order.id) = 2 then 22
		else 30
	end as discount
from person_order
left join menu on menu.id = person_order.menu_id
group by person_id, pizzeria_id
order by id
