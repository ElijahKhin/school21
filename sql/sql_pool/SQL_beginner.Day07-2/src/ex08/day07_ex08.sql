select person.id, count(*) 
from person_order
left join person on person.id = person_order.person_id
left join menu on menu.id = person_order.menu_id
left join pizzeria on pizzeria.id = menu.pizzeria_id
group by person.id 
