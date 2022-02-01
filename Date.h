// Gordon Straub + Andre Boodaghian + Adrian Holguin

#ifndef DATE_H
#define DATE_H

#include<iostream>
#include<iomanip>
#include <string>

using namespace std;

class Date
{

	friend istream &operator>>(istream&, Date&);
	friend ostream &operator<<(ostream&, const Date&);

private:
	int month; //1-12
	int day; //1-31 depending on month
	int year; //any year

	//utility function to check if day is proper for month and year
	int checkDay(int) const;

public:
	Date(int = 1, int = 1, int = 1990);
	Date& setDate(int, int, int);
	Date& setMonth(int);
	Date& setDay(int);
	Date& setYear(int);
	int getMonth()const;
	int getDay()const;
	int getYear()const;

	bool operator< (const Date&);
	bool operator> (const Date&);
	bool operator>= (const Date&);
	bool operator<= (const Date&);
	bool operator== (const Date&);
	bool operator!= (const Date&);
};

#endif