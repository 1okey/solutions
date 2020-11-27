-- https://www.hackerrank.com/challenges/weather-observation-station-16/problem
select round(lat_n, 4) from station where lat_n > 38.7780 order by lat_n asc limit 1;
-- or 
select round(min(lat_n), 4) from station where lat_n > 38.7780;