// Gordon Straub + Andre Boodaghian + Adrian Holguin

#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
using namespace std;

class Time
{
	friend istream &operator>>(istream&, Time&); //Step #4
	friend ostream &operator<<(ostream&, const Time&);       //Step #3
	   //Step #5

private:
	int hour;  //0-23 (24 hour clock format)
	int minute; //0-59

	Time convertTime(string);

public:
	//default constructor
	Time(int = 0, int = 0);

	//set functions - not const since they modify private data
	//The & return type enables cascading
	Time& setTime(int, int);
	Time& setHour(int);
	Time& setMinute(int);

	int getHour() const;
	int getMinute() const;

	//print functions declared const since they do not modify members
	void printUniversal() const;
	void printStandard()const;


	double operator-(Time&);
};

#endif