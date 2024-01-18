with
	visited(name) as (
		select 
			pizzeria.name
		from person_visits
		left join pizzeria on person_visits.pizzeria_id=pizzeria.id
		where person_visits.person_id = 2
	),
	ordered(name) as (
		select 
			pizzeria.name
		from person_order
		left join menu on person_order.menu_id=menu.id
		left join pizzeria on menu.pizzeria_id=pizzeria.id
		where person_order.person_id = 2
	)

(
		select name from visited
	EXCEPT
		select name from ordered
)
