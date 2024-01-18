select generated_date as missing_date from v_generated_dates
EXCEPT
select visit_date::date
from person_visits
where extract(month from visit_date) = 1
order by missing_date;

