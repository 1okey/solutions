-- https://www.hackerrank.com/challenges/asian-population/problem
select sum(c.population) from city as c
join country as co
on co.code = c.countrycode
where co.continent = 'Asia';