drop function p3_task_1;
CREATE OR REPLACE FUNCTION p3_task_1()
RETURNS TABLE (Peer1 text, Peer2 text, PointsAmount bigint) AS $$
BEGIN
    RETURN QUERY
    SELECT
        tp1.checking_peer::text AS Peer1,
        tp1.checked_peer::text AS Peer2,
        CASE
            WHEN tp1.points_amount > tp2.points_amount THEN (tp1.points_amount - tp2.points_amount)::bigint
            ELSE (-(tp2.points_amount - tp1.points_amount))::bigint
        END AS PointsAmount
    FROM
        transferred_points tp1
    JOIN
        transferred_points tp2
    ON
        tp1.checking_peer = tp2.checked_peer
    AND
        tp1.checked_peer = tp2.checking_peer;
END;
$$ LANGUAGE plpgsql;
--select * from p3_task_1();

drop function p3_task_2;
CREATE OR REPLACE FUNCTION p3_task_2()
RETURNS TABLE(Peer text, Task text, XP integer) AS $$
BEGIN
    RETURN QUERY
    SELECT 
        c.peer::text,
        c.task::text,
        xp.xp_amount::integer
    FROM 
        checks c
    JOIN
        xp ON c.id = xp._check;
END;
$$ LANGUAGE plpgsql;
--SELECT * FROM p3_task_2();


drop function p3_task_3;
create or replace function p3_task_3(day date)
returns table (Peer character varying) as $$
declare 
    last_state integer;
begin
    return QUERY
    select distinct tt.peer as Peer
    from time_tracking tt
    where tt._date = day
    and tt.state::text = '1'
    and not exists (
        select 1
        from time_tracking tt2
        where tt2._date = day
        and tt2.peer = tt.peer
        and tt2._time > tt._time 
        and tt2.state::text = '2'
    );
end;
$$ language plpgsql;
--select * from p3_task_3('2022-01-24');

drop function calculate_points_change;
CREATE OR REPLACE FUNCTION calculate_points_change()
RETURNS TABLE (
    Peer text,
    PointsChange bigint
) AS $$
BEGIN
    CREATE TEMPORARY TABLE IF NOT EXISTS temp_result (
        Peer text,
        PointsChange bigint
    );
    DELETE FROM temp_result;
    INSERT INTO temp_result (Peer, PointsChange)
    SELECT
        tp.checking_peer AS Peer,
        SUM(tp.points_amount) AS PointsChange
    FROM transferred_points tp
    GROUP BY tp.checking_peer
    ORDER BY PointsChange DESC;
    
    RETURN QUERY SELECT * FROM temp_result;
END;
$$ LANGUAGE plpgsql;

DROP PROCEDURE IF EXISTS p3_task_4;
CREATE OR REPLACE PROCEDURE p3_task_4(
	ref refcursor default 'ref') as $$
begin
	open ref for
	select * from calculate_points_change();
end;
$$ LANGUAGE plpgsql;


DROP FUNCTION IF EXISTS calculate_points_change_2;
CREATE OR REPLACE FUNCTION calculate_points_change_2()
RETURNS TABLE (
    Peer text,
    PointsChange bigint
) AS $$
BEGIN
    RETURN QUERY
    SELECT
        tp.Peer1 AS Peer,
        SUM(tp.PointsAmount::bigint) AS PointsChange
    FROM p3_task_1() tp
    GROUP BY tp.Peer1
    ORDER BY PointsChange DESC;
END;
$$ LANGUAGE plpgsql;

DROP PROCEDURE IF EXISTS p3_task_5;

CREATE OR REPLACE PROCEDURE p3_task_5(
    ref refcursor DEFAULT 'ref'
) AS $$
BEGIN
    OPEN ref FOR
    SELECT
        tp.Peer1 AS Peer,
        SUM(tp.PointsAmount::bigint) AS PointsChange
    FROM p3_task_1() tp
    GROUP BY tp.Peer1
    ORDER BY PointsChange DESC;
