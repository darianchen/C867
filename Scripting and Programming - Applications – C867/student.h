#pragma once
#include "degree.h"
#include <string>
using std::string;

class Student {
private: 
	string studentID, firstName, lastName, emailAddress;
	int age;
	int numberOfDays[3];
	DegreeProgram degree;

public:
	Student(string sID, string fName, string lName, string eAddress, int aAge, int daysInCourse[], DegreeProgram degreeProgram);
	Student();
	~Student();

	string GetID();
	string GetFirstName();
	string GetLastName();
	string GetEmailAddress();
	
	DegreeProgram GetDegreeProgram();
	
	int GetAge();
	int *GetNumberOfDays();

	void SetID(string ID);
	void SetFirstName(string first);
	void SetLastName(string last);
	void SetEmailAddress(string email);
	void SetAge(int theAge);
	void SetNumberOfDays(int *daysInCourse);
	void SetDegreeProgram(DegreeProgram degreeProgram);
	void Print();
};