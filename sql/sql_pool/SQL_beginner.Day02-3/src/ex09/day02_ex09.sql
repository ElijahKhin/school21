with
	girls(id, name) as (
		select id, name
		from person
		where gender = 'female'
	),
	pizzas(id, pizza_name) as (
		select id, pizza_name
		from menu
		where pizza_name in ('pepperoni pizza', 'cheese pizza')
	)

select 
	name
from person_order
left join girls on person_order.person_id = girls.id
left join pizzas on person_order.menu_id = pizzas.id
where girls.id is not null and pizzas.id is not null
group by name
having 
	count(pizza_name) filter (WHERE pizza_name = 'pepperoni pizza') +
	count(pizza_name) filter (WHERE pizza_name = 'cheese pizza') > 1
order by name;
