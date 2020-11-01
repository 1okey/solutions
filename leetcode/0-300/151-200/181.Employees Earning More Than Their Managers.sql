# https://leetcode.com/problems/employees-earning-more-than-their-managers/submissions/
# Write your MySQL query statement below
select e.Name as Employee 
from Employee as e
join Employee as m
on e.managerId = m.Id
where e.salary > m.salary;
