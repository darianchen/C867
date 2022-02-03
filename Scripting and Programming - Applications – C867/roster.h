#pragma once
#include "student.h"
#include "degree.h"
#include <string>

using std::string;

class Roster 
{
public:
	void Parser();
	void Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void Remove(string studentID);
	void PrintAll();
	void PrintAverageDaysInCourse(string studentID);
	void PrintInvalidEmails();
	void PrintByDegreeProgram(DegreeProgram degreeProgram);
	Roster();
	~Roster();

	Student getStudent(int index);

private:
	Student* classRosterArray[5]; 
	int lastIndex = -1;
	const int numOfStudents = 5;
};

