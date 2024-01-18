create view v_generated_dates as
select generated_date::date
from generate_series(
	'2022-01-01'::timestamp, 
	'2022-01-31'::timestamp, 
	'1 day') as generated_date
order by generated_date;
