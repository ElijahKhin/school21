set client_min_messages = 'ERROR'; --use -q to quite notifications
set datestyle to 'European';

drop table if exists personal_info cascade;
create table personal_info (
	customer_id serial primary key,
	customer_name varchar not null,
	customer_surname varchar not null,
	customer_primary_email varchar not null,
	customer_primary_phone varchar not null
);

drop table if exists cards cascade;
create table cards (
	customer_card_id serial primary key,
	customer_id bigint not null
);
alter table cards add constraint fk_cards_to_customer_id foreign key(customer_id) references personal_info(customer_id);

drop table if exists transactions cascade;
create table transactions (
	transaction_id serial primary key,
	customer_card_id bigint not null,
	transaction_summ numeric(11, 4) not null,
	transaction_datetime timestamp(0) not null,
	transaction_store_id bigint not null
);
alter table transactions 
add constraint fk_transactions_to_card_id foreign key(customer_card_id) references cards(customer_card_id);
--add constraint fk_transactions_to_stores foreign key(transaction_store_id) references stores(transaction_store_id);

drop table if exists sku_group cascade;
create table sku_group (
	group_id serial primary key,
	group_name varchar not null
);

drop table if exists product_grid cascade;
create table product_grid (
	sku_id serial primary key,
	sku_name varchar not null,
	group_id bigint not null
);
alter table product_grid
add constraint fk_product_grid_to_group_id foreign key(group_id) references sku_group(group_id);

drop table if exists checks cascade;
create table checks (
	transaction_id bigint not null,
	sku_id bigint not null,
	sku_amount numeric(6, 2) not null,
	sku_summ numeric(11, 4) not null,
	sku_summ_paid numeric(11, 4) not null,
	sku_discount numeric(11, 4) not null
);
alter table checks 
add constraint fk_checks_to_transaction_id foreign key(transaction_id) references transactions(transaction_id),
add constraint fk_checks_to_sku_id foreign key(sku_id) references product_grid(sku_id);

drop table if exists stores cascade;
create table stores (
	transaction_store_id bigint not null,
	sku_id bigint not null,
	sku_purchase_price numeric(11, 4) not null,
	sku_retail_price numeric(11, 4) not null
);
alter table stores
add constraint fk_stores_to_sku_id foreign key(sku_id) references product_grid(sku_id);

drop table if exists date_of_analysis cascade;
create table date_of_analysis (
	analysis_formation timestamp(0) not null
);


-- Import & Export -- 

create or replace procedure import(
	_table text,
	file_name text,
	del varchar(1) default ',',
	header boolean default True
) as $$
declare
	_path varchar;
	new_seq bigint;
begin
	select '/Users/khin/local/school21_platform/sql/retail_21/datasets/' into _path;
	if header = True then
		execute format('copy %s from ''%s%s'' delimiter E''%s'' csv header', _table, _path, file_name, del);
	else
		execute format('copy %s from ''%s%s'' delimiter E''%s'' csv', _table, _path, file_name, del);
	end if;
--	execute format('select max(id) + 1 from %I', _table) into new_seq;
--	execute format('alter sequence %I_id_seq restart with %I', _table, new_seq);

end
$$ language plpgsql;

create or replace procedure export(
	_table text,
	file_name text,
	del varchar(1) default ',',
	header boolean default True
) as $$
declare
	_path varchar;
begin
	select '/Users/khin/local/school21_platform/sql/retail_21/src/export/' into _path;
	if header = True then
		execute format('copy %s to ''%s%s'' delimiter E''%s'' csv header', _table, _path, file_name, del);
	else
		execute format('copy %s to ''%s%s'' delimiter E''%s'' csv', _table, _path, file_name, del);
	end if;
end
$$ language plpgsql;


-- Regular Expressions Constraints -- 

-- # Personal Info
alter table personal_info
add constraint regex_customer_name check(customer_name ~ '(^([А-ЯЁ]{1}[а-яё\- ]{1,}|[A-Z]{1}[a-z\- ]{1,})$)'),
add constraint regex_customer_surname check(customer_surname ~ '(^([А-ЯЁ]{1}[а-яё\- ]{1,}|[A-Z]{1}[a-z\- ]{1,})$)'),
add constraint regex_customer_full_name_same_lang check(
	customer_name ~ '(^([А-ЯЁ]{1}[а-яё\- ]{1,})$)' and customer_surname ~ '(^([А-ЯЁ]{1}[а-яё\- ]{1,})$)' or
	customer_name ~ '(^([A-Z]{1}[a-z\- ]{1,})$)' and customer_surname ~ '(^([A-Z]{1}[a-z\- ]{1,})$)'),
add constraint regex_customer_email check(customer_primary_email ~ '(^[\w\.]+@([\w]+\.)+[\w]{2,4}$)'),
add constraint regex_customer_phone check(customer_primary_phone ~ '(^\+{1}7{1}[0-9]{10}$)');

-- # SKU 
alter table product_grid
add constraint regex_sku_name check(sku_name ~ '^[A-Za-zА-ЯЁа-яё0-9_@!#%&()+-=*\s\[\]{};:''"\\|,.<>?/`~^$]*$');

-- # Groups Of SKU's
alter table sku_group
add constraint sku_group check(group_name ~ '^[A-Za-zА-ЯЁа-яё0-9_@!#%&()+-=*\s\[\]{};:''"\\|,.<>?/`~^$]*$');


-- Useless Comments On Columns -- 

comment on column cards.customer_id is 'One customer can own several cards';
comment on column transactions.transaction_id is 'Unique value';
comment on column transactions.transaction_summ is 'Transaction sum in rubles(full purchase price excluding discounts)';
comment on column transactions.transaction_datetime is 'Date and time when the transaction was made';
comment on column transactions.transaction_store_id is 'The store where the transaction was made';
comment on column product_grid.group_id is 'The ID of the group of related products to which the product belongs (for example, same type of yogurt of the same manufacturer and volume, but different flavors). One identifier is specified for all products in the group';
comment on column checks.transaction_id is 'Transaction ID is specified for all products in the check';
comment on column checks.sku_amount is 'The quantity of the purchased product';
comment on column checks.sku_summ is 'The purchase amount of the actual volume of this product in rubles (full price without discounts and bonuses)';
comment on column checks.sku_summ_paid is 'The amount actually paid for the product not including the discount';
comment on column checks.sku_discount is 'The size of the discount granted for the product in rubles';
comment on column stores.sku_purchase_price is 'Purchasing price of products for this store';
comment on column stores.sku_retail_price is 'The sale price of the product excluding discounts for this store';
