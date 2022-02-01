//Gordon Straub + Andre Boodaghian + Adrian Holguin

#include "Semester.h"

using namespace std;

Semester::Semester(string semName, Date startDate, Date endDate)
{
	this->setSemesterName(semName).setSemesterStartDate(startDate).setSemesterEndDate(endDate);
}


Semester::~Semester()
{
}

string Semester::getSemesterName() const
{
	return semesterName;
}

Date Semester::getSemesterStartDate() const
{
	return semesterStartDate;
}

Date Semester::getSemesterEndDate() const
{
	return semesterEndDate;
}

Semester & Semester::setSemesterName(string n)
{
	semesterName = n;
	return *this;
}

Semester & Semester::setSemesterStartDate(Date startDate)
{
	semesterStartDate = startDate;
	return *this;
}

Semester & Semester::setSemesterEndDate(Date endDate)
{
	semesterEndDate = endDate;
	return *this;
}

istream & operator>>(istream & in, Semester & sem)
{
	string input;
	Date tempDate;

	cout << "Input Semester Name: \n";
	getline(in, input);
	sem.setSemesterName(input);

	bool valid = false;
	while (!valid) {

		cout << "Input Start Date (MM/DD/YYYY): \n";
		cin >> tempDate;
		sem.setSemesterStartDate(tempDate);

		cout << "Input End Date (MM/DD/YYYY): \n";
		cin >> tempDate;
		sem.setSemesterEndDate(tempDate);

		if (sem.getSemesterStartDate() > sem.getSemesterEndDate()) {
			cout << "Invalid semester. Start date occurrs after end date." << endl;
		}
		else {
			valid = true;
		}

	}
	return in;
}

ostream & operator<<(ostream& out, const Semester &sem)
{
	out << sem.getSemesterName() << " (" << sem.getSemesterStartDate() << " -> " << sem.getSemesterEndDate() << ")";
	return out;
}
