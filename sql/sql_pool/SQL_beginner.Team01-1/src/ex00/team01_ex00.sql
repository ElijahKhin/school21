with 
	aggregation AS (
		select 
			b.user_id,
            b.type                                    as type,
            sum(b.money)                              as volume,
            coalesce(c.name, 'not defined')           as currency_name,
            coalesce(c.rate_to_usd, 1)                as last_rate_to_usd,
            sum(b.money * coalesce(c.rate_to_usd, 1)) as total_volume_in_usd
        from balance b
        left join currency c on c.id = b.currency_id and c.updated = (
			SELECT max(updated)
			from currency
           	where b.currency_id = id
		)
        group by b.user_id, b.type, currency_name, last_rate_to_usd)
select coalesce(u.name, 'not defined') AS name,
       coalesce(u.lastname, 'not defined') AS lastname,
       ag.type,
       ag.volume,
       ag.currency_name,
       ag.last_rate_to_usd,
       ag.total_volume_in_usd
from "user" as u
         full join aggregation as ag on u.id = ag.user_id
order by name desc , lastname , type;
