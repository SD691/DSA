# Write your MySQL query statement below
select teacher_id, count(distinct(subject_id)) as cnt from teacher
group by teacher_id 

/*https://chat.openai.com/share/65bb69e3-da96-4c9e-a315-76c189579388*/
