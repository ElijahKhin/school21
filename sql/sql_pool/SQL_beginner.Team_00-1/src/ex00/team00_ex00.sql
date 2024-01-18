create table if not exists nodes (
	id bigint primary key,
	point1 varchar not null,
	point2 varchar not null,
	cost integer not null
);

insert into nodes(id, point1, point2, cost) 
values 
	(1, 'a', 'b', 10),
	(2, 'a', 'c', 15),
	(3, 'a', 'd', 20),
	(4, 'b', 'a', 10),
	(5, 'b', 'c', 35),
	(6, 'b', 'd', 25),
	(7, 'c', 'a', 15),
	(8, 'c', 'b', 35),
	(9, 'c', 'd', 30),
	(10, 'd', 'a', 20),
	(11, 'd', 'b', 25),
	(12, 'd', 'c', 30);

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
order by total_cost, tour;
