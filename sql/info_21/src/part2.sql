create or replace function tasks_updating() returns trigger as $$
begin
	if exists (select * from tasks) then
		if new.parent_task is null then
			raise exception 'Error [tasks]: there should be ONLY one task without a parent task. Add parent task for %', new.title;
		end if;
	end if;
	if not exists (select * from tasks) then
		if new.parent_task is not null then
			raise exception 'Error [tasks]: there should be one task without a parent task';
		end if;
	end if;
	return new;
end;
$$ language plpgsql;

create or replace trigger tr_tasks_updating
before insert or update on tasks
for each row
	execute function tasks_updating();

create or replace function friends_updating() returns trigger as $$
begin
	if exists(select * from friends where friends.peer1 = new.peer2 and friends.peer2 = new.peer1) then
		raise exception 'Error: duplicated values!';
	end if;
	return new;
end;
$$ language plpgsql;

create or replace trigger tr_friends
before insert or update on friends
for each row
	execute function friends_updating();

create or replace function recommendations_updating() returns trigger as $$
begin
	if not exists(
		select * from p2p 
		left join checks on checks.id = p2p._check
		where 
		p2p.checking_peer = new.recommended_peer and 
		checks.peer = new.peer and 
		p2p.state in ('Failure', 'Success')) then

		raise exception 'Error: % hasn''t checked %!', new.recommended_peer, new.peer;

	end if;
	return new;
end;
$$ language plpgsql;

create or replace trigger tr_recommendations
before insert or update on recommendations
for each row
	execute function recommendations_updating();

create or replace function time_tracking_updating() returns trigger as $$
declare
	max_date date = (
		select max(_date) from time_tracking
		where time_tracking.peer = new.peer
		);

	ins int = (
		select count(*) from time_tracking 
		where 
			time_tracking.peer = new.peer and 
			time_tracking._date = max_date and
			time_tracking.state = '1'
		);

	outs int = (
		select count(*) from time_tracking 
		where 
			time_tracking.peer = new.peer and 
			time_tracking._date = max_date and
			time_tracking.state = '2'
		);

	max_time time = (
		select _time from time_tracking 
		where 
			time_tracking.peer = new.peer and 
			time_tracking._date = new._date and
			time_tracking._time = (select max(_time) from time_tracking where time_tracking.peer = new.peer and time_tracking._date = new._date)
		);

	last_state state_io = (
		select state from time_tracking 
		where 
			time_tracking.peer = new.peer and 
			time_tracking._date = new._date and
			time_tracking._time = max_time
		);

begin
	if max_date > new._date then
		raise exception 'Error [time_tracking]: wrong date';
	end if;
	if exists(select * from time_tracking where time_tracking.peer = new.peer) then
		if exists(select * from time_tracking where time_tracking.peer = new.peer and time_tracking._date = new._date) then
			if last_state != new.state and max_time < new._time then
				return new;
			end if;
			raise exception 'Error [time_tracking]: wrong state or time';
		end if;
		if ins = outs and new.state = '1' then
			return new;
		end if;
		raise exception 'Error [time_tracking]: wrong ins / outs or state';
	end if;
	if new.state = '1' then
		return new;
	end if;
	raise exception 'Error [time_tracking]: if peer''s never been in school state can''t be ''2''';
end;
$$ language plpgsql;

create or replace trigger tr_tt
before insert or update on time_tracking
for each row
	execute function time_tracking_updating();

create or replace function xp_updating() returns trigger as $$
declare
	max_xp int = (select max_xp from tasks where tasks.title = (select task from checks where checks.id = new._check));
	p2p_status state = (select state from p2p where p2p._check = new._check and state = 'Success');
	verter_start state = (select state from verter where verter._check = new._check and state = 'Start');
	verter_success state = (select state from verter where verter._check = new._check and state = 'Success');
begin
	if 
		max_xp >= new.xp_amount and p2p_status = 'Success' and
		(verter_start is null or verter_success = 'Success') then
		return new;
	end if;
	raise exception 'Error: something went wrong!';
end;
$$ language plpgsql;

create or replace trigger tr_xp
before insert or update on xp
for each row
	execute function xp_updating();

create or replace function tp_updating() returns trigger as $$
declare 
	_checking_peer_ varchar = new.checking_peer;
	_checked_peer_ varchar = (select peer from checks where checks.id = new._check);
	current_points_amount int = (select points_amount from transferred_points where checking_peer = _checking_peer_ and checked_peer = _checked_peer_);

begin
	if new.state = 'Start' then
		if current_points_amount is null then
			insert into transferred_points(checking_peer, checked_peer, points_amount) values(_checking_peer_, _checked_peer_, 1);
		end if;
		if current_points_amount is not null then
			update transferred_points set points_amount = current_points_amount + 1 where checking_peer = _checking_peer_ and checked_peer = _checked_peer_;
		end if;
	end if;
	return new;
end;
$$ language plpgsql;

create or replace trigger tr_tp
after insert or update on p2p
for each row
	execute function tp_updating();

create or replace function p2p_updating() returns trigger as $$
declare 
	_checking_peer_ varchar = new.checking_peer;
	_checked_peer_ varchar = (select peer from checks where checks.id = new._check);
	_task_ varchar = (select task from checks where checks.id = new._check);
	_timestamp_ timestamp;

