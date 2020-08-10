
SELECT DISTINCT name,address
FROM customer
WHERE status = 'H' AND RIGHT(name,1) = 'n';
/* name  |   address    
-------+--------------
 Gavin | 
 Kevin | 223 Baker St*/
