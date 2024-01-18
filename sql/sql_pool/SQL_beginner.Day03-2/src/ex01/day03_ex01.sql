select 
	menu.id
from menu
left join person_order on person_order.menu_id=menu.id
where order_date is null
order by menu.id;

select distinct
	menu.id
from menu
except
select distinct
	menu_id
from person_order
order by id;
