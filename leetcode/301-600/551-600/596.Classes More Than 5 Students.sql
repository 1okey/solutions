-- https://leetcode.com/problems/classes-more-than-5-students/submissions/
select class from courses 
group by class
having count(distinct student) >= 5;