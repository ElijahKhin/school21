-- Подпредставление для базовой информации о транзакциях
CREATE OR REPLACE VIEW transaction_info AS
SELECT
    t.transaction_id,
    t.transaction_datetime,
    c.sku_summ_paid AS group_summ_paid,
	t.customer_card_id,
	ca.customer_id,
	t.transaction_store_id
FROM transactions t
JOIN checks c ON t.transaction_id = c.transaction_id
JOIN cards ca ON t.customer_card_id = ca. customer_card_id;

-- Подпредставление для информации о продуктах
CREATE OR REPLACE VIEW product_info AS
SELECT
    p.group_id,
    s.sku_purchase_price AS group_cost,
    s.sku_retail_price AS group_summ,
	s.transaction_store_id
FROM product_grid p
JOIN stores s ON p.sku_id = s.sku_id;

-- Представление "История покупок", объединяющее подпредставления
CREATE OR REPLACE VIEW purchase_history AS
SELECT
    ti.customer_id,
    ti.transaction_id,
    ti.transaction_datetime,
    pi.group_id,
    pi.group_cost,
    pi.group_summ,
    ti.group_summ_paid
FROM transaction_info ti
JOIN product_info pi ON pi.transaction_store_id = ti.transaction_store_id;
