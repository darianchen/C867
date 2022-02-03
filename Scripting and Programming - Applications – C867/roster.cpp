#include <iostream>
#include "roster.h"
#include <string>
#include <vector>
#include <sstream>
#include "student.h"
#include "degree.h"
using std::string; 
using std::vector;
using std::stringstream;
using std::cout;
using std::endl;

const string studentData[5] = 
{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,Derek,Johnson,dbjohnson66779@gmail.com,24,10,15,20,SOFTWARE"};

void Roster::Parser()
{
    for (int x = 0; x < numOfStudents; x++) {
        vector<string> vector;    
        string row = studentData[x]; 
        stringstream s_stream(row);  
        while (s_stream.good()) { 
            string item; 
            getline(s_stream, item, ','); 
            vector.push_back(item); 
        }
        DegreeProgram deg = SECURITY; 
        if (vector.at(8).back() == 'E') {
            deg = SOFTWARE;
        }
        if (vector.at(8).back() == 'K') { 
            deg = NETWORK;
        }
        Add(vector.at(0), vector.at(1), vector.at(2), vector.at(3), stoi(vector.at(4)), stoi(vector.at(5)), stoi(vector.at(6)), stoi(vector.at(7)), deg);
    }
}

void Roster::Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
    int days[3] = {daysInCourse1,daysInCourse2,daysInCourse3};
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, days, degreeProgram);
}



void Roster::Remove(string studentID)
{ 
    for (int x = 0; x <= lastIndex; x++) {
        if (classRosterArray[x]->GetID() == studentID) {
            cout << "Student " << classRosterArray[x]->GetID() <<" has been deleted!" << endl;
            classRosterArray[x]->SetID("Deleted");
            return;
        }
    }
    cout << "A student with ID "<< studentID << " was not found!" << endl;
}
void Roster::PrintAll() 
{
    for (int x = 0; x <= lastIndex; x++) {
        classRosterArray[x]->Print();
 }
    cout << endl;
}

void Roster::PrintAverageDaysInCourse(string studentID)
{
    bool studentExists = false; 
    for (int x = 0; x <= lastIndex; x++) {
        if (classRosterArray[x]->GetID() == studentID) {
            studentExists = true; 
            int* numberofDays = classRosterArray[x]->GetNumberOfDays();
            int average = (numberofDays[0] + numberofDays[1] + numberofDays[2])/3;
            cout << "Student " << classRosterArray[x]->GetID() <<  "'s average number of days in three courses is " << average; 
        }
    }
    if (studentExists == false) {
        cout << "Student not found!"; 
    }
}
void Roster::PrintInvalidEmails() 
{
    for (int x = 0; x <= lastIndex; x++) {
        string email = classRosterArray[x]->GetEmailAddress();
        if (email.find("@") != string::npos && email.find(".") != string::npos && email.find(" ") == string::npos){
       }
        else { 
            cout << "Student " << classRosterArray[x]->GetID() <<  " has an invalid email. " << classRosterArray[x]->GetEmailAddress();
            cout << endl;
        }
    }
    cout << endl;
}
void Roster::PrintByDegreeProgram(DegreeProgram degreeProgram)
{
    string deg = "SECURITY";

    if (degreeProgram == SOFTWARE) {
        deg = "SOFTWARE";
    }
    else if(degreeProgram == NETWORK) {
        deg = "NETWORK";
    }
 
    cout << "Students with degree " << deg << " are listed below" << endl;
    for (int x = 0; x <= lastIndex; x++) {
        if (classRosterArray[x]->GetDegreeProgram() == degreeProgram) {
            classRosterArray[x]->Print(); 
        }
    }
    cout << endl;
}
Roster::Roster()
{ 
    for (int x = 0; x <= lastIndex; x++) {
        classRosterArray[x] = nullptr;
    }
}
Roster::~Roster() 
{
    
       
    
    for (int x = 0; x <= lastIndex; x++) {
       delete classRosterArray[x];
    }
}

Student Roster::getStudent(int index)
{
    return *classRosterArray[index];
}