with
	template as (
		select 
		address, 
		round((max(age) - min(age) / max(age)::numeric), 2) as formula, 
		round(avg(age), 2) as average
		from person
		group by address
		order by address
	)

select 
	*,
	case
		when formula > average then 'true'
		else 'false'
	end as comparison
from template;
