SELECT C.name, C.status, C.joinDate, V.cost, C.custID
FROM Customer C, Visit V
WHERE C.custID = V.custID
ORDER By status ASC, joinDate ASC, custID ASC;