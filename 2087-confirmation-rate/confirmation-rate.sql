# Write your MySQL query statement below
#select Signups.user_id, as confirmation_rate
select Signups.user_id,round(ifnull(count(case when action='confirmed' then action END)/count(action),0),2) as confirmation_rate from Signups
left join
Confirmations
on Signups.user_id= confirmations.user_id
group by Signups.user_id
