select 
	menu.pizza_name,
	menu.price,
	pizzeria.name as pizzeria_name
from menu
left join person_order on person_order.menu_id=menu.id
left join pizzeria on pizzeria.id=menu.pizzeria_id
where order_date is null
order by menu.pizza_name, menu.price;
