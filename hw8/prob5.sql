select distinct a.Title
from Album a inner join Track t on a.AlbumId=t.AlbumId
where t.Milliseconds/1000/60 > 6;
