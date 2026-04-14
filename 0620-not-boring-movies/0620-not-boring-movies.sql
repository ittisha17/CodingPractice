# Write your MySQL query statement belowse
select * from cinema where
id%2<>0 and description not like 'boring'
order by rating desc;