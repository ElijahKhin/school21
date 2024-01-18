select 
	person.name,
	menu.pizza_name,
	menu.price,
	round((1 - person_discounts.discount / 100) * menu.price) as discount_price,
	pizzeria.name as pizzeria_name
from person_order
left join person on person.id = person_order.person_id
left join menu  on menu.id = person_order.menu_id
left join pizzeria  on menu.pizzeria_id = pizzeria.id
left join person_discounts  on person_discounts.person_id = person_order.person_id and person_discounts.pizzeria_id = pizzeria.id
order by name, pizza_name
