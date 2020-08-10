

SELECT DISTINCT V.visitID, C.name as custName, S.name as serverName
FROM customer C, visit V, server S, dinnerTable D
WHERE V.cost >= 200 
AND D.numSeats = V.numPeople 
AND V.serverID = S.serverID
AND V.custID = C.custID 
AND S.level IS NOT NULL
AND V.dinnerTableID = D.dinnerTableID;
/*visitid | custname |   servername    
---------+----------+-----------------
       5 | Matthew  | Fred Flintstone
*/