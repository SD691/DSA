# Write your MySQL query statement below
select ifNULL(
    (select n1.num from MyNumbers n1
left join MyNumbers n2
on n1.num=n2.num
group by n1.num
having count(n1.num)<=1
order by n1.num DESC
limit 1),null)
as num