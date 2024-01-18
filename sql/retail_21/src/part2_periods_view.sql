DROP VIEW IF EXISTS periods_view CASCADE;
CREATE VIEW periods_view AS
SELECT
    c.customer_id,
    sg.group_id,
    MIN(t.transaction_datetime) as first_group_purchase_date,
    MAX(t.transaction_datetime) as last_group_purchase_date,
    COUNT(t.transaction_id) as group_purchase,
    ROUND((MAX(t.transaction_datetime)::date - MIN(t.transaction_datetime)::date + 1)::numeric / COUNT(t.transaction_id), 2) as group_frequency,
    ROUND(COALESCE(MIN(CASE WHEN ch.sku_discount = 0 THEN NULL ELSE (ch.sku_discount / ch.sku_summ) * 100 END), 0), 2) as Group_Min_Discount
FROM transactions t
JOIN cards c ON c.customer_card_id = t.customer_card_id
JOIN checks ch ON ch.transaction_id = t.transaction_id
JOIN stores st ON st.transaction_store_id = t.transaction_store_id
              AND st.sku_id = ch.sku_id
JOIN sku_group sg ON true
GROUP BY c.customer_id, sg.group_id;
