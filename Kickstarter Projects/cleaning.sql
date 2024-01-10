SELECT * FROM kickstarters;
--Overview of the dataset

SELECT id
FROM kickstarters
GROUP BY id
HAVING COUNT(id) > 1;
--Check if there are duplicates in the dataset
--There are none

SELECT *
FROM kickstarters 
WHERE name IS NULL
		OR category IS NULL
		OR sub_category IS NULL
		OR country IS NULL
		OR launched IS NULL
		OR deadline IS NULL
		OR goal IS NULL
		OR plegded IS NULL
		OR backers IS NULL
		OR state IS NULL;
--Check if there are missing values in the dataset
--No missing values. There are some values in goal, plegded, or backers are 0 probably that have been filled in for missing values.

SELECT * 
FROM INFORMATION_SCHEMA.COLUMNS
WHERE TABLE_NAME = 'kickstarters';
--Check if table's datatypes match with the table creation and import data code
--All columns match with the importing data code
--Data is clean and ready for analysis
