WITH purchase_history_total AS (
    SELECT
        (AVG(ph.group_summ_paid) - AVG(ph.group_cost)) / 100.0 * 80 / AVG(ph.group_cost) AS pre_offer_discount_depth,
        ph.customer_id,
        ph.group_id
    FROM purchase_history ph
    GROUP BY ph.customer_id, ph.group_id
)

SELECT 
    DISTINCT ON (groups_view.customer_id) groups_view.customer_id :: INT,
    '2023-01-10 00:00:00' as start_date,
    '2023-10-30 00:00:00' as end_date,

    (('2023-10-30 00:00:00'::date - '2023-01-10 00:00:00'::date) / customers_view.customer_frequency):: INT + 1 AS required_transactions_count,
    sku_group.group_name AS group_name,

    (CEIL(groups_view.group_min_discount / 0.05) * 0.05 * 100) :: INT AS offer_discount_depth
FROM groups_view

JOIN sku_group ON sku_group.group_id = groups_view.group_id
JOIN periods_view ON periods_view.customer_id = groups_view.customer_id AND periods_view.group_id = groups_view.group_id 
JOIN customers_view ON customers_view.customer_id = groups_view.customer_id
JOIN purchase_history_total ON purchase_history_total.customer_id = groups_view.customer_id
AND purchase_history_total.group_id = groups_view.group_id

WHERE
    groups_view.group_churn_rate <= 4
    AND groups_view.group_discount_share < 50 / 100
    AND CEIL(groups_view.group_min_discount / 0.05) * 0.05 < pre_offer_discount_depth

ORDER BY groups_view.customer_id, groups_view.group_affinity_index DESC, groups_view.group_id;
