-- https://www.hackerrank.com/challenges/earnings-of-employees/problem
select 
    salary * months as earnings, 
    count(name) as count 
from employee 
group by earnings 
order by count desc 
limit 1;