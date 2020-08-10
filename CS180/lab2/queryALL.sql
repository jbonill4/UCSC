SELECT DISTINCT name,address
FROM customer
WHERE status = 'H' AND RIGHT(name,1) = 'n';
/* name  |   address    
-------+--------------
 Gavin | 
 Kevin | 223 Baker St*/

SELECT DISTINCT name,description,price
FROM menuItem M, billEntry B
WHERE M.menuItemID = B.menuItemID AND B.quantity >=1;
/*    name    |     description     | price  
------------+---------------------+--------
 Ramen bowl | Something delicious | 232.23
 Hummus     |                     |   1.25
 Fried Rice | Something delicious |  14.25
 Rice bowl  | Something delicious |   2.23
 Pita Bread |                     |   4.25
 Foie Gras  | Something delicious | 112.23 
*/

SELECT V.custID, C.name
FROM customer C, visit V, visit R
WHERE V.custID = C.custID AND V.custID = R.custID --AND R.custArrive <> V.custArrive;
AND R.custArrive > '2018-12-18 08:00:00' AND
V.custArrive > '2018-12-18 08:00:00' AND R.custDepart < '2018-12-21 23:00:00' AND
V.custDepart < '2018-12-21 23:00:00'
GROUP BY V.custID, C.name
Having Count(*) > 1;
/*
 custid |      name      
--------+----------------
      2 | Shelock Holmes
      1 | Indiana Jones*/

/*SELECT DISTINCT V.custID, C.name
FROM customer C, visit V
WHERE V.custID = C.custID AND
V.custArrive > '2018-12-18 08:00:00' AND
V.custDepart < '2018-12-21 23:00:00'
GROUP BY V.custID, C.name
Having Count(*) > 1;*/

SELECT DISTINCT B.visitID, B.menuItemID, M.name, (M.price * B.quantity) as totalItemCost
FROM BillEntry B, menuItem M
WHERE B.menuItemID = M.menuItemID;
/*
 visitid | menuitemid |    name    | totalitemcost 
---------+------------+------------+---------------
       1 |          3 | Ramen bowl |        232.23
       2 |          2 | Rice bowl  |          2.23
       7 |          2 | Rice bowl  |          4.46
       8 |          5 | Pita Bread |          4.25
       5 |          5 | Pita Bread |         25.50
      10 |          3 | Ramen bowl |        232.23
       6 |          3 | Ramen bowl |        464.46
       5 |          4 | Fried Rice |         28.50
       3 |          4 | Fried Rice |         71.25
      10 |          4 | Fried Rice |         42.75
       4 |          2 | Rice bowl  |          4.46
       8 |          4 | Fried Rice |         14.25
      10 |          2 | Rice bowl  |          4.46
       2 |          3 | Ramen bowl |        232.23
       9 |          2 | Rice bowl  |          4.46
       5 |          6 | Hummus     |          2.50
       1 |          2 | Rice bowl  |          2.23
       2 |          1 | Foie Gras  |        224.46
       7 |          1 | Foie Gras  |        112.23
       6 |          2 | Rice bowl  |          2.23
       4 |          1 | Foie Gras  |        112.23
       1 |          1 | Foie Gras  |        224.46
       3 |          3 | Ramen bowl |        928.92
*/

SELECT DISTINCT V.visitID, C.name as custName, S.name as serverName
FROM customer C, visit V, server S, dinnerTable D
WHERE V.cost >= 200 AND D.numSeats = V.numPeople AND V.serverID = S.serverID
AND V.custID = C.custID AND S.level IS NOT NULL;
/*visitid | custname |   servername    
---------+----------+-----------------
       5 | Matthew  | Fred Flintstone
*/