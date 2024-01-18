create index if not exists id_person_name on person (UPPER(person.name));

set enable_indexscan = on;
set enable_seqscan = off;

explain analyze
select name from person where UPPER(name)= 'DMITRIY'; 
