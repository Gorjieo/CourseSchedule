// Gordon Straub + Andre Boodaghian + Adrian Holguin

#include "CourseSchedule.h"

//pauses execution to check for memory leaks
CourseSchedule::~CourseSchedule()
{
	delete[] courses;
	cout << "Courses have been deleted\n";
	//system("PAUSE");
}

CourseSchedule::CourseSchedule(string name, Semester sem, int maxCourses)
{
	setStudentName(name);
	semester = sem;
	maxSize = maxCourses;
	numCourses = 0;
	courses = { new Course[maxSize] };
}

CourseSchedule::CourseSchedule(CourseSchedule &copy)
{
	setStudentName(copy.getStudentName());
	semester = copy.getSemester();
	maxSize = copy.maxSize;
	numCourses = copy.getNumCourses();
	courses = { new Course[maxSize] };
	for (int i = 0; i < numCourses; i++) {
		*(courses + i) = *(copy.courses + i);
	}
}

void CourseSchedule::setStudentName(string n)
{
	studentName = n;
}

string CourseSchedule::getStudentName() const
{
	return studentName;
}

Semester CourseSchedule::getSemester() const
{
	return semester;
}

int CourseSchedule::getNumCourses() const
{
	return numCourses;
}

void CourseSchedule::addCourse(Course c)
{
	if (c.getStartDate() > c.getEndDate()) {
		cout << "Course add failed. The start date occurs before the end date." << endl;
		return;
	}
	else if (numCourses >= maxSize) {
		cout << "Course add failed. The maximum number of courses has already been reached. Please remove a course and try again." << endl;
		return;
	}
	else if (!checkDates(getSemester(), c.getStartDate(), c.getEndDate())) {
		cout << "Course add failed. The course's start or end date falls outside the current semester. Please add a different course." << endl;
		return;
	}
	else {
		*(courses + (numCourses)) = c;
		++numCourses;
		cout << "Course added successfully." << endl;
		return;
	}
}

void CourseSchedule::removeCourse()
{
	int userInput = 0;

	while (userInput != -1) {
		for (int i = 0; i < numCourses; i++) {
			cout << "Enter " << i << " to delete: " << ((courses + i)->getCourseName()) << endl;
		}

		cout << "Which course would you like to remove? You can remove multiple courses, one at a time.\nEnter the number next to the course, or -1 to exit." << endl;
		cin >> userInput;

		//bounds check
		while (userInput < -1 || userInput > numCourses) {
			cout << "Out of bounds. Please enter the number next to the course you want to delete, or -1 to exit." << endl;
			cin >> userInput;
		}

		if (userInput > -1) {
			swap(userInput);
			cout << "Course removed." << endl;
		}
	}
}

bool CourseSchedule::checkDates(Semester currentSem, Date startDate, Date endDate)
{
	
	if (currentSem.getSemesterStartDate() > endDate || currentSem.getSemesterEndDate() < startDate) {
		return false;
	}
		
	if (currentSem.getSemesterStartDate() <= startDate && currentSem.getSemesterEndDate() >= endDate) {
		return true;
	}
	else {
		return false;
	}

}

void CourseSchedule::swap(int index)
{
	//if final element is to be removed it will only reduce number of courses, not swap. stays within array bounds
	if (index < numCourses - 1) {
		for (int i = index; i < numCourses; i++) {
			if (i < numCourses - 1)
			*(courses + i) = *(courses + i + 1);
		}
	}
	numCourses--;
}

ostream & operator<<(ostream & out, const CourseSchedule &schedule)
{
	out << "CLASS SCHEDULE\n-----------------------------------------\n";
	out << "Name: " << schedule.getStudentName() << endl;
	out << "Semester: " << schedule.getSemester() << endl;
	out << "Number of Classes: " << schedule.getNumCourses() << endl;
	out << "-----------------------------------------\n";

	for (int i = 0; i < schedule.getNumCourses(); i++) {
		out << *(schedule.courses + i);
		out << "\n\n";
	}
	return out;

}
