\c postgres;

drop database if exists retail_21;
create database retail_21;

\c retail_21;
\i part1.sql;

create or replace procedure retail_21_import() as $$
declare 
	name_list varchar[] = array[
			['personal_info', 'Personal_Data.tsv'], 
			['cards', 'Cards.tsv'],
			['transactions', 'Transactions.tsv'],
			['sku_group', 'Groups_SKU.tsv'], 
			['product_grid', 'SKU.tsv'], 
			['checks', 'Checks.tsv'], 
			['stores', 'Stores.tsv'],
			['date_of_analysis', 'Date_Of_Analysis_Formation.tsv']];

	match varchar[];
begin
	foreach match slice 1 IN array name_list 
	loop
		execute format('call import(%L, %L, ''\t'', False)', match[1], match[2]);
	end loop;
end;
$$ language plpgsql;

call retail_21_import();

create or replace procedure retail_21_export() as $$
declare 
	name_list varchar[] = array[
			['personal_info', 'Personal_Data.tsv'], 
			['cards', 'Cards.tsv'],
			['transactions', 'Transactions.tsv'],
			['sku_group', 'Groups_SKU.tsv'], 
			['product_grid', 'SKU.tsv'], 
			['checks', 'Checks.tsv'], 
			['stores', 'Stores.tsv'],
			['date_of_analysis', 'Date_Of_Analysis_Formation.tsv']];

	match varchar[];
begin
	foreach match slice 1 IN array name_list 
	loop
		execute format('call export(%L, %L, '','', False)', match[1], match[2]);
	end loop;
end;
$$ language plpgsql;

call retail_21_export();

\i part2.sql;
\i part3.sql;
\i part5.sql;
