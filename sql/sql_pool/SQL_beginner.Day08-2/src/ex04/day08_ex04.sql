--Session #1
begin transaction; -- declare transaction

show transaction isolation level;
set transaction isolation level serializable;

select * from pizzeria where name = 'Pizza Hut'; --test
select * from pizzeria where name = 'Pizza Hut'; --test

commit;

select * from pizzeria where name = 'Pizza Hut'; --test

--Session #2
begin transaction; -- declare transaction

show transaction isolation level;
set transaction isolation level serializable;

update pizzeria -- update exact table
set rating = 3.0 -- with this value
WHERE name = 'Pizza Hut'; -- with this filter
commit;

select * from pizzeria where name = 'Pizza Hut'; --test
