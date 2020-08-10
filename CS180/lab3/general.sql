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
CHECK(custArrive <= custDepart)
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
