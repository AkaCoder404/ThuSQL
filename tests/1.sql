CREATE DATABASE db;
SHOW DATABASE db;
CREATE DATABASE db1;
CREATE DATABASE db2; 
CREATE DATABASE db3;
USE db;
CREATE TABLE Persons ( 
	ID INT NOT NULL, 
	Age INT DEFAULT 1, 
	Height INT DEFAULT NULL, 
	Grade FLOAT DEFAULT 100.00,  
	LastName VARCHAR(20) DEFAULT 'lastname', 
	FirstName VARCHAR(20) DEFAULT 'firstname',
	PRIMARY KEY (ID)
);
CREATE TABLE Ident (
    ID INT,
    Key VARCHAR(32)
);
SHOW DATABASE db;


DESC Persons;
DESC Ident;
INSERT INTO Persons VALUES 
	(420, 69, 12, 1.0, 'It', 'Blaze'), 
	(69, 420, 12, 0.0, 'Stupid', 'Very'),
	(100, 100, 100, 100, 'Is', 'Not', 'Allowed'),
	('number', 100, 100, 100, 'Inorrect', 'Type'),
	(100, 69, 12, 1.0, 'It', '0123456789012345678');
INSERT INTO Ident VALUES 
	(1, 'keys');

SELECT * FROM Persons;
SELECT LastName, FirstName, Grade FROM Persons;

SHOW DATABASE db;

