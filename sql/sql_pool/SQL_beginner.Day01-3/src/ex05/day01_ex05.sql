select *
from person
CROSS JOIN pizzeria
order by person.id, pizzeria.id;
