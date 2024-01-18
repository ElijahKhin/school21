select name, count(*) as count_of_visit 
from person_visits
left join person on person.id = person_visits.person_id
group by name
having count(*) > 3
