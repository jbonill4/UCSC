
--SERVER ERROR
INSERT INTO visit 
VALUES (22,1,1,1,3,950.00,'2018-12-20 08:09:15', '2018-12-20 09:09:01');

--DINNERTABLEID ERROR
INSERT INTO visit 
VALUES (21,1,44,2,3,950.00,'2018-12-20 08:10:15', '2018-12-20 09:09:01');


--CUSTID ERROR
INSERT INTO visit 
VALUES (20,33,44,2,3,950.00,'2018-12-20 08:11:15', '2018-12-20 09:09:01');

---------------------------------------------------------------------

--DINNERTABLEID MEET CONSTRAINT
UPDATE visit
SET numPeople = 44, dinnerTableID = 2
WHERE visit.visitID = 3;

--DINNERTABLEID NO MEET CONSTRAINT
UPDATE visit
SET numPeople = 44, dinnerTableID = 9
WHERE visit.visitID = 3;

---------------------------------------------------------------------

--SERVERID MEET CONSTRAINT
UPDATE visit
SET numPeople = 22, serverID = 3
WHERE visit.visitID = 6;

--SERVERID NO MEET CONSTRAINT
UPDATE visit
SET numPeople = 22, serverID = 99
WHERE visit.visitID = 6;

---------------------------------------------------------------------

--CUSTID MEET CONSTRAINT
UPDATE visit
SET numPeople = 88, custID = 3
WHERE visit.visitID = 4;

--CUSTID NO MEET CONSTRAINT
UPDATE visit
SET numPeople = 88, custID = 600
WHERE visit.visitID = 4;

---------------------------------------------------------------------

