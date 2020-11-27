-- https://www.hackerrank.com/challenges/weather-observation-station-13/problem
select truncate(sum(lat_n), 4) 
from station 
where lat_n > 38.7880 and lat_n < 137.2345;