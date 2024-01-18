select dates::date as missing_date
from generate_series
        ( '2022-01-01'::timestamp,
          '2022-01-10'::timestamp, 
          '1 day'::interval) dates
left join (
	select distinct visit_date::date 
	from person_visits 
	where 
	person_visits.person_id = 1 or 
	person_visits.person_id = 2) as distinct_dates 
on distinct_dates.visit_date=dates
where distinct_dates.visit_date is null
order by missing_date;
