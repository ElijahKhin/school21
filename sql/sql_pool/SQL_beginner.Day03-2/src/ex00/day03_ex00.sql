select 
	menu.pizza_name, 
	menu.price, 
	pizzeria.name as pizzeria_name, 
	person_visits.visit_date
from menu
left join pizzeria on pizzeria.id=menu.pizzeria_id
left join person_visits on person_visits.pizzeria_id=menu.pizzeria_id
where 
	person_visits.person_id=3 and 
	menu.price between 800 and 1000
order by pizza_name, price, pizzeria_name
