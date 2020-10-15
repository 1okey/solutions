# https://leetcode.com/problems/second-highest-salary/
# Write your MySQL query statement below
select max(Salary) as SecondHighestSalary from Employee as e
where e.Salary < (select max(Salary) from Employee)