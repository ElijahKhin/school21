update menu
set price = round(price * 0.9)
where pizza_name = 'greek pizza';

cluster menu using menu_pkey;
