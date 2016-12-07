select c.FirstName, c.LastName, sum(i.total) as TotalSpent
from Invoice i
inner join Customer c on i.CustomerId = c.CustomerId
group by i.CustomerId
order by TotalSpent desc
limit 10;
