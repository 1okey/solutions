-- https://www.hackerrank.com/challenges/what-type-of-triangle/problem
select case             
            when A + B > C and B + C > A and A + C > B then
                CASE 
                    when A = B and B = C then 'Equilateral'
                    when A = B or B = C or A = C then 'Isosceles'
                    else 'Scalene'
                end
            else 'Not A Triangle'
        end
from triangles; 