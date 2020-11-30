-- https://www.hackerrank.com/challenges/draw-the-triangle-1/problem
set @row := 21;
select repeat('* ', @row := @row - 1) from information_schema.tables where @row > 0