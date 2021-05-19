#include <iostream>
#include "roster.h"
#include <string>
#include "student.h"
using std::string;
using std::cout;
using std::endl;


int main() {
	cout << "Course Title: Scripting and Programming - Applications ¨C C867\n";
	cout << "Programming Language: C++\n";
	cout << "WGU Student ID: #001536238\n";
	cout << "Darian Chen\n\n";

	Roster classRoster;
	classRoster.Parser();
	classRoster.PrintAll();
	classRoster.PrintInvalidEmails();

	// For loop that prints a student¡¯s average number of days in the 3 courses by student ID

	for (int x = 0; x < 5; x++) {
		Student student = classRoster.getStudent(x);  //classRosterArray is private so I used a method to retrieve the students
		classRoster.PrintAverageDaysInCourse(student.GetID());
		cout << endl;
	}
	cout << endl;

	classRoster.PrintByDegreeProgram(SOFTWARE);
	classRoster.Remove("A3");
	classRoster.PrintAll();
	classRoster.Remove("A3"); //Prints a message saying such a student with this ID was not found
}

//All files were created using visual studio 2019
//Thank you for taking the time to review my project