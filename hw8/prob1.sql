select t.name, cast(t.Milliseconds/1000/60 as text) || ':' ||cast(t.Milliseconds/1000%60 as text) as 'minutes:seconds'
from Album a inner join Track t on a.AlbumId=t.AlbumId
where a.Title = 'Temple of the Dog';
