-- Sample Script file to Populate a BEERS DB
-- print out the current time
SELECT timeofday();
-- Populate the tables
COPY customer FROM stdin USING DELIMITERS '|';
1|Indiana Jones|USA|1973-04-22|R
2|Shelock Holmes|221 Baker St|1895-04-22|O
\.

COPY menuItem FROM stdin USING DELIMITERS '|';
1|Foie Gras|Something delicious| 112.23
2|Rice bowl|Something delicious| 2.23
3|Ramen bowl|Something delicious| 232.23
\.

COPY dinnerTable FROM stdin USING DELIMITERS '|';
1|4|False
2|8|True
3|2|T
4|8|F
\.

COPY server FROM stdin USING DELIMITERS '|';
1|Bill Jones|L|4322.22
2|Kelly Arthu|U|322.22
3|Fred Flintstone|U|522.22
\.

COPY visit FROM stdin USING DELIMITERS '|';
1|1|1|1|3|950.00|'1970-01-01 00:00:01' UTC | '1970-01-01 00:09:01' UTC
\.

COPY billEntry FROM stdin USING DELIMITERS '|';
1|1|2
1|2|1
1|3|1
\.

SELECT * FROM customer;
SELECT * FROM menuItem;
SELECT * FROM dinnerTable;
SELECT * FROM server;
SELECT * FROM visit;
SELECT * FROM BillEntry;
-- print out the current time
SELECT timeofday();
