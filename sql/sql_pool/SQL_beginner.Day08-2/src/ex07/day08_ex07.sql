--Session #1
begin transaction; -- declare transaction

update pizzeria -- update exact table
set rating = 2 -- with this value
WHERE id = 1; -- with this filter

update pizzeria -- update exact table
set rating = 1 -- with this value
WHERE id = 2; -- with this filter
commit;

--Session #2
begin transaction; -- declare transaction

update pizzeria -- update exact table
set rating = 3 -- with this value
WHERE id = 2; -- with this filter

update pizzeria -- update exact table
set rating = 2 -- with this value
WHERE id = 1; -- THERE IS WILL BE DEADLOCK!!!
commit;
