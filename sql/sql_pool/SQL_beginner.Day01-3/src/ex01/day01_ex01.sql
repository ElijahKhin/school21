(
	select person.name as object_name
	from person
	order by object_name
)
UNION ALL
(
	select menu.pizza_name as object_name
	from menu
	order by object_name
);
