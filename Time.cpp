//Gordon Straub + Andre Boodaghian + Adrian Holguin

#include <iostream>
#include <iomanip>
#include <string>
#include "Time.h"

using namespace std;

Time::Time(int hour, int minute)
{
	setTime(hour, minute);
}

Time& Time::setTime(int hour, int minute)
{
	setHour(hour);
	setMinute(minute);
	return *this;
}

//setHour function is now set up to enable cascading
Time& Time::setHour(int h)
{
	hour = (h >= 0 && h <= 23) ? h : 12;  //validates hour, if valid set to h, else set to 0
	return *this;
}

//setMinute function is now set up to enable cascading
Time& Time::setMinute(int m)
{
	minute = (m >= 0 && m < 60) ? m : 0;  //validates minute, if valid set to m, else set to 0
	return *this;
}

int Time::getHour() const  //must be const since prototype is const
{
	return hour;
}

//get Minute
int Time::getMinute() const  //must be const since prototype is const
{
	return minute;
}

/*PRINT FUNCTIONS:  Normally do not modify private member data so should be const*/
void Time::printUniversal()const  
{
	cout << setfill('0') << setw(2) << hour << ":"
		<< setw(2) << minute << endl;
}

void Time::printStandard()const  //must be const since prototype is const
{
	cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
		<< setfill('0') << setw(2) << minute << ":"
		<< (hour < 12 ? "AM" : "PM") << endl;

}

ostream& operator<<(ostream& out, const Time& time) 

{
	cout << ((time.getHour() == 0 || time.getHour() == 12) ? 12 : time.getHour() % 12) << ":"
		<< setfill('0') << setw(2) << time.getMinute() << " "
		<< (time.getHour() < 12 ? "AM" : "PM");

	return out;

}

istream& operator>>(istream& in, Time &sTime)        

{
	Time newTime;
	string stringTime;
	getline(in, stringTime);

	newTime = newTime.convertTime(stringTime);

	if (newTime.getHour() < 0 || newTime.getHour() > 24)
	{
		newTime.setHour(12);
		cout << "Bad input, hour set to 12. " << endl;
	}

	if (newTime.getMinute() < 0 || newTime.getMinute() > 59)
	{
		newTime.setMinute(0);
		cout << "Bad input, min set to 0. " << endl;
	}

	sTime.setTime(newTime.getHour(), newTime.getMinute());

	return in;

}

// Convert Standard to Universal
Time Time::convertTime(string standard)
{
	string tempString = standard;
	Time tempTime;
	int _h = stoi(tempString.substr(0, tempString.find(':')));
	tempString = tempString.substr(tempString.find(':') + 1);
	int _m = stoi(tempString.substr(0, tempString.find(' ')));
	tempString = tempString.substr(tempString.find(' ') + 1);

	tempString[0] = toupper(tempString[0]);
	tempString[1] = toupper(tempString[1]);

	if (tempString == "PM") {
		if (_h < 12) {
			_h = _h + 12;
		}
	}
	if (tempString == "AM") {
		if (_h == 12) {
			_h = 0;
		}
	}

	tempTime.setTime(_h, _m);
	return tempTime;
}

double Time::operator-(Time& time2)         

{
	//print test numbers commented out
	double minutes1 = (double(getHour()) * 60.0) + double(getMinute());
	//cout << minutes1 << endl;
	double minutes2 = (double(time2.getHour()) * 60.0) + double(time2.getMinute());
	//cout << minutes2 << endl;
	double timeF = minutes1 - minutes2;
	if (timeF < 0) {
		timeF = 1440 + timeF;
	}
	//cout << timeF << endl;
	double result = timeF / 60.0;
	return result;

}
