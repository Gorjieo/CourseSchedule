// Gordon Straub + Andre Boodaghian + Adrian Holguin

#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
#include<iomanip>
#include "Time.h"
#include "Date.h"

using namespace std;

class Course
{

	friend ostream &operator<<(ostream&, const Course&);

public:

	Course();
	Course(string, string, string, double, Date, Date, Time, Time);
	~Course();
	
	string getCourse() const;
	string getCourseName() const;
	string getMeetingDays() const;
	double getUnits() const;
	Date getStartDate() const;
	Date getEndDate() const;
	Time getStartTime() const;
	Time getEndTime() const;

	double calcDailyDuration() const;

	static enum DayOfWeek
	{
		Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday
	};

private:
	string courseNumber;
	string courseName;
	string meetingDays;
	double units;
	Date startDate;
	Date endDate;
	Time startTime;
	Time endTime;

	Course& setCourse(string);
	Course& setName(string);
	Course& setDays(string);
	Course& setUnits(double);
	Course& setStartDate(Date);
	Course& setEndDate(Date);
	Course& setStartTime(Time);
	Course& setEndTime(Time);


};

//Course
//Import date
//Import time
//
//Variables
//- String courseNumber
//- string courseName
//- string meetingDays(string of numbers separated by commas, corresponds to enumerated type.Allows for multiple days.Don’t want to use array for this so class can use memberwise assignment)
//- double units
//- Date startDate
//- Date endDate
//- Time startTime
//- Time endTime
//Static Enum dayOfWeek{ 1 = Sunday, 2 = Monday, etc… }
//
//Functions
//+ Constructor()
//+ Constructor(string, string, string, double, date, date, time, time);
////constructor should be a single statement of cascading calls
//
//+Course setCourse(string);
//+Course setName(string);
//+Course setDays(string);
//+Course setUnits(double);
//+Course setStartDate(date);
//+Course setEndDate(date);
//+Course setStartTime(time);
//+Course setEndTime(time);
//
//+get functions
//
//+ double(? ) calcDailyDuration();
////use overloaded +/- time operators
//
//+operator <<
////display like the picture, use overloaded << operators from date and time class
//+Destructor()~
////display “course has been deleted”