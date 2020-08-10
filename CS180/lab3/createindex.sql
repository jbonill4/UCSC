--An index on an attribute of a relation is a data structure that allows the 
--database system to find those tuples in the relation that have a specified value 
--for that attribute efficiently, without scanning through all the tuples of the relation.
--CREATE INDEX <name> ON <relation-name> (attributes);
CREATE INDEX LookUpBillItems ON BillEntry(menuItemID,quantity);

SELECT menuItemID, quantity
FROM BillEntry;