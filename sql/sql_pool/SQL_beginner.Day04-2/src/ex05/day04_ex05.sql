create view v_price_with_discount as
select 
	person.name, 
	menu.pizza_name, 
	menu.price, 
	round(menu.price * 0.9) as discount_price 
from person_order
left join menu on menu.id=person_order.menu_id
left join person on person.id=person_order.person_id
order by name, pizza_name;
