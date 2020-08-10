
CREATE OR REPLACE FUNCTION reduceSomeCostsFunction(max integer) RETURNS integer as $$
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
		IF stat = 'H' THEN
			UPDATE Visit V SET cost = cost*0.9 WHERE V.custID IN (SELECT C.custID FROM Customer C WHERE C.status = stat AND C.custID = V.custID AND name = na) AND cost IS NOT NULL;
			total = total + 1;
		ELSIF stat = 'J' THEN
			UPDATE Visit V SET cost = cost*0.95 WHERE V.custID IN (SELECT C.custID FROM Customer C WHERE C.status = stat AND C.custID = V.custID AND name = na) AND cost IS NOT NULL;
			total = total + 1;
		ELSIF stat = 'L' THEN
			UPDATE Visit V SET cost = cost*0.99 WHERE V.custID IN (SELECT C.custID FROM Customer C WHERE C.status = stat AND C.custID = V.custID AND name = na) AND cost IS NOT NULL;
			total = total + 1;
		ELSIF stat = 'null' THEN
		ELSE	
		END IF;
		count = count-1;
	END LOOP;
	CLOSE C;
	UPDATE Customer SET status = 'M' WHERE status = 'J';
	RETURN total;
END;
$$ LANGUAGE plpgsql;
