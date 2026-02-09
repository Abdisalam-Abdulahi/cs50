-- 13. Names of all people who starred in a movie in which Kevin Bacon also starred

SELECT DISTINCT name FROM people JOIN stars on people.id = stars.person_id WHERE stars.person_id IN (
    SELECT DISTINCT person_id FROM stars WHERE name != 'Kevin Bacon' AND movie_id IN (
        SELECT movie_id FROM stars WHERE person_id = (
            SELECT id from people WHERE name = 'Kevin Bacon' and birth = 1958
        )));













----""""SELECT DISTINCT name FROM people JOIN stars on people.id = stars.person_id WHERE stars.person_id IN (
 ----   SELECT DISTINCT person_id FROM stars WHERE person_id != 102 AND movie_id IN (
     -----    SELECT movie_id FROM stars WHERE person_id = 102));
----""