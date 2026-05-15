# Write your MySQL query statement below
select q.query_name,round(avg(q.rating/q.position),2) as quality,
round(avg(rating<3)*100,2) as  poor_query_percentage
from queries q
group by q.query_name;
