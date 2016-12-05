select t.name, count(il.TrackId) as Purchased
from InvoiceLine il
inner join Track t on il.TrackId=t.TrackId
group by il.TrackId
order by Purchased desc
limit 10;
