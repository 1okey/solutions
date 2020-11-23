-- https://leetcode.com/problems/combine-two-tables/
select p.FirstName, p.LastName, a.City, a.State 
from Person as p    
left join Address as a
on p.PersonId = a.PersonId;