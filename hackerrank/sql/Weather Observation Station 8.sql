-- https://www.hackerrank.com/challenges/weather-observation-station-8/problem
select distinct city from station 
where right(city, 1) in ('a','i','e','o','u') 
and left(city, 1) in ('a','i','e','o','u');