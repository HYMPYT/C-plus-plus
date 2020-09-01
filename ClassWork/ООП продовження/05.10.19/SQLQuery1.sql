/*create database Films
go
use Films
create table Film
(
id int identity primary key not null,
title nvarchar(60) not null,
director nvarchar(30),
r_year int check(r_year>1900) default 1901,
country nvarchar(20),
genre nvarchar(100)
);*/
---Insert---
/*insert into Film(title, director, r_year, country, genre)
values('Titanic', 'cameron', 1997, 'USA', 'Comedy')*/

/*insert into Film(title, director, r_year, country, genre)
values
('Matrix', 'Vachovsky', 1996, 'USA', 'Action'),
('Batman', 'Nolan', 2008, 'USA', 'Comics'),
('Joker', ' ', 2019, 'USA', 'Drama')*/

--update Film
--set country = 'Ukrain'
--where id = 1 or id = 3

delete
from Film
where id = 2

select *
from Film
order by r_year

--select title as 'Название', genre as 'Жанр'
--from Film
--where r_year>2000

--select *
--from Film;