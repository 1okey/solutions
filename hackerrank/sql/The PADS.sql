-- https://www.hackerrank.com/challenges/the-pads/problem
select 
    concat(name, '(', substr(occupation, 1,1), ')')
from occupations order by name asc;

select 
    concat('There are a total of ', count(occupation), ' ', lower(occupation), 's.')
from occupations 
group by occupation
order by count(occupation) asc;