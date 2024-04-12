# Write your MySQL query statement below
select r.contest_id, round((count(r.contest_id)/(select count(*) from users))*100,2) as percentage
from register r
left join users u
on r.user_id=u.user_id
group by r.contest_id
having r.contest_id is not NULL
order by percentage DESC, r.contest_id