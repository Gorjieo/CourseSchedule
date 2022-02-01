// Gordon Straub + Andre Boodaghian + Adrian Holguin

#pragma once
#include "Time.h"
#include "Date.h"
#include "Course.h"
#include "Semester.h"

class CourseSchedule
{

	friend ostream &operator<<(ostream&, const CourseSchedule&);

public:
	
	~CourseSchedule();
	CourseSchedule(string s = string(), Semester sem = Semester(), int max = 1);
	CourseSchedule(CourseSchedule&);

	void setStudentName(string);
	string getStudentName()const;
	Semester getSemester()const;
	int getNumCourses()const;

	void addCourse(Course);
	void removeCourse();

private:
	string studentName;
	Semester semester;
	Course *courses;
	int maxSize;
	int numCourses;

	bool checkDates(Semester, Date, Date);
	void swap(int);
	
};

//CourseSchedule
//Import Course
//Import Semester
//
//Variables
//- string studentName
//- semester semester
//- *course courses(pointer to first array element)
//- int maxSize
//- int numCourses
//
//Methods
//+ Constructor(string name, semester, int maxNumCourses)
////set numCourses to 0
////dynamic array set to maxNumCourses
////do not let other variables change after construction but don’t make them const somehow? Not sure how this is achieved
//
//+Destructor()~
////delete array
//
//+ string getName();
//+semester getSemester();
//+int getNumCourses();
//+void setStudentName(string);
//
//-bool checkDates(semester, date course.getStartDate(), date course.getEndDate())
////check if course’s dates fall within semester
//
//+ void AddCourse(course);
////add course to class schedule array w/ member wise assignment if the course falls within the semester dates
//
//+operator <<
////display similar to picture, use for loop and overloaded << from course 
//
//+void removeCourse();
//
//Disallow copy constructor and memberwise assignment b / c of pointer