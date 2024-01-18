--drop database if exists retail_21;
--create database retail_21;
--\c retail_21
\i part1.sql
call import('personal_info', 'tsv', '\t', False);
call import('cards', 'tsv', '\t', False);
call import('transactions', 'tsv', '\t', False);
call import('product_grid', 'tsv', '\t', False);
call import('checks', 'tsv', '\t', False);
call import('stores', 'tsv', '\t', False);
call import('sku_group', 'tsv', '\t', False);
--insert into 
--	personal_info(
--		customer_name, 
--		customer_surname, 
--		customer_primary_email, 
--		customer_primary_phone) 
--	values
--		('Ivan', 'Chernykh', 'workbiscap@gmail.com', '+79294355991'),
--		('Ёван ', 'Черных', 'workbiscap@gmail.com', '+79294355991');

