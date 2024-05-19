select (
    select distinct(salary) from employee
    group by salary
    order by salary DESC
    limit 1 offset 1
    
)
as SecondHighestSalary