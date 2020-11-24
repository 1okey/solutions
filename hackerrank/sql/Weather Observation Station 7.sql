-- https://www.hackerrank.com/challenges/weather-observation-station-7/problem
select distinct city from station where right(city, 1) in ('a','i','e','o','u');