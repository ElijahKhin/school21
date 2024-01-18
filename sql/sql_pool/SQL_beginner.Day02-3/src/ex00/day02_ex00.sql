select name, rating 
from ( 
	select 
		pizzeria.name as name, 
		pizzeria.rating as rating, 
		(
			case
				when pv.pizzeria_id::varchar <> '' then 'visited'
				else 'not visited'
			end
		) as isVisited
	from pizzeria
	LEFT JOIN (
		select distinct person_visits.pizzeria_id 
		from person_visits) as pv 
	on pizzeria.id=pv.pizzeria_id
) as marked_table
where marked_table.isVisited = 'not visited';
