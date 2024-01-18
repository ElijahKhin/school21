select 
	name, 
	count(*) as count_of_visit 
from person_visits
left join person on person.id=person_visits.person_id
group by name
order by count_of_visit desc, name
limit 4;
