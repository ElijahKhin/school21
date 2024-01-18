with
	template(name, gender) as (
		select 
			pizzeria.name, person.gender
		from person_order
		left join person on person_order.person_id=person.id
		left join menu on person_order.menu_id=menu.id
		left join pizzeria on menu.pizzeria_id=pizzeria.id
	),
	male(name) as (
		select name from template where gender = 'male'
	),
	female(name) as (
		select name from template where gender = 'female'
	) 

(
		select name from male
	EXCEPT
		select name from female
)
UNION
(
		select name from female
	EXCEPT
		select name from male
);
