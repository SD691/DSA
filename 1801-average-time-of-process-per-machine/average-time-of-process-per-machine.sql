select a1.machine_id, round(avg(a2.timestamp-a1.timestamp),3) as processing_time
from Activity a1
left join Activity a2
on a1.machine_id=a2.machine_id and a1.process_id=a2.process_id and a1.activity_type='start' and
a2.activity_type='end'
group by a1.machine_id;
/*https://chat.openai.com/share/8d8c5877-736c-4252-94a0-dbb399c68bd2*/

/*

In SQL, the ROUND() function is used to round a numeric
 value to a specified number of decimal places or to the nearest integer. 
 The syntax typically looks like this:

sql
Copy code
ROUND(numeric_expression, length [,function])
Where:

numeric_expression is the numeric value you want to round.
length is the number of decimal places to which you want to round 
the numeric_expression. If length is a positive number, it specifies 
the number of decimal places to round to. If length is negative, it 
specifies the number of digits to the left of the decimal point to round to. 
If length is 0, the numeric_expression is rounded to the nearest integer.*/





