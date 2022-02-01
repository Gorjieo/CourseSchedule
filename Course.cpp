// Gordon Straub + Andre Boodaghian + Adrian Holguin

#include "Course.h"

Course::Course()
{
}

Course::Course(string courseNum, string courseName, string days, double units, Date startDate, Date endDate, Time startTime, Time endTime)
{
	this->setCourse(courseNum).setName(courseName).setDays(days).setUnits(units).setStartDate(startDate).setEndDate(endDate).setStartTime(startTime).setEndTime(endTime);
}

Course::~Course()
{
	//cout << "Course deleted.\n";
}

string Course::getCourse() const
{
	return courseNumber;
}

string Course::getCourseName() const
{
	return courseName;
}

string Course::getMeetingDays() const
{
	return meetingDays;
}

double Course::getUnits() const
{
	return units;
}

Date Course::getStartDate() const
{
	return startDate;
}

Date Course::getEndDate() const
{
	return endDate;
}

Time Course::getStartTime() const
{
	return startTime;
}

Time Course::getEndTime() const
{
	return endTime;
}

double Course::calcDailyDuration() const
{
	Time startT = getStartTime();
	Time endT = getEndTime();
	return (endT - startT);
}


ostream & operator<<(ostream &out, const Course &outputC)
{
	out << "Course Info:\t" << outputC.getCourse() << " -- " << outputC.getCourseName() << endl;
	out << "# of Units:\t" << outputC.getUnits() << endl;
	out << "Course Dates:\t" << outputC.getStartDate() << " - " << outputC.getEndDate() << endl;
	out << "Meeting Days:\t" << outputC.getMeetingDays() << endl;
	out << "Meeting Time:\t" << outputC.getStartTime() << " - " << outputC.getEndTime() << endl;
	
	out << setprecision(2) << fixed;
	out << "Daily Duration:\t" << outputC.calcDailyDuration() << " hours" << endl;
	return out;
}

Course & Course::setCourse(string course)
{
	this->courseNumber = course;
	return *this;
}

Course & Course::setName(string name)
{
	this->courseName = name;
	return *this;
}

Course & Course::setDays(string days)
{
	this->meetingDays = days;
	return *this;
}

Course & Course::setUnits(double units)
{
	this->units = units;
	return *this;
}

Course & Course::setStartDate(Date startDate)
{
	this->startDate = startDate;
	return *this;
}

Course & Course::setEndDate(Date endDate)
{
	this->endDate = endDate;
	return *this;
}

Course & Course::setStartTime(Time startTime)
{
	this->startTime = startTime;
	return *this;
}

Course & Course::setEndTime(Time endTime)
{
	this->endTime = endTime;
	return *this;
}