DROP SCHEMA Lab1 CASCADE;
CREATE SCHEMA Lab1;

-- print out the current time

SELECT timeofday();

-- Create Tables

CREATE TABLE customer (
	custID INTEGER,
	name CHAR(40),
	address CHAR(40),
	joinDate DATE,
	status CHAR(1),
	PRIMARY KEY(custID)

--name VARCHAR(30),
--manf VARCHAR(50)
);

CREATE TABLE menuItem (
	menuItemID INTEGER,
	name CHAR(40),
	description CHAR(60),
	price NUMERIC(5,2),
	PRIMARY KEY(menuItemID)
--name VARCHAR(30),
--addr VARCHAR(50),
--license VARCHAR(50)
);

CREATE TABLE dinnerTable (
	dinnerTableID INTEGER,
	numSeats INTEGER,
	InUse boolean,
	PRIMARY KEY(dinnerTableID)

--bar VARCHAR(20),
--beer VARCHAR(30),
--price REAL
);

CREATE TABLE server (
	serverID INTEGER,
	name CHAR(40),
	level CHAR(1),
	salary NUMERIC(6,2),
	PRIMARY KEY(serverID)

--drinker VARCHAR(30),
--beer VARCHAR(30)
);

CREATE TABLE visit (
	visitID INTEGER,
	custID INTEGER,
	dinnerTableID INTEGER,
	serverID INTEGER,
	numPeople INTEGER,
	cost NUMERIC(6,2),
	custArrive TIMESTAMP,
	custDepart TIMESTAMP,
	PRIMARY KEY(visitID)

--name VARCHAR(30),
--addr VARCHAR(50),
--phone CHAR(16)
); 


CREATE TABLE billEntry (
	visitID INTEGER,
	menuItemID INTEGER,
	quantity INTEGER,
	PRIMARY KEY(visitID,menuItemID)

--drinker VARCHAR(30),
--bar VARCHAR(30)
);


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


