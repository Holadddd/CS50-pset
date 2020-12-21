 SELECT name FROM people
 WHERE id IN (
    SELECT person_id FROM stars 
    WHERE movie_id IN (
        /*Movie ID*/
        SELECT movie_id FROM stars 
        WHERE person_id == ( 
            /*Kevin Bacon ID*/
            SELECT id FROM people WHERE (name == "Kevin Bacon") 
            AND birth == 1958
            )
    )
)
AND id != (
        /*Kevin Bacon ID*/
        SELECT id FROM people WHERE (name == "Kevin Bacon") 
        AND birth == 1958
);


 
 