END;
$$ LANGUAGE plpgsql;


--BEGIN;
--CALL p3_task_5();
--FETCH ALL FROM ref;
--CLOSE ref;
--END;




CREATE OR REPLACE FUNCTION get_max_count_tasks() RETURNS TABLE (day DATE,task varchar) AS $$
BEGIN
    return QUERY
    SELECT c.date, c.task
    FROM (
        SELECT c.date, c.task, DENSE_RANK() OVER (PARTITION BY c.date ORDER BY COUNT(*) DESC) AS rn
        FROM checks as c
        GROUP BY c.date, c.task
    ) AS ranked
    join checks as c on ranked.date = c.date and ranked.task = c.task
    WHERE ranked.rn = 1;
END;
$$ LANGUAGE plpgsql;



drop procedure if exists p3_task_6 cascade;
create or replace procedure p3_task_6 (
	ref refcursor default 'ref') as $$
begin
	open ref for
	select * from get_max_count_tasks();
end;
$$ LANGUAGE plpgsql;

DROP FUNCTION IF EXISTS get_peers_completed_block(varchar);
CREATE OR REPLACE FUNCTION get_last_completed_task(block_name varchar)
RETURNS TABLE (
    peer varchar,
    day date
) AS $$
BEGIN
    RETURN QUERY
    WITH LastTask AS (
        SELECT
            c.peer,
            c.date,
            c.task,
            MAX(c.date) OVER (PARTITION BY c.peer, c.task) AS max_date
        FROM
            checks c
        JOIN
            tasks t ON c.task = t.title
        WHERE
            t.title LIKE block_name || '%'
    ),
    LastCompletedTask AS (
        SELECT
            lt.peer,
            lt.date AS last_task_date,
            MAX(c.date) AS max_date
        FROM
            LastTask lt
        JOIN
            checks c ON lt.peer = c.peer AND lt.task = c.task
        WHERE
            c.date <= lt.max_date
        GROUP BY
            lt.peer, lt.date
    )
    SELECT
        lc.peer,
        lc.last_task_date
    FROM
        LastCompletedTask lc
    WHERE
        lc.max_date = lc.last_task_date
    ORDER BY
        lc.last_task_date;
END;
$$ LANGUAGE plpgsql;



drop procedure if exists p3_task_7 cascade;
CREATE OR REPLACE PROCEDURE p3_task_7(
    block_name varchar,
    ref refcursor DEFAULT 'ref'
) AS $$
BEGIN
    OPEN ref FOR
    SELECT * FROM get_last_completed_task(block_name);
END;
$$ LANGUAGE plpgsql;




--BEGIN;
--   call p3_task_6();
--   FETCH ALL IN "ref";
--   CLOSE ref;
--END;

-- BEGIN;
-- CALL p3_task_7('CPP');
-- FETCH ALL FROM "ref";
-- CLOSE ref;
-- END;

DROP PROCEDURE IF EXISTS p3_task_8 CASCADE;
CREATE OR REPLACE PROCEDURE p3_task_8() AS $$

BEGIN
    IF EXISTS (SELECT 1 FROM information_schema.tables WHERE table_name = 'temp_recommendations_task_8') THEN
        EXECUTE 'DROP TABLE temp_recommendations_task_8';
    END IF;
    CREATE TABLE temp_recommendations_task_8 AS

    SELECT peers.nickname AS peer, 
    COALESCE(counted_rs.recommended_peer, 'No recommendation') AS recommended_peer
    FROM peers
        LEFT JOIN
        (
            SELECT grouped_rs.peer, grouped_rs.recommended_peer,   
                COUNT(grouped_rs.peer) AS recommendated_count
            FROM (
                SELECT rs.* FROM
                (
                    SELECT friends.peer2 as peer, friends.peer1 as friend_peer, recommendations.recommended_peer 
                    FROM recommendations 
                    JOIN friends ON friends.peer1 = recommendations.peer
                    WHERE friends.peer2 != recommendations.recommended_peer

                    UNION

                    SELECT friends.peer1 as peer, friends.peer2 as friend_peer, recommendations.recommended_peer 
                    FROM recommendations 
                    JOIN friends ON friends.peer2 = recommendations.peer 
                    WHERE friends.peer1 != recommendations.recommended_peer
                )
                AS rs

                GROUP BY rs.peer, rs.friend_peer, rs.recommended_peer
                ORDER BY rs.peer

            ) as grouped_rs

            GROUP BY grouped_rs.peer, grouped_rs.recommended_peer
            ORDER BY recommendated_count DESC, grouped_rs.peer ASC    
                
        ) 
        AS counted_rs
        ON counted_rs.peer = peers.nickname
        ORDER BY peers.nickname ASC;
        
