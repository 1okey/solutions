-- https://www.hackerrank.com/challenges/weather-observation-station-10/problem
select distinct city from station 
where right(city, 1) not in ('a','i','e','o','u');