select 
	person.name as person_name, 
	menu.pizza_name as pizza_name, 
	pizzeria.name as pizzeria_name 
from person_order
LEFT JOIN menu on menu.id = person_order.menu_id
LEFT JOIN person on person.id = person_order.person_id
LEFT JOIN pizzeria on menu.pizzeria_id = pizzeria.id
order by person_name, pizza_name, pizzeria_name;
