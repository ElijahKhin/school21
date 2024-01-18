select 
	menu.pizza_name as pizza_name,
	pizzeria.name as pizzeria_name
from person_order
left join person on person.id=person_order.person_id
left join menu on menu.id=person_order.menu_id
left join pizzeria on menu.pizzeria_id=pizzeria.id
where person.name in ('Denis', 'Anna')
order by pizza_name, pizzeria_name;
