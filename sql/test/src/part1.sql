set client_min_messages = 'ERROR'; --use -q to quite notifications

do $$ 
begin
	create type state_io as enum('1', '2');
	create type state as enum('Start', 'Success', 'Failure');
exception
	when duplicate_object then null;
end $$;

drop table if exists peers cascade;
create table peers (
	nickname varchar primary key not null unique,
	birthday date
);

drop table if exists tasks cascade;
create table tasks (
	title varchar primary key not null unique,
	parent_task varchar,
	max_xp int not null
);
alter table tasks 
add constraint fk_pt foreign key(parent_task) references tasks(title),
add constraint tsk_not_repeated check(title != parent_task);

drop table if exists checks cascade;
create table checks (
	id serial primary key,
	peer varchar not null,
	task varchar not null,
	date date not null
);
alter table checks 
add constraint fk_checks_peer foreign key(peer) references peers(nickname),
add constraint fk_checks_task foreign key(task) references tasks(title);

drop table if exists p2p;
create table p2p (
	id serial primary key,
	_check bigint not null,
	checking_peer varchar not null,
	state state not null,
	time time(0) not null
);
alter table p2p
add	constraint fk_checking_peer foreign key(checking_peer) references peers(nickname),
add	constraint fk_check foreign key(_check) references checks(id),
add	constraint uc_p2p_check_id_time unique(_check, time);

drop table if exists verter;
create table verter (
	id serial primary key,
	_check bigint not null,
	state state not null, 
	time time(0) not null
);
alter table verter 
add constraint fk_verter_peer foreign key(_check) references checks(id),
add	constraint uc_verter_check_id_time unique(_check, time);

drop table if exists xp;
create table xp (
	id serial primary key,
	_check bigint not null,
	xp_amount int
);
alter table xp add constraint fk_verter_peer foreign key(_check) references checks(id);

drop table if exists transferred_points;
create table transferred_points (
	id serial primary key,
	checking_peer varchar not null,
	checked_peer varchar not null,
	points_amount int not null
);
alter table transferred_points 
add constraint fk_tp_checking foreign key(checking_peer) references peers(nickname),
add constraint fk_tp_checked foreign key(checked_peer) references peers(nickname),
add constraint tp_not_repeated check(checking_peer != checked_peer),
add constraint uc_peers_couple unique(checking_peer, checked_peer);


drop table if exists friends;
create table friends (
	id serial primary key,
	peer1 varchar not null,
	peer2 varchar not null
);
alter table friends 
add constraint fk_f_peer1 foreign key(peer1) references peers(nickname),
add constraint fk_f_peer2 foreign key(peer2) references peers(nickname),
add constraint fr_not_repeated check(peer1 != peer2),
add constraint uc_friends unique(peer1, peer2);

drop table if exists recommendations;
create table recommendations (
	id serial primary key,
	peer varchar not null,
	recommended_peer varchar not null
);
alter table recommendations 
add constraint fk_r_peer foreign key(peer) references peers(nickname),
add constraint fk_r_rec_peer foreign key(recommended_peer) references peers(nickname),
add constraint rec_not_repeated check(peer != recommended_peer);

drop table if exists time_tracking;
create table time_tracking (
	id serial primary key,
	peer varchar not null,
	_date date not null,
	_time time not null,
	state state_io not null
);
alter table time_tracking add constraint fk_tt_peer foreign key(peer) references peers(nickname);

create or replace procedure import_csv(
	_table varchar,
	del varchar(1) default ',',
	header boolean default True
) as $$
declare
	_path varchar;
	new_seq bigint;
begin
	select '/Users/khin/local/school21_platform/sql/info_21/src/' into _path;
	if header = True then
		execute format('copy %s from ''%sdata/import/%s.csv'' delimiter ''%s'' csv header', _table, _path, _table, del);
		if _table not in ('peers', 'tasks') then
			execute format('select max(id) + 1 from %s', _table) into new_seq;
			execute format('alter sequence %s_id_seq restart with %s', _table, new_seq);
		end if;
	end if;
	if header = False then
		execute format('copy %s from ''%sdata/import/%s.csv'' delimiter ''%s'' csv', _table, _path, _table, del);
	end if;
end
$$ language plpgsql;

create or replace procedure export_csv(
	_table varchar,
	del varchar(1) default ',',
	header boolean default True
) as $$
declare
	_path varchar;
begin
	select '/Users/khin/local/school21_platform/sql/info_21/src/' into _path;
	if header = True then
		execute format('copy %s to ''%sdata/export/%s.csv'' delimiter ''%s'' csv header', _table, _path, _table, del);
	end if;
	if header = False then
		execute format('copy %s to ''%sdata/export/%s.csv'' delimiter ''%s'' csv', _table, _path, _table, del);
	end if;
end
$$ language plpgsql;
