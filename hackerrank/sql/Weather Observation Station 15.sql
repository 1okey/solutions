-- https://www.hackerrank.com/challenges/weather-observation-station-15/problem
select round(long_w, 4) 
from station 
where lat_n < 137.2345 
order by lat_n desc 
limit 1;