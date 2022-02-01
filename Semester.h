// Gordon Straub + Andre Boodaghian + Adrian Holguin

#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
#include<iomanip>
#include "Time.h"
#include "Date.h"

class Semester
{

	friend istream &operator>>(istream&, Semester&);
	friend ostream &operator<<(ostream&, const Semester&);

public:
	Semester(string s = string(), Date sD = Date(), Date eD = Date());
	~Semester();

	string getSemesterName() const;
	Date getSemesterStartDate() const;
	Date getSemesterEndDate() const;

private:
	string semesterName;
	Date semesterStartDate;
	Date semesterEndDate;

	Semester& setSemesterName(string);
	Semester& setSemesterStartDate(Date);
	Semester& setSemesterEndDate(Date);

};

//Semester
//Import Date
//
//Variables
//- string semesterName
//- date semesterStartDate
//- date semesterEndDate
//
//Methods
//+ Constructor(string, date, date);
//+operator <<
////(outputs semester name + dates like this “Semester: Fall 2019 (09/03/2019-12/12/2019)”)
//+operator >> accept input for semester name, start date, and end date
//+ get and sets