END;
$$ LANGUAGE plpgsql;


--CALL p3_task_8();
--SELECT * FROM temp_recommendations_task_8;


---EX-09---

DROP PROCEDURE IF EXISTS p3_task_9 CASCADE;
CREATE OR REPLACE PROCEDURE p3_task_9(Block1 VARCHAR, Block2 VARCHAR) AS $$
DECLARE
    StartedBlock1 INT;
    StartedBlock2 INT;
    StartedBothBlocks INT;
    DidntStartAnyBlock INT;

BEGIN
    IF EXISTS (SELECT 1 FROM pg_tables WHERE tablename = 'temp_res_task_9') THEN
        EXECUTE 'DROP TABLE temp_res_task_9';
    END IF;

    WITH block1_peers AS (
        SELECT DISTINCT "peer" FROM checks WHERE checks."task" ~ ('^' || Block1 || '[0-9]+_')
    ),

    block2_peers AS (
        SELECT DISTINCT "peer" FROM checks WHERE checks."task" ~ ('^' || Block2 || '[0-9]+_')
    ),

    block1_and_block2_peers AS (
        SELECT "peer" FROM block1_peers
        INTERSECT
        SELECT "peer" FROM block2_peers
    ),

    none_block1_and_block2_peers AS (
        SELECT "nickname" AS peer
        FROM peers p
        LEFT JOIN (
            SELECT DISTINCT "peer"
            FROM block1_peers
            UNION
            SELECT DISTINCT "peer"
            FROM block2_peers
        ) b ON p."nickname" = b."peer"
        WHERE b."peer" IS NULL
    ),

    sum_peers AS (
        SELECT COUNT("nickname") AS total_peers FROM peers

    )
    SELECT
        (SELECT (COUNT("peer")::NUMERIC / sum_peers.total_peers * 100)::INT FROM block1_peers) AS StartedBlock1,
        (SELECT (COUNT("peer")::NUMERIC / sum_peers.total_peers * 100)::INT FROM block2_peers) AS StartedBlock2,
        (SELECT (COUNT("peer")::NUMERIC / sum_peers.total_peers * 100)::INT FROM block1_and_block2_peers) AS StartedBothBlocks,
        (SELECT (COUNT(peer)::NUMERIC / sum_peers.total_peers * 100)::INT FROM none_block1_and_block2_peers) AS DidntStartAnyBlock
    INTO StartedBlock1, StartedBlock2, StartedBothBlocks, DidntStartAnyBlock
    FROM sum_peers;

    CREATE TEMP TABLE temp_res_task_9 AS
    SELECT StartedBlock1, StartedBlock2, StartedBothBlocks, DidntStartAnyBlock;
END;
$$ LANGUAGE plpgsql;


--CALL p3_task_9('SQL', 'A');
--SELECT * FROM temp_res_task_9;

