# Write your MySQL query statement below
Select m.name
from employee as e
inner join employee as m
on e.managerId=m.id
group by e.managerId 
having count(e.id)>=5

#https://chat.openai.com/share/8d8c5877-736c-4252-94a0-dbb399c68bd2
