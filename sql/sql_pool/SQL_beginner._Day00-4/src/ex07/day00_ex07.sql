select person.id, person.name,
case
	when person.age between 10 and 20 THEN 'interval #1'
	when person.age between 21 and 23 THEN 'interval #2'
	else 'interval #3'
end as interval_info
from person;
