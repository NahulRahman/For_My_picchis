
Create table Customer
(
	Cust_id 	VARCHAR2(12)  NOT NULL,
	Cust_name	VARCHAR2(12),
	Cust_dob	DATE,
	Cust_street	VARCHAR2(12),
	Cust_city	VARCHAR2(12)
);

Create table Account
(
	Account_id 	VARCHAR2(12)  NOT NULL,
	Balance		NUMBER(20,5),
	Type		VARCHAR2(8)
);

Create table Depositor
(
	Cust_id 	VARCHAR2(12)  NOT NULL,
	Account_id	 VARCHAR2(12) NOT NULL
);

Create table Employee
(
	Employee_id	VARCHAR2(12),
	Employee_name	VARCHAR2(20),
	Employee_dob	DATE,
	Employee_street	VARCHAR2(20),
	Employee_city	VARCHAR2(20),
	Employee_startdate DATE,
	Salary		NUMBER(10,3),
	MGR		VARCHAR2(12)
);

Create table SALGRADE
(
	GRADE	VARCHAR2(5)  NOT NULL,
	LOSAL	NUMBER(10,3),
	HISAL	NUMBER(10,3)	
);
