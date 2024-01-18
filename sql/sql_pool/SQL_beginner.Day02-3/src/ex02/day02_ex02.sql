select 
	coalesce(person.name, '-') as person_name, 
	coalesce(pv.visit_date::varchar, 'null') as visit_date, 
	coalesce(pizzeria.name, '-') as pizzeria_name
from person
full join (
	select * 
	from person_visits 
	where visit_date between '2022-01-01' and '2022-01-03'
) as pv on person.id=pv.person_id
full join pizzeria on pv.pizzeria_id=pizzeria.id
order by person_name, visit_date, pizzeria_name;
