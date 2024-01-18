select 
	pizzeria.name, 
	count(*) as count_of_orders, 
	round(avg(price), 2) as average_price,
	max(price) as average_price,
	min(price) as average_price
from person_order
left join menu on menu.id = person_order.menu_id
left join pizzeria on pizzeria.id = menu.pizzeria_id
group by name
order by name
