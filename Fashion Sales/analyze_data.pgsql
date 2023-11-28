SELECT * FROM fashion_sales
LIMIT 10;
--Overview of the data

--Question 1:How much sales were made in each month? 
SELECT DISTINCT EXTRACT(YEAR FROM date_purchased) AS year, EXTRACT(MONTH FROM date_purchased) AS month, SUM(purchase_amount) AS total_revenue FROM fashion_sales
WHERE purchase_amount != 0
GROUP BY EXTRACT(MONTH FROM date_purchased), EXTRACT(YEAR FROM date_purchased)
ORDER BY EXTRACT(YEAR FROM date_purchased);

--Quesiton2: Which month have the most revenue? Which month have the least sales
WITH total_revenue_in_a_month AS(
    SELECT DISTINCT EXTRACT(YEAR FROM date_purchased) AS year, EXTRACT(MONTH FROM date_purchased) AS month, SUM(purchase_amount) AS total_revenue FROM fashion_sales
GROUP BY EXTRACT(MONTH FROM date_purchased), EXTRACT(YEAR FROM date_purchased)
ORDER BY EXTRACT(YEAR FROM date_purchased)
)
SELECT total_revenue, month, year FROM total_revenue_in_a_month
ORDER BY total_revenue DESC
LIMIT 1;

WITH total_revenue_in_a_month AS(
    SELECT DISTINCT EXTRACT(YEAR FROM date_purchased) AS year, EXTRACT(MONTH FROM date_purchased) AS month, SUM(purchase_amount) AS total_revenue FROM fashion_sales
GROUP BY EXTRACT(MONTH FROM date_purchased), EXTRACT(YEAR FROM date_purchased)
ORDER BY EXTRACT(YEAR FROM date_purchased)
)
SELECT total_revenue, month, year FROM total_revenue_in_a_month
ORDER BY total_revenue ASC
LIMIT 1;
--December of 2022 have the highest sales - 46851

--October of 2023 have the lowest sales - 423

--Question 3: In the month with the least sales, what causes the sales to be low?

SELECT COUNT(purchase_amount) AS total_empty_values, TO_CHAR(date_purchased, 'MM-YYYY') AS month FROM fashion_sales
WHERE purchase_amount = 0 AND TO_CHAR(date_purchased, 'MM-YYYY') = '10-2023'
GROUP BY month;
--Check if the month have a lot of 0 values
--This month have no record with empty purchase amount
--There are only 5 records in this month. This suggests that either there are no other sales made in this month or there are more records that have not been collected in ihis month

--Question 4: What is the top 10 best rated items? 

SELECT item_purchased, ROUND(AVG(review_rating)*100)/100 AS average_rating FROM fashion_sales
GROUP BY item_purchased
ORDER BY average_rating DESC
LIMIT 10;

-- The top 10 best rated items are:
-- Sun Hat
-- Trench Coat
-- Flips-Flops
-- Sandals
-- Coat
-- Scraf
-- Umbrella
-- Skirt
-- Wallet
-- Jeans

--Question 5: Which item make the most revenue? Which item make the most sales

SELECT item_purchased, SUM(purchase_amount) AS total_revenue FROM fashion_sales
GROUP BY item_purchased
ORDER BY total_revenue DESC
LIMIT 10;

--Based on customer's reviews, 'Sun Hat' have the best average rating of 3.14 but it did not make the top 10 items with most sales.
--Instead, it is 'Tunic' at 17275$, 1.32 times more than the next most revenue made item 'Jeans'

SELECT item_purchased, COUNT(*) AS total_sales FROM fashion_sales
GROUP BY item_purchased
ORDER BY total_sales DESC;

--'Sun Hat' even though have the best rating, it has the lowest sales 
--'Tunic' makes the most revenue but it is 37th in sales made
--'Belt' makes the most sales and it is not in the top 10 most revenue made items.

--Question 6: What payment methods do customer use the most?

SELECT DISTINCT payment_method FROM fashion_sales;
--See types of paying method
--There are two types of payment: Credit Card and Cash

SELECT COUNT(payment_method) FILTER(WHERE payment_method = 'Credit Card') AS with_card, COUNT(payment_method) FILTER(WHERE payment_method = 'Cash') AS with_cash FROM fashion_sales;
--Each payment method's number of sales
--The number of sales of both payments are in similar range

WITH count_payment_method AS (SELECT COUNT(payment_method) FILTER(WHERE payment_method = 'Credit Card') AS with_card, COUNT(payment_method) FILTER(WHERE payment_method = 'Cash') AS with_cash FROM fashion_sales)
SELECT ROUND(with_card/(with_card+with_cash)::FLOAT*100) AS card_perc, ROUND(with_cash/(with_card+with_cash)::FLOAT*100) AS cash_perc, with_card+with_cash FROM count_payment_method
GROUP BY card_perc, cash_perc, with_card, with_cash;
--Check payment method's sales in percentage
--Credit Card takes up 52% whereas Cash is 48%

--Question 7: What item is paid with Credit Card the most? What item is paid with Cash the most?

SELECT item_purchased, payment_method, COUNT(payment_method) AS total FROM fashion_sales
WHERE payment_method = 'Credit Card'
GROUP BY payment_method, item_purchased
ORDER BY total DESC
LIMIT 1;
--The item bought with Credit Card the most is 'Skirt' with 55 sales

SELECT item_purchased, payment_method, COUNT(payment_method) AS total FROM fashion_sales
WHERE payment_method != 'Credit Card'
GROUP BY payment_method, item_purchased
ORDER BY total DESC
LIMIT 1;
--The item bought with Cash the most is 'Tank Top' with 47 sales