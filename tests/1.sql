<<<<<<< HEAD
SHOW DATABASES;
DROP DATABASE db;

CREATE DATABASE db;
SHOW DATABASE db;

USE db;
CREATE TABLE Classes (
	Class_ID INT NOT NULL
);

CREATE TABLE Persons ( 
	ID INT NOT NULL, 
	Age INT DEFAULT 1, 
	Height INT DEFAULT NULL, 
	Mass INT,
	Grade FLOAT DEFAULT 100.00,  
	LastName VARCHAR(20) DEFAULT 'lastname', 
	FirstName VARCHAR(20) DEFAULT 'firstname',
	PRIMARY KEY (ID, AGE),
	FOREIGN KEY (Class) REFERENCES Classes(Class_ID)
);

SHOW TABLES;
SHOW DATABASE db;
DESC Persons;

INSERT INTO Persons VALUES 
	(420, 69, 12, 100, 99.0, 'It', 'Blaze'), 
	(69, 420, 12, 101, 69.0, 'Stupid', 'Very'),
	(69, 420, 12, 102, 49.99, 'Gay', 'Big'),
	(69, 420, 12, 103, 30.99, 'Balls', 'Ligma'),
	(100, 100, 100, 100, 'Is', 'Not', 'Allowed'),
	('number', 100, 100, 100, 100, 'Inorrect', 'Type'),
	(100, 69, 12, 1.0, 1, 1, 'It', '0123456789012345678');

SELECT * FROM Persons;
SELECT LastName, FirstName, Grade FROM Persons;
SELECT * FROM Persons WHERE Grade >= 50.0;
SELECT * FROM Persons WHERE Grade <= 50.0 AND FirstName = 'Big';
UPDATE Persons SET FirstName = 'Smart', LastName = 'Student' WHERE Grade >= 90.0;
DELETE FROM Persons WHERE Grade <= 50;



SELECT * FROM Persons;

=======
SHOW DATABASES;
DROP DATABASE db;

CREATE DATABASE db;
SHOW DATABASE db;

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

SHOW TABLES;


SHOW DATABASE db;
 
DESC Persons;

INSERT INTO Persons VALUES 
	(420, 69, 12, 99.0, 'It', 'Blaze'), 
	(69, 420, 12, 69.0, 'Stupid', 'Very'),
	(69, 420, 12, 49.99, 'Gay', 'Big'),
	(69, 420, 12, 30.99, 'Balls', 'Ligma'),
	(100, 100, 100, 100, 'Is', 'Not', 'Allowed'),
	('number', 100, 100, 100, 'Inorrect', 'Type'),
	(100, 69, 12, 1.0, 'It', '0123456789012345678');

SELECT * FROM Persons;
SELECT LastName, FirstName, Grade FROM Persons;
SELECT * FROM Persons WHERE Grade >= 50.0;
SELECT * FROM Persons WHERE Grade <= 50.0 AND FirstName = 'Big';


DELETE FROM Persons WHERE Grade <= 50;

UPDATE Persons SET FirstName = 'Smart', LastName = 'Student' WHERE Grade >= 90.0;

SELECT * FROM Persons;


>>>>>>> update
