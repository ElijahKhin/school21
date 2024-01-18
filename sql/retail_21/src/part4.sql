DROP FUNCTION IF EXISTS generate_personal_offer(
    INTEGER,
    INTEGER,
    NUMERIC,
    NUMERIC,
    NUMERIC,
    NUMERIC
);
DROP FUNCTION IF EXISTS generate_personal_offer(
    INTEGER,
    DATE,
    DATE,
    NUMERIC,
    NUMERIC,
    NUMERIC,
    NUMERIC
);

CREATE OR REPLACE FUNCTION generate_personal_offer (  -- Параметры функции:
    chosen_method INTEGER,  -- метод расчета среднего чека (1 - за период, 2 - за количество)
    quantity INTEGER,  -- количество транзакций (для 2 метода)
    coefficient NUMERIC,  -- коэффициент увеличения среднего чека
    maximum_churn_index NUMERIC,  -- максимальный индекс оттока
    maximum_share NUMERIC,  -- максимальная доля транзакций со скидкой (в процентах)
    allowable_share NUMERIC  -- допустимая доля маржи (в процентах)
) 
RETURNS TABLE ( Customer_ID BIGINT, Required_Check_Measure NUMERIC, Group_Name VARCHAR(255), Offer_Discount_Depth NUMERIC) 
LANGUAGE PLPGSQL
AS $$
BEGIN
    IF chosen_method = 2 THEN
    RETURN QUERY
select
    customer_id_inner,
    avg_transaction_summ_inner,
    group_name_inner,
    calculated_discount
from
    (
        WITH purchase_history_total AS (
            /* Определение максимально допустимого размера скидки для вознаграждения. 
             Пользователь вручную определяет долю маржи (в процентах), которую допустимо использовать 
             для предоставления вознаграждения по группе. */
            SELECT
                /* Итоговое значение максимально допустимой скидки рассчитывается 
                 путем умножения заданного значения на среднюю маржу клиента по группе. */
                (
                    AVG(purchase_history.group_summ) - AVG(purchase_history.group_cost)
                ) * allowable_share / AVG(purchase_history.group_cost) AS pre_offer_discount_depth,  -- рассчет средней маржи в %
                purchase_history.customer_id,
                purchase_history.group_id
            FROM
                purchase_history
            GROUP BY
                purchase_history.customer_id,
                purchase_history.group_id
        )
        select
            distinct customer_id_inner,
            avg_transaction_summ_inner,
            group_name_inner,
            group_affinity_index_inner,
            ceil(group_minimum_discount_inner * 20) * 5 as calculated_discount  -- округляем вверх минимальную скидку с шагом в 5%
        from
            (
                select
                    customer_id_inner,
                    avg(transaction_summ_inner) over (partition by customer_id_inner) * coefficient as avg_transaction_summ_inner,
                    group_name_inner,
                    group_affinity_index_inner,
                    max(group_affinity_index_inner) over (partition by customer_id_inner) as max_group_affinity_index_inner,
                    group_minimum_discount_inner,
                    pre_offer_discount_depth
                from
                    (
                        select
                            cards.customer_id as customer_id_inner,
                            transactions.transaction_summ as transaction_summ_inner,
                            row_number() over(
                                partition by cards.customer_id
                                order by
                                    transactions.transaction_datetime
                            ) as transaction_summ_inner_counter,  -- переменная для учета количества транзакций, начиная счет с последних
                            sku_group.group_name as group_name_inner,
                            groups_view.group_affinity_index as group_affinity_index_inner,
                            groups_view.group_min_discount as group_minimum_discount_inner,
                            pre_offer_discount_depth
                        from
                            transactions
                            inner join cards on cards.customer_card_id = transactions.customer_card_id
                            inner join groups_view on groups_view.customer_id = cards.customer_id
                            inner join sku_group on sku_group.group_id = groups_view.group_id
                            inner join purchase_history_total on purchase_history_total.customer_id = cards.customer_id
                            and purchase_history_total.group_id = groups_view.group_id
                        where
                            groups_view.group_discount_share < maximum_share / 100
                            and groups_view.group_churn_rate <= maximum_churn_index
                    ) AS tmp_from1
                where
                    transaction_summ_inner_counter <= quantity  -- Фильтруем по количеству для второго метода
            ) AS tmp_from2
        where
            ceil(group_minimum_discount_inner * 20) * 5 < pre_offer_discount_depth
        order by
            group_affinity_index_inner desc
    ) AS tmp_from3;
    END IF;
