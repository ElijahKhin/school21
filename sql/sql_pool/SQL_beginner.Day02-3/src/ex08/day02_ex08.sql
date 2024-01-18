with
	guys(id, name) as (
		select id, name
		from person
		where 
			address in ('Moscow', 'Samara') and 
			gender = 'male'
	),
	pizzas(id, pizza_name) as (
		select id, pizza_name
		from menu
		where 
			pizza_name in ('pepperoni pizza', 'mushroom pizza')
	)

select name
from person_order
left join guys on person_order.person_id = guys.id
left join pizzas on person_order.menu_id = pizzas.id
where guys.id is not null and pizzas.id is not null
order by name desc;