begin
	if _checked_peer_ = _checking_peer_ then
		raise exception 'Error[p2p]: Checked peer and checking peer can''t be the same';
	end if;
	if new.state = 'Start' then
		if (select count(*) from p2p where p2p._check = new._check and p2p.state = 'Start') = 1 then
			raise exception 'Error [p2p]: P2P checking with id % has already started', new._check;
		end if;

		if exists (select * from checks where checks.id = new._check) then
			select into _timestamp_ date + new.time from checks where checks.id = new._check;
		end if;
		if not exists (select * from checks where checks.id = new._check) then
			select into _timestamp_ now()::date + new.time;
		end if;

		if (select count(*) from p2p 
			left join checks on checks.id = p2p._check
			where 
				_timestamp_::date = checks.date and
				_timestamp_::time > p2p.time and
				p2p.checking_peer = _checking_peer_ and
				checks.peer = _checked_peer_ and
				checks.task = _task_) % 2 = 1 then
				raise exception 'Error [p2p]: P2P checking is currently running with the same parameters';
		end if;


		if (select max(checks.date + p2p.time) from p2p left join checks on checks.id = p2p._check where state = 'Start') >= _timestamp_ then
			raise exception 'Error [p2p]: All p2p checks are time-bound. It means that each next check must be later than the previous one';
		end if;
		return new;
	end if;
	if (select count(*) from p2p where p2p._check = new._check) != 1 then
		raise exception 'Error [p2p]: P2P checking has already ended with state %', (select state from p2p where p2p._check = new._check and p2p.state != 'Start');
	end if;
	if (select time from p2p where p2p._check = new._check) >= new.time then
		raise exception 'Error [p2p]: The time of receiving the final status cannot be earlier than the start of the task checking. Each stage of p2p ends in one day!';
	end if;
	return new;
end;
$$ language plpgsql;

create or replace trigger tr_p2p
before insert or update on p2p
for each row
	execute function p2p_updating();
	

create or replace function verter_updating() returns trigger as $$
begin
	if new.state = 'Start' then
		if (select count(*) from p2p where p2p._check = new._check and p2p.state = 'Success') != 1 then
				raise exception 'p2p checked isn''t started or was failed';
		end if;
		if (select count(*) from verter where verter._check = new._check and verter.state = 'Start') = 1 then
			raise exception 'In these case state can''t be ''Start''';
		end if;
		if (select time from verter where verter._check = new._check and verter.state = 'Success') >= new.time then
			raise exception 'verter check can''t be earlier than p2p finished';
		end if;
		return new;
	end if;
	if (select count(*) from verter where verter._check = new._check) != 1 then
		raise exception 'Fuck off bleyat!';
	end if;
	if (select time from verter where verter._check = new._check) >= new.time then
		raise exception 'Time of final status can''t be earlier OR AT THE SAME TIME!!! than start of task checking. Each verter stage ends in one day!';
	end if;
	return new;
end;
$$ language plpgsql;

create or replace trigger tr_verter
before insert or update on verter
for each row
	execute function verter_updating();

create or replace function unfinished_checks(
	_checking_peer_ varchar, 
	_checked_peer_ varchar, 
	_task_ varchar,
	_time time(0), 
	_date date) returns boolean as $$
begin
	if (select count(*) from p2p 
		left join checks on checks.id = p2p._check
		where 
			_date = checks.date and 
			_time > p2p.time and 
			p2p.checking_peer = _checking_peer_ and
			checks.peer = _checked_peer_ and
			checks.task = _task_) % 2 = 1 then
			return false;
	end if;
	return true;
end;
$$ language plpgsql;

create or replace procedure insert_p2p(
	_checked_peer_ varchar,
	_checking_peer_ varchar,
	_task_ varchar,
	_state_ state,
	_time time(0)
	) as $$

declare 
	last_check_id bigint;
	_date date = now()::date;

begin
	if _state_ = 'Start' then
		if unfinished_checks(_checking_peer_, _checked_peer_, _task_, _time, _date) = true then
			insert into checks(peer, task, date) values(_checked_peer_, _task_, _date);
			select into last_check_id max(id) from checks where peer = _checked_peer_ and task = _task_ and date = _date;
		end if;
	end if;
	select into last_check_id checks.id from checks left join p2p on checks.id = p2p._check where peer = _checked_peer_ and task = _task_ and date = _date and checking_peer = _checking_peer_;
	insert into p2p(_check, checking_peer, state, time) values(last_check_id, _checking_peer_, _state_, _time);
end;
$$ language plpgsql;

create or replace procedure insert_verter(
	_checked_peer_ varchar,
	_task_ varchar,
	_state_ state,
	_time time(0)) as $$

declare 
	success_id_p2p bigint;

begin
	select into success_id_p2p sample_id
	from (
		select checks.id as sample_id, peer, checks.date + p2p.time as timestamp 
		from p2p 
		left join checks on checks.id = p2p._check 
		where 
		task = _task_ and 
		state = 'Success' and 
		peer = _checked_peer_
		order by timestamp desc) 
	as tmp limit 1;
	if success_id_p2p is not null then
		insert into verter(_check, state, time) values(success_id_p2p, _state_, _time);
	end if;
end;
$$ language plpgsql;
