select menu.id as object_id, menu.pizza_name as object_name
from menu
UNION ALL
select person.id as object_id, person.name as object_name
from person
order by object_id, object_name;
