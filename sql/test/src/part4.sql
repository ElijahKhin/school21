set client_min_messages = 'INFO'; --use -q to quite notifications

drop database if exists info_21_part4;
create database info_21_part4;
\c info_21_part4;
\i part1.sql;

drop table if exists TableNameTableName;
create table TableNameTableName  (
	column1 int,
	column2 varchar,
	column3 float
);

drop table if exists TableName;
create table TableName  (
	column1 int,
	column2 varchar,
	column3 float
);

drop table if exists TableName1;
create table TableName1  (
	column1 int,
	column2 varchar,
	column3 float
);

drop table if exists TableName2;
create table TableName2  (
	column1 int,
	column2 varchar,
	column3 float
);

drop table if exists ItsATrapTableName;
create table  ItsATrapTableName (
	column1 int,
	column2 varchar,
	column3 float
);

create or replace function dummy_function0() returns trigger as $$
begin
	select 1;
end;
$$ language plpgsql;

create or replace function dummy_function1(dummy varchar) returns void as $$
begin
	select 1;
end;
$$ language plpgsql;

create or replace function dummy_function2(dummy varchar, dummy_int int) returns void as $$
begin
	select 1;
end;
$$ language plpgsql;
comment on function dummy_function2 is 'This is your comment!';
comment on function dummy_function0 is 'jaflksdjf;sdkjf; This is your comment!aljfaskdl jf;lsakdjf ';
comment on function dummy_function1 is ' ';

create or replace trigger dummy_trigger_insert
before insert or update on TableName1
for each row
	execute function dummy_function0();


create or replace trigger dummy_trigger_delete
after delete or update on TableName1
for each row
	execute function dummy_function0();

create or replace function user_triggers() returns table(trigger_name text, event_object_table text) as $$
begin
	return query
	with
		user_triggers as (
		select 
			tr.trigger_name::text,
			tr.event_object_table::text
		from information_schema.triggers as tr
		where 
			trigger_schema !~* '^pg_*' and 
			trigger_schema <> 'information_schema'
)

	select * from user_triggers;
end;
$$ language plpgsql;



create or replace function pg_proc_data() returns 
	table(
		owner text, 
		proname text, 
		input_parameters text, 
		all_parameters text, 
		pronargs int, 
		routine_type text, 
		retset text, 
		description text) as $$
begin
	return query
	with
		pg_proc_data as (
		select
			u.usename::text as owner,
			p.proname::text,
			pg_catalog.pg_get_function_identity_arguments(p.oid)::text as input_parameters,
			array_to_string(array_agg(p.proargnames) filter(where proargnames <> '{}'), ', ')::text  as all_parameters,
			p.pronargs::int,
			p.prokind::text as routine_type,
			case
			when proretset = 't' then 'vector' else 'scalar'
			end as retset,
			obj_description(p.oid, 'pg_proc') as description
	
	
		from pg_proc as p
		left join pg_catalog.pg_namespace as ns on ns.oid = p.pronamespace
		left join pg_catalog.pg_user as u on p.proowner = u.usesysid
		where u.usename <> 'postgres'
		group by owner, p.proname, input_parameters, p.pronargs, routine_type, retset, description
	)

	select * from pg_proc_data;
end;
$$ language plpgsql;

create or replace procedure p4_task_01() as $$
declare 
	table_sample record;
begin
	for table_sample in (
		select tablename from pg_catalog.pg_tables
		where 
			tableowner <> 'postgres' and 
			tablename ~* '^TableName')
		loop
			execute format('drop table %s cascade', table_sample.tablename);
			raise info 'table % was droped', table_sample.tablename;
	end loop;
end;
$$ language plpgsql;

create or replace procedure p4_task_02(out number_of_functions_with_parameters int) as $$
declare 
	function_sample record;
begin
	number_of_functions_with_parameters = 0;
	for function_sample in (
		select proname, input_parameters from pg_proc_data() 
		where 
			routine_type = 'f' and retset = 'scalar' and pronargs <> 0)
		loop
			raise info '%(%)', function_sample.proname, function_sample.input_parameters;
		number_of_functions_with_parameters = number_of_functions_with_parameters + 1; 
	end loop;
end;
$$ language plpgsql;

create or replace procedure p4_task_03(out number_of_triggers int) as $$
declare 
	tr_record record;
begin
	number_of_triggers = 0;
	for tr_record in (select distinct * from user_triggers()) 
	loop
		execute format('drop trigger %s on %s cascade', tr_record.trigger_name, tr_record.event_object_table);
		raise info '% was droped', tr_record.trigger_name;
		number_of_triggers = number_of_triggers + 1;
	end loop;
end;
$$ language plpgsql;

create or replace procedure p4_task_04(in string text) as $$
declare 
	routine_sample record;
begin
	for routine_sample in (
		select proname, description from pg_proc_data() 
		where 
			(routine_type = 'f' and retset = 'scalar' or routine_type = 'p') and description ~* string)
		loop
			raise info '%: %', routine_sample.proname, routine_sample.description;
	end loop;
end;
$$ language plpgsql;
--call p4_task_04('comment');

\c info_21;

