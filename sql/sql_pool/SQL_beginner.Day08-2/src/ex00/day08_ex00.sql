--Session #1
begin transaction; -- declare transaction

update pizzeria -- update exact table
set rating = 5 -- with this value
WHERE name = 'Pizza Hut'; -- with this filter

select * from pizzeria where name = 'Pizza Hut'; --test

commit transaction; -- commit results of transaction to all sessions

--Session #2
select * from pizzeria where name = 'Pizza Hut'; --test
