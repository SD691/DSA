# Write your MySQL query statement below

#SELECT *, IF(x+y>z and y+z>x and z+x>y, "Yes", "No") as triangle FROM Triangle
select *, 
case
when x+y>z and y+z>x and x+z>y then 'Yes'
else 'No' end as triangle from triangle