-- https://www.hackerrank.com/challenges/average-population-of-each-continent/problem
select co.continent, round(avg(c.population) - 0.5)
from city as c
join country as co
on co.code = c.countrycode
group by co.continent;