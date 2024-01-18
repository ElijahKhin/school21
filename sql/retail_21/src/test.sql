SELECT customer_id               AS "Customer_ID",
       group_id                  AS "Group_ID",
       MIN(transaction_datetime) AS "First_Group_Purchase_Date",
       MAX(transaction_datetime) AS "Last_Group_Purchase_Date",
       COUNT(transaction_id)  AS "Group_Purchase",
       ROUND((MAX(transaction_datetime)::date - MIN(transaction_datetime)::date + 1)::numeric / COUNT(transaction_id), 2)         AS "Group_Frequency",
       ROUND(COALESCE(MIN(CASE
                              WHEN sku_discount = 0 THEN NULL
                              ELSE sku_discount / sku_summ END), 0), 2)                     AS "Group_Min_Discount"
from get_base
group by customer_id, group_id
order by 1,2;
