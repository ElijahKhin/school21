with
	template(id, pizza_name, pizzeria_name, price) as (
		select 
			menu.id,
			pizza_name, 
			name as pizzeria_name,
			price 
		from menu
		left join pizzeria on pizzeria.id=menu.pizzeria_id
	)

select 
	t1.pizza_name as pizza_name, 
	t1.pizzeria_name as pizzeria_name_1, 
	t2.pizzeria_name as pizzeria_name_2,
	t2.price as price_right
from template as t1, template as t2
where 
	t1.price = t2.price and 
	t1.pizza_name = t2.pizza_name and
	t1.pizzeria_name <> t2.pizzeria_name and
	t1.id > t2.id
order by pizza_name;
