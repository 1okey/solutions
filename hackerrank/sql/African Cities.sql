-- https://www.hackerrank.com/challenges/african-cities/problem
select c.name from city as c
join country as co
on co.code = c.countrycode
where co.continent = 'Africa';