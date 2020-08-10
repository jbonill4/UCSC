
SELECT DISTINCT name as theName ,description theDescription ,price thePrice
FROM menuItem M, billEntry B
WHERE M.menuItemID = B.menuItemID;
/*    name    |     description     | price  
------------+---------------------+--------
 Ramen bowl | Something delicious | 232.23
 Hummus     |                     |   1.25
 Fried Rice | Something delicious |  14.25
 Rice bowl  | Something delicious |   2.23
 Pita Bread |                     |   4.25
 Foie Gras  | Something delicious | 112.23 
*/