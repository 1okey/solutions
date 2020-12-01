-- https://www.hackerrank.com/challenges/weather-observation-station-18/problem
select 
    round(abs(min(lat_n) - max(lat_n)) + abs(min(long_w) - max(long_w)), 4)
as distance from station;