with
	visited_pizzeria(visited_id) as (
		select pizzeria_id
		from person_visits
		where 
			person_id = 9 and
			visit_date = '2022-01-08'
	)

select 
	pizzeria.name as pizzeria_name
from menu
left join pizzeria on menu.pizzeria_id=pizzeria.id
left join visited_pizzeria on menu.pizzeria_id=visited_pizzeria.visited_id
where
	visited_id is not Null and 
	menu.price < 800;
