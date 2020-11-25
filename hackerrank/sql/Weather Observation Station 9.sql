-- https://www.hackerrank.com/challenges/weather-observation-station-9/problem
select distinct city from station 
where left(city, 1) not in ('a','i','e','o','u');