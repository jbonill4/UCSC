CREATE VIEW name AS
(SELECT C.name AS CustomerName
FROM Customer C, Visit V
WHERE C.custID = V.custID
GROUP BY name
HAVING COUNT(*) >= 3);

--prints out customer names,visitID, and COST. ONLY if ID's match
SELECT DISTINCT V.visitID, C.name as CustomerNAME, V.cost AS cost, W.totalItemCost 
FROM VISIT V, Customer C, costView W
WHERE V.custID = C.custID 
AND C.name IN (SELECT CustomerName FROM name) 
AND V.visitId = W.VISIT 
AND V.cost <> W.totalItemCost;


DELETE FROM billEntry
WHERE visitID = 10 AND menuItemID = 3;


DELETE FROM billEntry
WHERE visitID = 2 AND menuItemID = 1;


SELECT DISTINCT V.visitID, C.name as CustomerNAME, V.cost AS cost, W.totalItemCost 
FROM VISIT V, Customer C, costView W
WHERE V.custID = C.custID 
AND C.name IN (SELECT CustomerName FROM name) 
AND V.visitId = W.VISIT 
AND V.cost <> W.totalItemCost;
