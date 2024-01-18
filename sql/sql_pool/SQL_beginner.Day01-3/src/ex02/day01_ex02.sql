(
	select menu.pizza_name
	from menu
)
UNION
(
	select null as pizza_name limit 0
)
order by pizza_name desc;
