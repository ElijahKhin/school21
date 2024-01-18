with 
	date_gen(dates) as (
		select 
			dates::date as missing_date
		from
			generate_series
				('2022-01-01'::timestamp,
				 '2022-01-10'::timestamp, 
				 '1 day'::interval) as dates
	), 
	distinct_dates(visit_date) as (
		select distinct visit_date::date
		from person_visits
		where 
		person_visits.person_id = 1 or 
		person_visits.person_id = 2
	)

select dates as missing_date
from date_gen
left join distinct_dates on distinct_dates.visit_date=dates
where distinct_dates.visit_date is null
order by missing_date;

WITH t1 AS (SELECT *
		   	FROM person_visits
		   	WHERE (person_id = 1 OR person_id = 2)
		   	AND visit_date BETWEEN '2022-01-01' AND '2022-01-10'
		   )
SELECT CAST(list AS DATE) AS missing_date
FROM generate_series('2022-01-01', '2022-01-10', interval '1 day') list
LEFT JOIN t1
ON list = t1.visit_date
WHERE t1.visit_date IS NULL
ORDER BY missing_date ASC;
