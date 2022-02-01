//Gordon Straub + Andre Boodaghian + Adrian Holguin

#include <iostream>
#include <iomanip>    
#include <string> 
#include "CourseSchedule.h" 
#include "Course.h"
#include "Date.h"
#include "Semester.h"
#include "Time.h" 
using namespace std;

void displayMenu(CourseSchedule&);

void displayMenu(CourseSchedule& schedule)
{
	string userChoice = "0";
	bool quit = false;
	string courseNumber;
	string courseName;
	string courseMeetingDays;
	int units;
	string unitString;
	Date startDate;
	Date endDate;
	Time startTime;
	Time endTime;
	Course c;
	bool dateInput;

	while (!quit)
	{
		cout << "COURSE ENTRY MENU FOR:\t" << schedule.getSemester() << endl;
		cout << "----------------------------------------------------------\n1) Enter a new course\n2) Remove a course \n3) Print Semester Schedule\nq) Quit the program" << endl;
		userChoice = "";
		cin >> userChoice;
		cin.ignore();
		dateInput = false;

		switch (userChoice[0])
		{

		case '1':
			cout << "Input course number: " << endl;
			getline(cin, courseNumber);
			cout << "Enter the course's name: " << endl;
			getline(cin, courseName);
			cout << "Enter meeting days: " << endl;
			getline(cin, courseMeetingDays);
			cout << "Enter the number of units: " << endl;
			getline(cin, unitString);
			units = stoi(unitString);
			
			while (!dateInput) {
				cout << "Enter start date MM/DD/YYYY" << endl;
				cin >> startDate;
				cout << "Enter end date MM/DD/YYYY" << endl;
				cin >> endDate;
				if (startDate > endDate) {
					cout << "Invalid date. The start date occurrs after the end date." << endl;
				}
				else {
					dateInput = true;
				}
			}

			cout << "Enter start time HH:MM AM or PM" << endl;
			cin >> startTime;
			cout << "Enter end time HH:MM AM or PM" << endl;
			cin >> endTime;

			schedule.addCourse(Course(courseNumber, courseName, courseMeetingDays, units, startDate, endDate, startTime, endTime));
			break;

		case '2':
			schedule.removeCourse();
			break;

		case '3':
			cout << schedule;
			break;

		case 'Q':
			quit = true;
			break;

		case 'q':
			quit = true;
			break;


		default:
			cout << "Incorrect input, please enter 1, 2, 3 or q." << endl;
			break;

		}
	}
}

int main()
{
	string user;
	int max;
	Semester s;

	cout << "Please enter your name:\n";
	getline(cin, user);
	cin >> s;

	cout << "Please enter the maximum number of classes: " << endl;
	cin >> max;

	CourseSchedule schedule(user, s, max);
	displayMenu(schedule);

}