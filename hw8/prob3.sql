select c.FirstName, c.LastName, sum(i.total) as TotalSpent
from Invoice i, InvoiceLine il, Customer c
where i.InvoiceId = il.InvoiceId and i.CustomerId = c.CustomerId
group by i.CustomerId
order by TotalSpent desc
limit 10;
