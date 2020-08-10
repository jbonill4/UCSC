DROP FUNCTION incriment(integer);

CREATE OR REPLACE FUNCTION incriment(max integer) RETURNS CHAR as $$
DECLARE stat CHAR(1);
DECLARE na VARCHAR(40);
DECLARE join DATE;
DECLARE count integer;
DECLARE total integer;
DECLARE c refcursor;
BEGIN
        UPDATE Customer SET status = 'J' WHERE status = 'M';
        OPEN c FOR SELECT name, status, joinDate FROM Customer ORDER By status ASC, joinDate ASC;
        count = max;
        total = 0;
        WHILE count > 0 LOOP
                FETCH c INTO na, stat, join;
                return stat;
                count = count -1;
        END LOOP;
        CLOSE C;
        UPDATE Customer SET status = 'M' WHERE status = 'J';
END;
$$ LANGUAGE plpgsql;