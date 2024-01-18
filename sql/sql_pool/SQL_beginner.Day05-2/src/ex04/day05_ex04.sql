create unique index if not exists idx_menu_unique on menu (pizzeria_id, pizza_name);

set enable_indexscan = on;
set enable_seqscan = off;

explain analyze
SELECT pizzeria_id, pizza_name
FROM menu;

