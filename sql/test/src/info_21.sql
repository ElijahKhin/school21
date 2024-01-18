create or replace procedure info_21_import() as $$
declare 
	table_names varchar[] = array['peers', 'tasks', 'checks', 'p2p', 'verter', 'friends', 'xp', 'recommendations', 'time_tracking'];
	table_name varchar;
begin
	foreach table_name in array table_names loop
		call import_csv(table_name, ',');
	end loop;
end;
$$ language plpgsql;

create or replace procedure info_21_export() as $$
declare 
	table_names varchar[] = array['peers', 'tasks', 'checks', 'p2p', 'verter', 'friends', 'xp', 'recommendations', 'time_tracking'];
	table_name varchar;
begin
	foreach table_name in array table_names loop
		call export_csv(table_name, '	');
	end loop;
end;
$$ language plpgsql;

-- //////////////Building a Project/////////////////// --

\i part1.sql;
\i part2.sql;

call info_21_import();
call info_21_export();

\i part3.sql;
\i part4.sql;
