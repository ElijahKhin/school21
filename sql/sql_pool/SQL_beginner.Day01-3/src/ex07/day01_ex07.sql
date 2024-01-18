select 
	person_order.order_date, 
	(person.name || ' (age:' || person.age::varchar || ')') as person_information
from person_order
INNER JOIN person on person_order.person_id=person.id 
order by order_date, person_information;
