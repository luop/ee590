select ar.name, sum(il.UnitPrice * il.Quantity) as TotalSpent
from InvoiceLine il, Track t, Album a, Artist ar
where il.TrackId = t.TrackId and t.AlbumId = a.AlbumId and a.ArtistId = ar.ArtistId
group by ar.ArtistId
order by TotalSpent desc
limit 10;
