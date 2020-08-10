
SELECT V.custID, C.name
FROM customer C, visit V
WHERE V.custID = C.custID AND V.custArrive BETWEEN '2018-12-18 08:00:00' AND '2018-12-21 23:00:00'
GROUP BY V.custID, C.name
Having Count(*) > 1;
/*
 custid |      name      
--------+----------------
      2 | Shelock Holmes
      1 | Indiana Jones*/


