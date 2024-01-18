--Session #1
begin transaction; -- declare transaction

show transaction isolation level;

select sum(rating) from pizzeria; --test
select sum(rating) from pizzeria; --test 

commit;

select sum(rating) from pizzeria; --test 

--Session #2
begin transaction; -- declare transaction

show transaction isolation level;

update pizzeria -- update exact table
set rating = 1 -- with this value
WHERE name = 'Pizza Hut'; -- with this filter
commit;

select sum(rating) from pizzeria; --test 