drop procedure if exists p3_task_10 cascade;
create or replace procedure p3_task_10 (ref refcursor default 'ref') as $$
begin
	open ref for
	with
	peers_md as (
	select 
		*, 
		extract(month from birthday)::varchar as birth_month,
		extract(day from birthday)::varchar as birth_day
	from peers
	),
	
	verter_status as (
	select verter._check, state as verter_state
	from verter 
	join (
		select 
			_check,
			max(time) 
		from verter 
		group by _check
	) as tmp on 
	verter._check = tmp._check and 
	verter.time = tmp.max
	),
	
	p2p_status as (
	select p2p._check, state as p2p_state
	from p2p 
	join (
		select 
			_check,
			max(time) 
		from p2p 
		group by _check
	) as tmp on 
	p2p._check = tmp._check and 
	p2p.time = tmp.max
	),
	
	all_finished_checks as (
	select
		_check,
		peer,
		date, 
		extract(month from date)::varchar as check_month,
		extract(day from date)::varchar as check_day,
		p2p_state, 
		verter_state, 
		isFinished,
		case 
			when p2p_state = 'Failure' then 'not ok'  
			when p2p_state = 'Success' and verter_state = 'Failure' then 'not ok'  
			else 'ok'
		end as final_state 
	from (
		select p2p_status.*, verter_status.verter_state, checks.date, checks.peer,
			case
				when p2p_state = 'Start' or verter_state::text = 'Start' then 'not finished'
			else 'finished' 
			end as isFinished
		from p2p_status 
		left join verter_status using(_check)
		left join checks on checks.id = p2p_status._check
	) as tmp
	where isFinished = 'finished'
	),
	birthday_checks as (
		select * 
		from all_finished_checks 
		inner join peers_md on 
		all_finished_checks.peer = peers_md.nickname and 
		peers_md.birth_month = all_finished_checks.check_month and 
		peers_md.birth_day = all_finished_checks.check_day
	),
	birthday_success as (
		select * from birthday_checks where final_state = 'ok' 
	),
	ratio_success as (
		select 
			(select count(*) from birthday_success) / 
			(select count(*) from birthday_checks)::float as successful_checks
	),
	task10_answer as (
	select round((select * from ratio_success) * 100), round((1 - (select * from ratio_success)) * 100) as unsuccessful_checks
	)
	select * from task10_answer;
end;
$$ language plpgsql;

drop procedure if exists p3_task_11 cascade;
create or replace procedure p3_task_11 (
	ref refcursor default 'ref', 
	first_one varchar default 'C2_SimpleBashUtils',
	second_one varchar default 'C3_s21_string+',
	third_one varchar default 'CPP5_3DViewer_v2.1') as $$
begin
	open ref for
	with

	verter_status as (
	select verter._check, state as verter_state
	from verter 
	join (
		select 
			_check,
			max(time) 
		from verter 
		group by _check
	) as tmp on 
	verter._check = tmp._check and 
	verter.time = tmp.max
	),
	
	p2p_status as (
	select p2p._check, state as p2p_state
	from p2p 
	join (
		select 
			_check,
			max(time) 
		from p2p 
		group by _check
	) as tmp on 
	p2p._check = tmp._check and 
	p2p.time = tmp.max
	),
	
	all_finished_checks as (
	select
		_check,
		peer,
		task,
		date, 
		extract(month from date)::varchar as check_month,
		extract(day from date)::varchar as check_day,
		p2p_state, 
		verter_state, 
		isFinished,
		case 
			when p2p_state = 'Failure' then 'not ok'  
			when p2p_state = 'Success' and verter_state = 'Failure' then 'not ok'  
			else 'ok'
		end as final_state 
	from (
		select p2p_status.*, verter_status.verter_state, checks.date, checks.peer, checks.task,
			case
				when p2p_state = 'Start' or verter_state::text = 'Start' then 'not finished'
			else 'finished' 
			end as isFinished
		from p2p_status 
		left join verter_status using(_check)
		left join checks on checks.id = p2p_status._check
	) as tmp
	where isFinished = 'finished'
	),
	first_task as (
		select distinct peer from all_finished_checks 
		where 
			task = first_one and 
			final_state = 'ok' 
	),
	second_task as (
		select distinct peer from all_finished_checks 
		where 
			task = second_one and 
			final_state = 'ok' 
	),
	third_task as (
		select * from all_finished_checks 
		where 
			task = third_one and 
			final_state = 'ok' 
	)
	select peer as two_out_of_three 
	from (
		select * from first_task 
		inner join second_task using(peer)) as tmp 
	where tmp.peer not in (select peer from third_task);
