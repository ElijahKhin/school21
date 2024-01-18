(select name, count(*), 'order' as action_type  
from person_order 
left join menu on menu.id = person_order.menu_id
left join pizzeria on pizzeria.id = menu.pizzeria_id
group by name
order by 3, 2 desc limit 3)
UNION ALL
(select name, count(*), 'visit' as action_type  
from person_visits 
left join pizzeria on pizzeria.id = person_visits.pizzeria_id
group by name
order by 3, 2 desc limit 3) 
