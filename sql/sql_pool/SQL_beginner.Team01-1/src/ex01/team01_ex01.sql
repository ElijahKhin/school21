insert into currency values (100, 'EUR', 0.85, '2022-01-01 13:29');
insert into currency values (100, 'EUR', 0.79, '2022-01-08 13:29');

with ag1 as (
    select b.user_id, b.money, b.type, b.currency_id, b.updated as balance, c.id,
           c.name, c.rate_to_usd, c.updated as currency
    from balance b
             join currency c on c.id = b.currency_id and b.updated > c.updated),
     ag2 as (
         select b.user_id, b.money, b.type, b.currency_id, b.updated as balance,
                c.id, c.name, c.rate_to_usd, c.updated as currency
         from balance b
                  join currency c on c.id = b.currency_id and b.updated < c.updated),
     connect as (select p.money AS c_money,
                        p.type as c_type,
                        p.currency_id as c_currency_id,
                        min(p.valid_date) as valid_date
                 FROM (
                          select ag1.money,
                                 ag1.type,
                                 ag1.currency_id,
                                 max(ag1.currency) as valid_date
                          from ag1
                          group by ag1.money, ag1.type, ag1.currency_id
                          union
                          select ag2.money,
                                 ag2.type,
                                 ag2.currency_id,
                                 min(ag2.currency) as valid_date
                          from ag2
                          group by ag2.money, ag2.type, ag2.currency_id) p
                 group by p.money, p.type, p.currency_id)
select coalesce(u.name, 'not defined') as name,
       coalesce(u.lastname, 'not defined') as lastname,
       c2.name as currency_name,
       b.money * c2.rate_to_usd as currency_in_usd
from connect c
         join balance b ON b.money = c.c_money and b.type = c.c_type
         join currency c2 ON c2.updated = c.valid_date and c2.id = c.c_currency_id
         left join "user" u ON b.user_id = u.id
order by name desc , lastname, currency_name;
