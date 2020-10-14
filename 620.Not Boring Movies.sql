# https://leetcode.com/problems/not-boring-movies/submissions/
# Write your MySQL query statement below
select * from cinema where id % 2 = 1 and description not like 'boring' order by rating desc;