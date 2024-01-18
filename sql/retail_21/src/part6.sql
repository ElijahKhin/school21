CREATE OR REPLACE FUNCTION generate_cross_selling (  -- Параметры функции:
    number_of_groups BIGINT,  -- количество групп
    maximum_churn_index NUMERIC,  -- максимальный индекс оттока
    maximum_consumption_stability_index NUMERIC,  -- максимальный индекс стабильности потребления
    maximum_SKU_share NUMERIC,  -- максимальная доля SKU (в процентах)
    allowable_margin_share INTEGER  -- допустимая доля маржи (в процентах)
) 
RETURNS TABLE ( Customer_ID BIGINT, SKU_Name VARCHAR(255), Offer_Discount_Depth NUMERIC)
LANGUAGE PLPGSQL
AS $$
BEGIN
    return query
        select
            customer_id_inner,
            sku_name_inner,
            ceil(group_minimum_discount_inner * 100 / 5) * 5
        from
            (
                select
                    *,
                    row_number() over(
                        partition by customer_id_inner
                        order by
                            group_affinity_index_inner
                    ) as group_counter_inner,  -- Счетчик групп для параметра number_of_groups
                    max(difference_inner) over(partition by customer_id_inner) as max_difference_inner,  -- Запоминаем максимальную маржу SKU
                    allowable_margin_share * difference_inner / sku_retail_price_inner as calculated_discount_inner
                from
                    (
                        select
                            distinct groupsview.customer_id as customer_id_inner,
                            groupsview.group_id as group_id_inner,
                            groupsview.group_affinity_index as group_affinity_index_inner,
                            retailstores.sku_retail_price - retailstores.sku_purchase_price as difference_inner,  -- Маржи SKU для выбора максимальной во внешнем запросе
                            retailstores.sku_retail_price as sku_retail_price_inner,
                            productmatrix.sku_name as sku_name_inner,  -- Название SKU
                            100.0 * count(productmatrix.sku_name) over () / count(groupsview.group_id) over () as sku_share_inner,  -- Доля SKU в своей группе, для фильрации параметром maximum_SKU_share
                            groupsview.group_minimum_discount as group_minimum_discount_inner,  -- Запоминаем минимальную скидку для рассчета итоговой скидки
                            customersview.customer_primary_store as customer_primary_store_inner,  -- Запоминаем основной магазин каждого клиента для внешнего запроса
                            retailstores.transaction_store_id as transaction_store_id_inner
                        from
                            groupsview
                            inner join productmatrix on productmatrix.group_id = groupsview.group_id
                            inner join retailstores on retailstores.sku_id = productmatrix.sku_id
                            inner join transactions on transactions.transaction_store_id = retailstores.transaction_store_id
                            inner join customersview on customersview.customer_id = groupsview.customer_id
                        where
                            groupsview.group_churn_rate <= maximum_churn_index  -- Фильтр по заданному индексу оттока
                            and groupsview.group_stability_index < maximum_consumption_stability_index  -- Фильтр по заданному индексу стабильности
                    ) AS tmp_from1
            ) AS tmp_from2
        where
            group_counter_inner <= number_of_groups  -- Фильтр по заданному числу групп
            and difference_inner = max_difference_inner  -- Выбор продуктов с максимальной маржой
            and sku_share_inner <= maximum_SKU_share  -- Фильтр по заданной доле SKU в каждой группе
            and customer_primary_store_inner = transaction_store_id_inner  -- Анализируем только основные магазины клиентов
            and ceil(group_minimum_discount_inner * 100 / 5) * 5 <= calculated_discount_inner;
END; $$;

SELECT * FROM generate_cross_selling(
    5, 3, 0.5, 100, 30);
