select a.Title, count(t.TrackId) as TotalSongs, sum(t.Milliseconds) as TotalDuration
from Album a inner join Track t on a.AlbumId=t.AlbumId
group by a.AlbumId;
