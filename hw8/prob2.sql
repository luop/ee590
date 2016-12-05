select t.Name as TrackName, a.Title as AlbumName, ar.Name as Artist
from Album a
inner join Track t on a.AlbumId=t.AlbumId
inner join Artist ar on a.ArtistId=ar.ArtistId
order by Milliseconds desc
limit 1;
