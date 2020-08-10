--New goals for Lab3:
--1. Perform SQL to “combine data” from two tables
--2. Add foreign key constraints
--3. Add general constraints
--4. Write unit tests for constraints
--5. Create and query a view
--6. Create an index

/*
Note that in both foreign.sql and general.sql, you're told to add the 
constraints to the tables created by lab3_create.sql.  So you should 
add these constraints to the tables created by lab3_create.sql, not 
rewrite the create table statements that are in lab3_create.sql - FINKLESTEIN


Important: Before running Sections 2.3, 2.4 and 2.5, recreate the Lab3 schema 
using the lab3_create.sql script, and load the data using the script lab3_data_loading.sql. 
That way, any database changes that you’ve done for Combine won’t propagate to 
these other parts of Lab3.

MY INTERPRETATION OF THIS IS THAT I 'ADD THESE CONSTRAINTS' TO THE TABLES
BY COPYING OVER THE LAB3_CREATE.SQL I AM NOT REWRITING IM AM JUST ADDING
THE CONSTRAINTS AS STATED ABOVE I HAVE WRITTEN AN ALTERNATIVE THAT COMPLETES
THE SAME TASK BELOW
*/


/*
ALTER TABLE Visit
ADD FOREIGN KEY (dinnerTableID) REFERENCES DinnerTable(dinnerTableID);

ALTER TABLE Visit
ADD FOREIGN KEY (custID) REFERENCES Customer(custID)
ON DELETE CASCADE;

ALTER TABLE Visit
ADD FOREIGN KEY (serverID) REFERENCES Server(serverID)
ON UPDATE CASCADE
ON DELETE SET NULL;
*/


DROP SCHEMA Lab3 CASCADE;
CREATE SCHEMA Lab3;

-- Create Tables
CREATE TABLE Customer (
custID INT,
name VARCHAR(40) NOT NULL,
address VARCHAR(40),
joinDate DATE,
status CHAR(1),
PRIMARY KEY (custID),
UNIQUE (name, address)
);

CREATE TABLE MenuItem (
menuItemID INT,
name VARCHAR(40) NOT NULL,
description VARCHAR(60),
price NUMERIC (5,2),
PRIMARY KEY (menuItemID),
UNIQUE(name),
CONSTRAINT positive_price CHECK(price >= 0)
);

CREATE TABLE DinnerTable (
dinnerTableID INT,
numSeats INT NOT NULL,
inUse BOOLEAN,
PRIMARY KEY (dinnerTableID),
CHECK((inUse IS NOT NULL AND numSeats > 0) OR
(inUse IS NULL))
);

CREATE TABLE Server (
serverID INT,
name VARCHAR (40),
level CHAR (1),
salary NUMERIC(6,2),
PRIMARY KEY (serverID)
);

CREATE TABLE Visit (
visitID INT,
custID INT REFERENCES Customer(custID)
ON DELETE CASCADE,
dinnerTableID INT REFERENCES DinnerTable(dinnerTableID),
serverID INT REFERENCES Server(serverID)
ON UPDATE CASCADE
ON DELETE SET NULL,
numPeople INT, 
cost NUMERIC (6,2),
custArrive TIMESTAMP,
custDepart TIMESTAMP,
PRIMARY KEY (visitID),
UNIQUE(custID, custArrive),
CHECK(custArrive < custDepart)
);

CREATE TABLE BillEntry (
visitID INT,
menuItemID INT,
quantity INT,
PRIMARY KEY (visitID, menuItemID),
FOREIGN KEY (visitID) REFERENCES Visit,
FOREIGN KEY (menuItemID) REFERENCES MenuItem
);

CREATE TABLE ModifyVisit (
visitID INT,
custID INT,
dinnerTableID INT,
serverID INT,
numPeople INT, 
PRIMARY KEY (visitID)
);

