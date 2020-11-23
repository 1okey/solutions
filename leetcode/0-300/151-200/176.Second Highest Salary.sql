-- https://leetcode.com/problems/second-highest-salary/
select max(Salary) as SecondHighestSalary from Employee as e
where e.Salary < (select max(Salary) from Employee)