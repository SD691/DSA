# Write your MySQL query statement below
select name from customer
where referee_id != 2 or referee_id is NULL

/*
-- Checking for NULL values
SELECT * FROM table_name WHERE column_name IS NULL;

-- Checking for non-NULL values
SELECT * FROM table_name WHERE column_name IS NOT NULL;

-- Checking for TRUE values
SELECT * FROM table_name WHERE boolean_column IS TRUE;

-- Checking for FALSE values
SELECT * FROM table_name WHERE boolean_column IS FALSE;
*/