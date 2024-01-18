drop table if exists person_audit;
drop function if exists fnc_trg_person_insert_audit() cascade;
delete from person where id = 10;

create table if not exists person_audit (
	created timestamp with time zone default now() not null,
	type_event char(1) default 'I' not null,
	row_id bigint not null,
	name varchar,
	age integer,
	gender varchar,
	address varchar
);
alter table person_audit add constraint ch_type_event check (type_event in ('I','U', 'D'));

create function fnc_trg_person_insert_audit() returns trigger AS $$
begin
	insert into person_audit(created, type_event, row_id, name, age, gender, address) 
	values(now(), 'I', new.id, new.name, new.age, new.gender, new.address);
	return new;
end;
$$ LANGUAGE PLPGSQL;

create or replace trigger trg_person_insert_audit 
after insert
on person
for each row
	execute procedure fnc_trg_person_insert_audit();

INSERT INTO person(id, name, age, gender, address) VALUES (10,'Damir', 22, 'male', 'Irkutsk');
select * from person_audit;
