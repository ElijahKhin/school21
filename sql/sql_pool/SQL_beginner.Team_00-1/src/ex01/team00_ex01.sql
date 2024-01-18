with 
	recursive tour(iter, point1, point2, total_cost, tour) as (
		select 
			1 as iter,
			point1,
			point2,
			cost as total_cost,
			point1 || ',' || point2 as tour
		from
			nodes
		where 
			nodes.point1 = 'a'
		union
		select
			iter + 1,
			nodes.point1,
			nodes.point2,
			nodes.cost + tour.total_cost as total_cost,
			tour.tour || ',' || nodes.point2 as tour
		from
			tour, nodes
		where
			iter < 4 and
			tour.point1 <> nodes.point2 and
			tour.point2 = nodes.point1
	),
	all_tours(total_cost, tour) as (
		select total_cost, tour from tour where iter = 4 and point2 = 'a'
	)

select total_cost, '{' || tour || '}' as tour from all_tours
where total_cost = (select min(total_cost) from all_tours)
union all
select total_cost, '{' || tour || '}' as tour from all_tours
where total_cost = (select max(total_cost) from all_tours)
order by total_cost, tour;
