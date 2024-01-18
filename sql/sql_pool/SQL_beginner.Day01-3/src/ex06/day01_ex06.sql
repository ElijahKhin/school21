(
	select person_order.order_date as action_date, person.name as person_name
	from person_order
	INNER JOIN person on person_order.person_id=person.id 
)
INTERSECT
(
	select person_visits.visit_date as action_date, person.name as person_name
	from person_visits
	INNER JOIN person on person_visits.person_id=person.id 
)
order by action_date, person_name desc;
