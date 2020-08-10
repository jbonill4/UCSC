CREATE VIEW costView AS
(SELECT DISTINCT V.visitID AS VISIT, SUM(M.price * B.quantity) as totalItemCost
FROM BillEntry B, menuItem M, visit V
WHERE B.menuItemID = M.menuItemID AND B.visitID = V.visitID 
GROUP BY V.visitID
UNION
SELECT DISTINCT V.visitID AS VISIT, 0 as totalItemCost
FROM visit V
WHERE V.visitID NOT IN (SELECT BILL.visitID FROM BillEntry BILL));