end;
$$ language plpgsql;

create or replace function count_prev(init_task varchar) returns table(task varchar, prev_count bigint) as $$ 
begin
	return query
	with 
		recursive previous_tasks as (
			select * from tasks
			where tasks.title = init_task 
			union all
			select
				tasks.title,
				tasks.parent_task,
				tasks.max_xp
			from
				tasks, previous_tasks
			where
				tasks.title = previous_tasks.parent_task and
				tasks.parent_task is not null
		),
		answer_task_12 as (
			select init_task as task, count(parent_task) as prev_count from previous_tasks
		)
	select * from answer_task_12;
end;
$$ language plpgsql;

create or replace function task_12() returns table(task varchar, prev_count bigint) as $$
declare 
	init_title record;  
	sample record;
begin
	for init_title in (select title from tasks)
	loop
		select into sample * from count_prev(init_title.title);
		task = sample.task;
		prev_count = sample.prev_count;
		return next;
	end loop;
end;
$$ language plpgsql;

drop procedure if exists p3_task_12 cascade;
create or replace procedure p3_task_12 (
	ref refcursor default 'ref') as $$
begin
	open ref for
	select * from task_12();
end;
$$ language plpgsql;

create or replace function te() returns table(id_ bigint, task varchar, _date_ date, _time_ time,  _final_state_ text, xp_ratio float) as $$ 
begin
	return query
	with
		verter_status as (
		select verter._check, state as verter_state
		from verter 
		join (
			select 
				_check,
				max(time) 
			from verter 
			group by _check
		) as tmp on 
		verter._check = tmp._check and 
		verter.time = tmp.max
		),
		
		p2p_status as (
		select p2p._check, state as p2p_state
		from p2p 
		join (
			select 
				_check,
				max(time) 
			from p2p 
			group by _check
		) as tmp on 
		p2p._check = tmp._check and 
		p2p.time = tmp.max
		),
		
		all_finished_checks as (
		select
			_check,
			peer,
			tmp.task,
			date, 
			extract(month from date)::varchar as check_month,
			extract(day from date)::varchar as check_day,
			p2p_state, 
			verter_state, 
			isFinished,
			case 
				when p2p_state = 'Failure' then 'not ok'  
				when p2p_state = 'Success' and verter_state = 'Failure' then 'not ok'  
				else 'ok'
			end as final_state 
		from (
			select p2p_status.*, verter_status.verter_state, checks.date, checks.peer, checks.task,
				case
					when p2p_state = 'Start' or verter_state::text = 'Start' then 'not finished'
				else 'finished' 
				end as isFinished
			from p2p_status 
			left join verter_status using(_check)
			left join checks on checks.id = p2p_status._check
		) as tmp
		where isFinished = 'finished'
		),
		p2p_start as (
			select _check, time from p2p 
			where state = 'Start'
		),
		all_finished_with_time_start as (
			select all_finished_checks._check, all_finished_checks.task, date, time, final_state, (xp.xp_amount / tasks.max_xp)::float as xp_ratio from all_finished_checks 
			left join p2p_start using(_check)
			left join xp on xp._check = all_finished_checks._check
			left join tasks on all_finished_checks.task = tasks.title
		)
	select * from all_finished_with_time_start;
end;
$$ language plpgsql;

create or replace function task_13() returns table(date_set date) as $$
declare
	iter int;
	day record;
	result record;

