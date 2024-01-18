with
	template(name, gender) as (
		select 
			pizzeria.name, person.gender
		from person_visits
		left join person on person_visits.person_id=person.id
		left join pizzeria on person_visits.pizzeria_id=pizzeria.id
	),
	male(name) as (
		select name from template where gender = 'male'
	),
	female(name) as (
		select name from template where gender = 'female'
	) 

(
		select name from male
	EXCEPT ALL
		select name from female
)
UNION ALL
(
		select name from female
	EXCEPT ALL
		select name from male
) order by name;
