select distinct name 
from person_order
left join person on person.id = person_order.person_id
order by name
