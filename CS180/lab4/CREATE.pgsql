
CREATE OR REPLACE Function reduceSomeCostsFunction()
returns integer as $$
DECLARE thePrice REAL;
DECLARE NotFound CONDITION FOR SQLSTATE '02000';
DECLARE c CURSOR FOR SELECT custID FROM Customer WHERE status = 'H';
BEGIN
OPEN c;
menuloop: LOOP
FETCH c INTO thePrice;
IF NotFound THEN LEAVE menuLoop END IF;
IF thePrice > 0 THEN
UPDATE Customer SET address = 'UrMomsHouse';
END IF;
END LOOP;
CLOSE C;
END;
$$ language plpgsql;


