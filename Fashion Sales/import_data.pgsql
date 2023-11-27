CREATE TABLE fashion_sales(customer_id INT,
                        item_purchased VARCHAR,
                        purchase_amount FLOAT,
                        date_purchased DATE,
                        review_rating FLOAT,
                        payment_method VARCHAR);

COPY fashion_sales(customer_id,
                item_purchased,
                purchase_amount,
                date_purchased,
                review_rating,
                payment_method)
FROM 'C:\Users\Public\Fashion_Retail_Sales.csv'
DELIMITER ','
CSV HEADER;