#include <iostream>
#include "roster.h"
#include <string>
#include "student.h"
using std::string;
using std::cout;
using std::endl;


int main() {

	Roster classRoster;
	classRoster.Parser();
	classRoster.PrintAll();
	classRoster.PrintInvalidEmails();



	for (int x = 0; x < 5; x++) {
		Student student = classRoster.getStudent(x);  
		classRoster.PrintAverageDaysInCourse(student.GetID());
		cout << endl;
	}
	cout << endl;

	classRoster.PrintByDegreeProgram(SOFTWARE);
	classRoster.Remove("A3");
	classRoster.PrintAll();
	classRoster.Remove("A3"); 
}
//All files were created using visual studio 2019