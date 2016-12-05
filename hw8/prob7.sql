select ar.name, sum(t.Milliseconds/1000/60) as Duration
from Album a
inner join Track t on a.AlbumId=t.AlbumId
inner join Artist ar on a.ArtistId=ar.ArtistId
group by a.ArtistId
order by Duration desc
limit 10;
