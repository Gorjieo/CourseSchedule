//Gordon Straub + Andre Boodaghian + Adrian Holguin

#include <iostream>
#include <iomanip>
#include "Date.h"
#include <string>

using namespace std;

//constructor validates month and calls utility function to validate day
Date::Date(int mn, int dy, int yr)
{
	setDate(mn, dy, yr);
	//cout << "Date Constructor called for date: ";
	//print();
	//cout << endl;
}

Date& Date::setDate(int mn, int dy, int yr)
{
	if (mn > 0 && mn <= 12)
	{
		month = mn;
	}

	else
	{
		month = 1;
		cout << "Month set to one - INVALID" << endl;  //BAD DESIGN!
	}

	year = yr;  //could also validate year

	day = checkDay(dy);  //to validate the day

	//cout << endl;
	return *this;
}

Date& Date::setDay(int numDay) {
	day = numDay;
	return *this;
}

Date& Date::setMonth(int numMonth) {
	month = numMonth;
	return *this;
}

Date& Date::setYear(int numYear) {
	year = numYear;
	return *this;
}

int Date::getDay() const {
	return day;
}

int Date::getMonth() const {
	return month;
}

int Date::getYear() const {
	return year;
}

//PRIVATE COST UTILITY FUNCTION
int Date::checkDay(int testDay) const
{
	static const int daysPerMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	if (testDay > 0 && testDay <= daysPerMonth[month])
	{
		return testDay;
	}

	//determine whether testDay is valid for a specific month
	if (month == 2 && testDay == 29 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
	{
		return testDay;
	}

	cout << "Invalid Day " << testDay << " was set to 1" << endl;
	return 1;  //keep data in valid state
}

bool Date::operator<(const Date& toCompare) {
	if (getYear() < toCompare.getYear()) {
		return true;
	}
	if (year == toCompare.getYear()) {
		if (month < toCompare.getMonth()) {
			return true;
		}
		if (month == toCompare.getMonth()) {
			if (day < toCompare.getDay()) {
				return true;
			}
		}
	}
	return false;
}

//problem with this one fixed
bool Date::operator<=(const Date& toCompare) {
	if (getYear() < toCompare.getYear()) {
		return true;
	} if (year == toCompare.getYear()) {
		if (month < toCompare.getMonth()) {
			return true;
		} if (month == toCompare.getMonth()) {
			if (day <= toCompare.getDay()) {
				return true;
			}
		}
		
	}
	else {
		return false;
	}
	
}

bool Date::operator>(const Date& toCompare) {
	if (getYear() > toCompare.getYear()) {
		return true;
	}
	if (year == toCompare.getYear()) {
		if (month > toCompare.getMonth()) {
			return true;
		}
		if (month == toCompare.getMonth()) {
			if (day > toCompare.getDay()) {
				return true;
			}
		}
	}
	return false;
}

// problem with this one too, fixed
bool Date::operator>=(const Date& toCompare) {
	if (getYear() > toCompare.getYear()) {
		return true;
	}
	if (year == toCompare.getYear()) {
		if (month > toCompare.getMonth()) {
			return true;
		}
		if (month == toCompare.getMonth()) {
			if (day >= toCompare.getDay()) {
				return true;
			}
		}
	}
	else {
		return false;
	}
	
}

bool Date::operator==(const Date& toCompare) {
	if (getYear() == toCompare.getYear()) {
		if (getMonth() == toCompare.getYear()) {
			if (getDay() == toCompare.getYear()) {
				return true;
			}
		}
	}
	return false;
}

bool Date::operator!=(const Date& toCompare) {
	if (getYear() != toCompare.getYear()) {
		return true;
	}
	if (getMonth() != toCompare.getYear()) {
		return true;
	}
	if (getDay() != toCompare.getYear()) {
		return true;
	}
	return false;
}

ostream& operator<<(ostream& out, const Date& date) {
	out << date.getMonth() << '/' << date.getDay() << '/' << date.getYear();
	return out;
}

istream& operator>>(istream& in, Date& date) {
	string input;
	int m;
	int d;
	int y;

	getline(in, input);
	m = stoi(input.substr(0, input.find('/')));
	input = input.substr(input.find('/') + 1);
	d = stoi(input.substr(0, input.find('/')));
	input = input.substr(input.find('/') + 1);
	y = stoi(input);

	date.setDate(m, d, y);
	return in;
}