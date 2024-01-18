with
	orders as (
		select name, count(*), 'order' as action_type  
		from person_order 
		left join menu on menu.id = person_order.menu_id
		left join pizzeria on pizzeria.id = menu.pizzeria_id
		group by name

	),
	visits as (
		select name, count(*), 'visit' as action_type  
		from person_visits 
		left join pizzeria on pizzeria.id = person_visits.pizzeria_id
		group by name
	)

select 
	case 
		when orders.name is not null then orders.name
		else visits.name
	end as name,
	case 
		when orders.count is null then 0
		else orders.count
	end +
	case 
		when visits.count is null then 0
		else visits.count
	end as total_count
from visits
full join orders on orders.name = visits.name
order by total_count desc, name;
