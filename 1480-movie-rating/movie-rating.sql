# Write your MySQL query statement below
(
    select name as results from Users
    left join 
    MovieRating
    on Users.user_id=MovieRating.user_id 
    group by Users.user_id  
    order by count(MovieRating.user_id) DESC,name
    limit 1 
) 
union all
(   
    select title as results from Movies
    left join
    MovieRating
    on MovieRating.movie_id=Movies.movie_id
    where created_at between '2020-02-01' and '2020-02-28'
    group by title
    order by avg(rating) DESC,title
    limit 1
) 