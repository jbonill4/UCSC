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