END; $$;

-- Основная логика:
-- Функция активируется, если chosen_method = 1.
-- Аналогично первой функции, сначала определяется максимальная глубина скидки.
-- Для каждого клиента рассчитывается средний чек за выбранный период. Также определяется максимальная возможная скидка на основе истории покупок за этот период.
-- Скидки округляются с шагом в 5%.
-- Функция возвращает те же значения, что и первая функция.
--CREATE OR REPLACE FUNCTION generate_personal_offer (
--    chosen_method INTEGER,
--    start_date DATE,
--    end_date DATE,
--    coefficient NUMERIC,
--    maximum_churn_index NUMERIC,
--    maximum_share NUMERIC,
--    allowable_share NUMERIC
--) 
--RETURNS TABLE ( Customer_ID BIGINT, Required_Check_Measure NUMERIC, Group_Name VARCHAR(255), Offer_Discount_Depth NUMERIC) 
--LANGUAGE PLPGSQL
--AS $$
--BEGIN
--    IF chosen_method = 1 THEN
--    RETURN QUERY
--select
--    customer_id_inner,
--    avg_transaction_summ_inner,
--    group_name_inner,
--    calculated_discount
--from
--    (
--        WITH purchase_history_total AS (
--            /* Определение максимально допустимого размера скидки для вознаграждения. 
--             Пользователь вручную определяет долю маржи (в процентах), которую допустимо использовать 
--             для предоставления вознаграждения по группе. */
--            SELECT
--                /* Итоговое значение максимально допустимой скидки рассчитывается 
--                 путем умножения заданного значения на среднюю маржу клиента по группе. */
--                (
--                    AVG(purchase_history.group_summ) - AVG(purchase_history.group_cost)
--                ) * allowable_share / AVG(purchase_history.group_cost) AS pre_offer_discount_depth,
--                purchase_history.customer_id,
--                purchase_history.group_id
--            FROM
--                purchase_history
--            GROUP BY
--                purchase_history.customer_id,
--                purchase_history.group_id
--        )
--        select
--            distinct customer_id_inner,
--            avg_transaction_summ_inner,
--            group_name_inner,
--            group_affinity_index_inner,
--            ceil(group_minimum_discount_inner * 20) * 5 as calculated_discount
--        from
--            (
--                select
--                    customer_id_inner,
--                    avg(transaction_summ_inner) over (partition by customer_id_inner) * coefficient as avg_transaction_summ_inner,
--                    group_name_inner,
--                    group_affinity_index_inner,
--                    max(group_affinity_index_inner) over (partition by customer_id_inner) as max_group_affinity_index_inner,
--                    group_minimum_discount_inner,
--                    pre_offer_discount_depth
--                from
--                    (
--                        select
--                            cards.customer_id as customer_id_inner,
--                            transactions.transaction_summ as transaction_summ_inner,
--                            sku_group.group_name as group_name_inner,
--                            groups_view.group_affinity_index as group_affinity_index_inner,
--                            groups_view.group_min_discount as group_minimum_discount_inner,
--                            pre_offer_discount_depth
--                        from
--                            transactions
--                            inner join cards on cards.customer_card_id = transactions.customer_card_id
--                            inner join groups_view on groups_view.customer_id = cards.customer_id
--                            inner join sku_group on sku_group.group_id = groups_view.group_id
--                            inner join purchase_history_total on purchase_history_total.customer_id = cards.customer_id
--                            and purchase_history_total.group_id = groups_view.group_id
--                        where
--                            groups_view.group_discount_share < maximum_share / 100
--                            and groups_view.group_churn_rate <= maximum_churn_index
--                            and transactions.transaction_datetime >= '01-01-1999'
--                            and transactions.transaction_datetime <= '01-01-2030'
--                    ) AS tmp_from5
--            ) AS tmp_from6
--        where
--            ceil(group_minimum_discount_inner * 20) * 5 < pre_offer_discount_depth
--        order by
--            group_affinity_index_inner desc
--    ) AS tmp_from7;
--    END IF;
--END; $$;

SELECT * FROM generate_personal_offer(2, 100, 1.15, 3, 70, 30);
