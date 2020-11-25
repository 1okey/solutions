-- https://www.hackerrank.com/challenges/weather-observation-station-11/problem
select distinct city from station 
where right(city, 1) not in ('a','i','e','o','u') 
or left(city, 1) not in ('a','i','e','o','u');