begin

	for day in (select distinct _date_ from te()) 
	loop
		iter = 0;
		for result in (
			select _final_state_, xp_ratio from te()
			where _date_ = day._date_
			order by _time_)
		loop
			if result._final_state_ = 'ok' and result.xp_ratio >= 0.8 then
				iter = iter + 1;
			else
				iter = 0;
			end if;
			exit when iter = 3;
		end loop;
		if iter = 3 then 
			date_set = day._date_;
			return next;
		end if;
	end loop;
end;
$$ language plpgsql;

drop procedure if exists p3_task_13 cascade;
create or replace procedure p3_task_13 (
	ref refcursor default 'ref') as $$
begin
	open ref for
	select * from task_13() order by date_set;
end;
$$ language plpgsql;

drop procedure if exists p3_task_14 cascade;
create or replace procedure p3_task_14 (
	inout peer_nickname varchar default null,
	inout total_amt int default null) as $$

begin
	select into peer_nickname, total_amt
		peer, 
		sum(xp.xp_amount) as total_xp 
	from xp 
	left join checks on checks.id = xp._check 
	group by peer 
	order by total_xp desc 
	limit 1;
end;
$$ language plpgsql;

drop procedure if exists p3_task_15 cascade;
create or replace procedure p3_task_15 (
	ref refcursor default 'ref',
	limit_time time default '06:00:00',
	limit_entrings int default 10) as $$
begin
	open ref for
		select peer as peer_list from 
		(
			select 
				peer, 
				_date, 
				min(_time) as time_first_entering 
			from time_tracking 
			group by peer, _date
			having min(_time) < limit_time
		) as tmp
		group by peer
		having count(time_first_entering) >= limit_entrings
		order by count(time_first_entering) desc;
end;
$$ language plpgsql;

drop procedure if exists p3_task_16 cascade;
create or replace procedure p3_task_16 (
	ref refcursor default 'ref',
	limit_days int default 10,
	min_exits int default 0) as $$
begin
	open ref for
	with 
	n_last_days as (
		select distinct _date
		from time_tracking
		order by _date desc
		limit limit_days
	), 
	exits_per_day as (
		select 
			peer, 
			_date, 
			count(state) - 1 as exits 
		from time_tracking 
		where 
			_date in (select * from n_last_days) and 
			state = '2' 
		group by peer, _date 
		having count(state) - 1 > 0
		order by peer, _date, exits desc
	),
	total_exits as (
		select peer, sum(exits) as total_exits
		from exits_per_day
		group by peer
		order by total_exits desc
	)
	select peer as peer_list from total_exits where total_exits > min_exits;
end;
$$ language plpgsql;

drop procedure if exists p3_task_17 cascade;
create or replace procedure p3_task_17 (
	ref refcursor default 'ref') as $$
begin
	open ref for
	with 
	peers_birthday_month as (
		select nickname, to_char(birthday, 'Month') as birthday_month 
		from peers
	),
	total_entrings as (
		select distinct peer, count(distinct _date) as total_entrings 
		from time_tracking group by peer
		order by total_entrings desc
	),
	early_entrings as (
		select peer, count(_date) as early_entrings from (
		select distinct peer, _date, min(_time) as first_entering
		from time_tracking group by peer, _date
		having min(_time) < '12:00:00'
		order by peer, _date) as tmp
		group by peer
		order by early_entrings desc
	),
	shared_df as (
		select 
			peers_birthday_month.nickname as peer,
			birthday_month,
			total_entrings,
			early_entrings
		from peers_birthday_month
		left join 
			total_entrings on peers_birthday_month.nickname = total_entrings.peer
		left join
			early_entrings on peers_birthday_month.nickname = early_entrings.peer
	),
	ratio as (
		select birthday_month as month, round((sum(early_entrings) / sum(total_entrings))::float * 100) as early_entries
		from shared_df
		group by birthday_month
		order by early_entries desc
	)
	select * from ratio;
end;
$$ language plpgsql;

--BEGIN;
--    call p3_task_15();
--    FETCH ALL IN "ref";
--    CLOSE ref;
--END;
