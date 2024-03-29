# Write your MySQL query statement below
select distinct author_id as id from views
where author_id=viewer_id
order by id

/*-- Ascending order (default)
SELECT column1, column2
FROM table_name
ORDER BY column1;

-- Descending order
SELECT column1, column2
FROM table_name
ORDER BY column1 DESC;

-- Sorting by multiple columns
SELECT column1, column2
FROM table_name
ORDER BY column1, column2;
*/

