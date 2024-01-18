--Session #1
begin transaction; -- declare transaction

show transaction isolation level;
set transaction isolation level repeatable read;

select * from pizzeria where name = 'Pizza Hut'; --test

update pizzeria -- update exact table
set rating = 4 -- with this value
WHERE name = 'Pizza Hut'; -- with this filter
commit;

select * from pizzeria where name = 'Pizza Hut'; --test

--Session #2
begin transaction; -- declare transaction

show transaction isolation level;
set transaction isolation level repeatable read;

select * from pizzeria where name = 'Pizza Hut'; --test

update pizzeria -- update exact table
set rating = 3.6 -- with this value
WHERE name = 'Pizza Hut'; -- with this filter
commit;

select * from pizzeria where name = 'Pizza Hut'; --test
