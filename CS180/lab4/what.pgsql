DROP FUNCTION reducesomecostsfunction(integer);

CREATE OR REPLACE FUNCTION reduceSomeCostsFunction(max integer)
RETURNS TABLE(n varchar, sta CHAR(1), tim DATE) as $$
DECLARE stat CHAR(1);
DECLARE na VARCHAR(40);
DECLARE join DATE;
DECLARE count integer;
DECLARE c CURSOR FOR (SELECT name, status, joinDate FROM Customer ORDER By status ASC, joinDate ASC);
BEGIN
	UPDATE Customer SET status = 'J' WHERE status = 'M';
	count = max;
	OPEN c;
	WHILE count > 0 
	LOOP
		FETCH c INTO na, stat, join;
	END LOOP;
	CLOSE c;
	UPDATE Customer SET status = 'M' WHERE status = 'J';
	RETURN QUERY SELECT C.name, C.status, C.joinDate FROM Customer C ORDER By C.status ASC, C.joinDate ASC);
	
END;
$$ LANGUAGE plpgsql;
