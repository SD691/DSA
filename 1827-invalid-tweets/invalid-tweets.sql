# Write your MySQL query statement below
select tweet_id from tweets where length(content)>15

/*
To count the number of characters in a string column in SQL, 
you can use the LENGTH() function in most SQL databases. 
However, some databases like MySQL have CHAR_LENGTH() specifically 
for counting characters. Here's how you can use these functions:

Using LENGTH():

sql
Copy code
SELECT LENGTH(column_name) AS character_count
FROM table_name;
Using CHAR_LENGTH() in MySQL:

sql
Copy code
SELECT CHAR_LENGTH(column_name) AS character_count
FROM table_name;
Replace column_name with the name of the column you want to count characters from, and table_name with the name of your table.

These queries will return the number of char
*/