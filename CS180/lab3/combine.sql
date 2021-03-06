
SELECT *
FROM visit;

UPDATE visit
SET custID = N.custID, dinnerTableID = N.dinnerTableID,
serverID = N.serverID, numPeople = N.numPeople
FROM modifyVisit N
WHERE N.visitID = visit.visitID;
/*
 visitid | custid | dinnertableid | serverid | numpeople |  cost   |     custarrive      |     custdepart      
---------+--------+---------------+----------+-----------+---------+---------------------+---------------------
       2 |      1 |             2 |        2 |         4 |  950.00 | 2018-12-20 09:13:01 | 2018-12-20 10:13:01
       3 |      2 |             4 |        3 |         5 |  950.00 | 2018-12-20 12:13:01 | 2018-12-20 14:13:01
       5 |      5 |             5 |        3 |        12 | 1553.00 |                     | 
       7 |      2 |             4 |        3 |         8 |  150.00 | 2018-12-19 12:13:01 | 2018-12-19 14:13:01
       8 |      2 |             4 |        3 |         7 |  228.00 | 2018-12-18 11:13:01 | 2018-12-18 12:13:01
       9 |      3 |             4 |        3 |         6 |   45.00 | 2018-12-18 08:13:01 | 2018-12-18 09:13:01
      11 |      1 |             2 |        3 |         3 |  950.00 | 2018-12-19 17:08:15 | 2018-12-19 18:09:01
      10 |      1 |             2 |        4 |         6 |  134.00 | 2018-12-18 07:13:01 | 2018-12-18 09:13:01
       1 |      2 |             4 |        3 |         8 |  950.00 | 2018-12-20 08:08:15 | 2018-12-20 09:09:01
       6 |     10 |             5 |        1 |         6 |   53.00 |                     | 2019-05-20 15:30:01
       4 |      6 |             3 |        4 |         7 |  259.00 | 2019-02-20 11:23:01 | 2019-02-20 13:00:01
*/

INSERT INTO visit 
SELECT M.visitID, M.custID, M.dinnerTableID, M.serverID,M.numPeople, null, CURRENT_TIMESTAMP, null
FROM modifyVisit M
WHERE M.visitID NOT IN (SELECT visitID FROM visit);
/*
 visitid | custid | dinnertableid | serverid | numpeople |  cost   |        custarrive         |     custdepart      
---------+--------+---------------+----------+-----------+---------+---------------------------+---------------------
       2 |      1 |             2 |        2 |         4 |  950.00 | 2018-12-20 09:13:01       | 2018-12-20 10:13:01
       3 |      2 |             4 |        3 |         5 |  950.00 | 2018-12-20 12:13:01       | 2018-12-20 14:13:01
       5 |      5 |             5 |        3 |        12 | 1553.00 |                           | 
       7 |      2 |             4 |        3 |         8 |  150.00 | 2018-12-19 12:13:01       | 2018-12-19 14:13:01
       8 |      2 |             4 |        3 |         7 |  228.00 | 2018-12-18 11:13:01       | 2018-12-18 12:13:01
       9 |      3 |             4 |        3 |         6 |   45.00 | 2018-12-18 08:13:01       | 2018-12-18 09:13:01
      11 |      1 |             2 |        3 |         3 |  950.00 | 2018-12-19 17:08:15       | 2018-12-19 18:09:01
      10 |      1 |             2 |        4 |         6 |  134.00 | 2018-12-18 07:13:01       | 2018-12-18 09:13:01
       1 |      2 |             4 |        3 |         8 |  950.00 | 2018-12-20 08:08:15       | 2018-12-20 09:09:01
       6 |     10 |             5 |        1 |         6 |   53.00 |                           | 2019-05-20 15:30:01
       4 |      6 |             3 |        4 |         7 |  259.00 | 2019-02-20 11:23:01       | 2019-02-20 13:00:01
      12 |      9 |             3 |        2 |         2 |         | 2019-11-15 16:23:05.30835 | 
      13 |      4 |             7 |        5 |        13 |         | 2019-11-15 16:23:05.30835 | 
*/

SELECT *
FROM visit;

/*SELECT *
FROM modifyVisit;*/