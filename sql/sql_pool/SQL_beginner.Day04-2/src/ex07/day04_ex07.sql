with visit(pizzeria_id) as (
	select person_visits.pizzeria_id 
	from person_visits
	left join person on person.id=person_visits.person_id
	left join menu on menu.pizzeria_id=person_visits.pizzeria_id
	where 
		visit_date = '2022-01-08' and
		name = 'Dmitriy' and
		price < 800
)

insert into person_visits (id, person_id, pizzeria_id, visit_date)
values(
	(select max(id) from person_visits) + 1,
	(select id from person where name = 'Dmitriy'),
	(select pizzeria_id from menu where price < 800 and pizzeria_id not in(select pizzeria_id from visit) limit 1),
	'2022-01-8'
);

refresh materialized view mv_dmitriy_visits_and_eats;
