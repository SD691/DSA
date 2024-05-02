select e1.name from employee e1
inner join
employee e2
on e1.id=e2.managerId
group by e1.id
having count(e2.managerId)>4


