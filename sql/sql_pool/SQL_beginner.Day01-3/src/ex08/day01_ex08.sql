select 
	person_order.order_date, 
	(person_edit.name || ' (age:' || person_edit.age || ')') as person_information
from person_order
NATURAL JOIN (
	select 
	person.id as person_id, 
	person.name, person.age 
	from person
) as person_edit
order by order_date, person_information;
