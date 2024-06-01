SELECT 
    q1.person_name
FROM Queue q1 JOIN Queue q2 ON q1.turn >= q2.turn
group by q1.turn
having sum(q2.weight)<=1000
order by q1.turn DESC
limit 1

 