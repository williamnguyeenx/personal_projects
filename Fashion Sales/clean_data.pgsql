SELECT * FROM fashion_sales
LIMIT 10;
--Overview of file

SELECT * FROM INFORMATION_SCHEMA.COLUMNS
WHERE table_name = 'fashion_sales';
--Check table's datatype

SELECT * FROM fashion_sales
WHERE CAST(purchase_amount AS TEXT) LIKE '%.%';
--See if any data in purchase_amount is decimal value
--No values in purchase_amount is decimal value

ALTER TABLE fashion_sales
ALTER COLUMN purchase_amount
TYPE INT;
--Update purchase_amount's datatype from float to int

SELECT purchase_amount FROM fashion_sales
LIMIT 10;
--Check if update is successful
--Updated purchase_amount successful

SELECT * FROM 
    (SELECT
        customer_id,
        ROW_NUMBER() OVER(
            PARTITION BY 
                customer_id,
                item_purchased,
                purchase_amount,
                date_purchased,
                review_rating,
                payment_method
        ) - 1 AS duplicate, 
        item_purchased,
        purchase_amount,
        date_purchased,
        review_rating,
        payment_method
    FROM 
        fashion_sales)
WHERE duplicate > 0;
--Check for duplicates in the table
--There are no duplicates in the table

SELECT * FROM fashion_sales
WHERE customer_id IS NULL 
    OR customer_id IS NULL
    OR item_purchased IS NULL
    OR purchase_amount IS NULL
    OR date_purchased IS NULL
    OR review_rating IS NULL
    OR payment_method IS NULL;
--Check table's column to see if there are NULL values. 
--Exists some NULL VALUES.


SELECT customer_id FROM fashion_sales
WHERE customer_id IS NULL
LIMIT 1;

SELECT item_purchased FROM fashion_sales
WHERE item_purchased IS NULL
LIMIT 1;

SELECT purchase_amount FROM fashion_sales
WHERE purchase_amount IS NULL
LIMIT 1;

SELECT date_purchased FROM fashion_sales
WHERE date_purchased IS NULL
LIMIT 1;

SELECT review_rating FROM fashion_sales
WHERE review_rating IS NULL
LIMIT 1;

SELECT payment_method FROM fashion_sales
WHERE payment_method IS NULL
LIMIT 1;
--Check each columns for NULL values
--NULL values exist in columns 'purchase_amount' and 'review' review_rating

UPDATE fashion_sales
SET purchase_amount = COALESCE(purchase_amount, 0);
--Fill in purchase_amount's NULL values with 0

SELECT COUNT(*) FROM fashion_sales 
WHERE purchase_amount IS NULL;
--Filled in NULL value successful

UPDATE fashion_sales
SET review_rating = COALESCE(review_rating, 0.0);
--Fill in review_rating's NULL values with 0

SELECT COUNT(*) FROM fashion_sales 
WHERE review_rating IS NULL;
--Filled in NULL value successful

SELECT * FROM fashion_sales
--Check the table again

--Data cleaning completed