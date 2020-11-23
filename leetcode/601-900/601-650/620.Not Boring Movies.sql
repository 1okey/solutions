-- https://leetcode.com/problems/not-boring-movies/submissions/
select * from cinema where id % 2 = 1 and description not like 'boring' order by rating desc;