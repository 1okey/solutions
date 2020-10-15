# https://leetcode.com/problems/customers-who-never-order/
# Write your MySQL query statement below
select c.Name as Customers from customers as c
left join Orders as o
on c.id = o.CustomerId
where CustomerId is null