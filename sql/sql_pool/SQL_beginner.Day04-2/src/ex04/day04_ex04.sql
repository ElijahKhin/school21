create view v_symmetric_union as 
(
	(
		select person_id 
		from person_visits 
		where visit_date = '2022-01-02'
	)
	EXCEPT
	(
		select person_id 
		from person_visits
		where visit_date = '2022-01-06'
	)
)
UNION
(
	(
		select person_id 
		from person_visits
		where visit_date = '2022-01-06'
	)
	EXCEPT
	(
		select person_id 
		from person_visits 
		where visit_date = '2022-01-02'
	)
)
order by person_id;
