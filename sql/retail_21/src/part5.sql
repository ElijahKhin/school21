SET datestyle = 'ISO, DMY';

-- Входные данные
CREATE OR REPLACE FUNCTION generate_growth_offers(
    -- первая и последняя даты периода
    date_start TIMESTAMP,
    date_end TIMESTAMP,
    -- добавляемое число транзакций
    added_transactions INT,
    -- максимальный индекс оттока
    max_churn_index FLOAT,
    -- максимальная доля транзакций со скидкой (в процентах)
    max_discount_ratio FLOAT,
    -- допустимая доля маржи (в процентах)
    max_margin_ratio FLOAT
)
-- Выходные данные
RETURNS TABLE (
    customer_id INT,
    start_date TIMESTAMP,
    end_date TIMESTAMP,
    required_transactions_count INT,
    group_name VARCHAR(255),
    offer_discount_depth INT
)
AS $$
BEGIN
    RETURN QUERY
        WITH purchase_history_total AS (
        /* Определение максимально допустимого размера скидки для вознаграждения. 
        Пользователь вручную определяет долю маржи (в процентах), которую допустимо использовать 
        для предоставления вознаграждения по группе. Итоговое значение максимально допустимой
        скидки рассчитывается путем умножения заданного значения на среднюю маржу клиента по группе. */
                SELECT
                    /* Итоговое значение максимально допустимой скидки рассчитывается 
                       путем умножения заданного значения на среднюю маржу клиента по группе. */
                    (AVG(purchase_history.group_summ) - AVG(purchase_history.group_cost)) / 100.0 * max_margin_ratio 
                    / AVG(purchase_history.group_cost) AS pre_offer_discount_depth,
                    purchase_history.customer_id,
                    purchase_history.group_id
                FROM
                    purchase_history
                GROUP BY
                    purchase_history.customer_id,
                    purchase_history.group_id
        )
        SELECT 
            DISTINCT ON (groups_view.customer_id) groups_view.customer_id :: INT,
            date_start as start_date,
            date_end as end_date,
            -- Определение текущей частоты посещений клиента в заданный период.
            (EXTRACT(EPOCH FROM (date_end - date_start)) / 86400.0 / customer_frequency)
            -- Определение транзакции для начисления вознаграждения.
            :: INT + added_transactions AS target_transactions_count,
            sku_group.group_name AS group_name,
            /* В случае,
               если минимальная скидка после округления меньше значения,
               получившегося на шаге 5, она устанавливается в качестве скидки для
               группы в рамках предложения для клиента. */
            (CEIL(groups_view.group_min_discount / 0.05) * 0.05 * 100) :: INT AS offer_discount_depth
        FROM groups_view
            JOIN sku_group ON sku_group.group_id = groups_view.group_id
            JOIN periods_view ON periods_view.customer_id = groups_view.customer_id AND periods_view.group_id = groups_view.group_id 
            JOIN customers_view ON customers_view.customer_id = groups_view.customer_id
            JOIN purchase_history_total ON purchase_history_total.customer_id = groups_view.customer_id 
            AND purchase_history_total.group_id = groups_view.group_id
        WHERE
            -- Индекс оттока по данной группе не должен превышать заданного пользователем значения. 
            group_churn_rate <= max_churn_index
            -- Доля транзакций со скидкой по данной группе – менее заданного пользователем значения. 
            AND group_discount_share < max_discount_ratio / 100
            /* Определение величины скидки. Значение, полученное на шаге 5,
               сравнивается с минимальной скидкой, которая была зафиксирована для
               клиента по данной группе, округленной вверх с шагом в 5%. */
            AND CEIL(groups_view.group_min_discount / 0.05) * 0.05 < pre_offer_discount_depth
        ORDER BY
            groups_view.customer_id,
            -- Индекс востребованности группы – максимальный из всех возможных. + DISTINCT в SELECT
            groups_view.group_affinity_index DESC, 
            groups_view.group_id;
END;
$$ LANGUAGE plpgsql;

SELECT * FROM generate_growth_offers (
    '20.06.2022 00:00:00', 
    '25.08.2022 00:00:00',
    1,
    4,
    80,
    50
);
