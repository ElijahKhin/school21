drop function if exists fnc_trg_person_update_audit() cascade;

create function fnc_trg_person_update_audit() returns trigger AS $$
begin
	insert into person_audit(type_event, row_id, name, age, gender, address) 
	values('U', old.id, old.name, old.age, old.gender, old.address);
	return old;
end;
$$ LANGUAGE PLPGSQL;

create or replace trigger trg_person_update_audit 
after update
on person
for each row
	execute procedure fnc_trg_person_update_audit();


update person set name = 'Bulat' where id = 10;
update person set name = 'Damir' where id = 10;
select * from person_audit;
