select e.employee_id, e.name, count(e.employee_id) as reports_count,
round(avg(m.age*1.0)) as average_age  
from Employees e
join Employees m 
on e.employee_id =m.reports_to 
group by e.employee_id
order by e.employee_id