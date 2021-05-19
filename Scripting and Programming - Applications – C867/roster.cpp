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
"A5,Darian,Chen,dchen8@wgu.edu,24,10,15,20,SOFTWARE"};

void Roster::Parser()
{
    for (int x = 0; x < numOfStudents; x++) {
        vector<string> vector;    //Create an empty vector
        string row = studentData[x];  //Create an array to store the row
        stringstream s_stream(row);  //Create a stream of input of the (row/item in student array) using string stream
        while (s_stream.good()) { 
            string item; 
            getline(s_stream, item, ','); //Split at character ','
            vector.push_back(item);  //Add item to vector
        }
        DegreeProgram deg = SECURITY; //Default value of SECURITY
        if (vector.at(8).back() == 'E') { //Check to see if degree is SOFTWARE
            deg = SOFTWARE;
        }
        if (vector.at(8).back() == 'K') { //Check to see if degree is NETWORK
            deg = NETWORK;
        }
        Add(vector.at(0), vector.at(1), vector.at(2), vector.at(3), stoi(vector.at(4)), stoi(vector.at(5)), stoi(vector.at(6)), stoi(vector.at(7)), deg);
        //Add students to vector by calling add function
    }
}

void Roster::Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
    int days[3] = {daysInCourse1,daysInCourse2,daysInCourse3};
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, days, degreeProgram);
}



void Roster::Remove(string studentID)
{ //This method changes the studentID to deleted
    for (int x = 0; x <= lastIndex; x++) {
        if (classRosterArray[x]->GetID() == studentID) {
            cout << "Student " << classRosterArray[x]->GetID() <<" has been deleted!" << endl;
            classRosterArray[x]->SetID("Deleted");
            return;
        }
    }
    cout << "A student with ID "<< studentID << " was not found!" << endl;
}
void Roster::PrintAll() //Prints tab-separated list of students and correctly loops through all of the students in the student list while calling print function for each
{
    for (int x = 0; x <= lastIndex; x++) {
        classRosterArray[x]->Print();
 }
    cout << endl;
}

void Roster::PrintAverageDaysInCourse(string studentID)
{
    bool studentExists = false; //Default value of false
    //Loop around the classRosterArray and use getter method to compare studentID
    for (int x = 0; x <= lastIndex; x++) {
        if (classRosterArray[x]->GetID() == studentID) {
            studentExists = true; //Set foundStudent to true if student is found
            int* numberofDays = classRosterArray[x]->GetNumberOfDays();
            int average = (numberofDays[0] + numberofDays[1] + numberofDays[2])/3;
            cout << "Student " << classRosterArray[x]->GetID() <<  "'s average number of days in three courses is " << average; 
            //Print out the average number of days in 3 course by Student ID
        }
    }
    if (studentExists == false) {
        cout << "Student not found!"; //If the given student ID is not found then we will display an error message to the user
    }
}
void Roster::PrintInvalidEmails() //Correctly verifies student email addresses and displays all invalid email addresses to the user
{
    for (int x = 0; x <= lastIndex; x++) {
        string email = classRosterArray[x]->GetEmailAddress();
        if (email.find("@") != string::npos && email.find(".") != string::npos && email.find(" ") == string::npos){
            //This email is valid so we do nothing
            //If find function satifies all the conditions above then this email is valid
            //A valid email must have an "@","." and no spaces
       }
        else { //Print out the invalid emails
            cout << "Student " << classRosterArray[x]->GetID() <<  " has an invalid email. " << classRosterArray[x]->GetEmailAddress();
            cout << endl;
        }
    }
    cout << endl;
}
void Roster::PrintByDegreeProgram(DegreeProgram degreeProgram)
{
    string deg = "SECURITY"; //Default value of security

    if (degreeProgram == SOFTWARE) {
        deg = "SOFTWARE";
    }
    else if(degreeProgram == NETWORK) {
        deg = "NETWORK";
    }
 
    cout << "Students with degree " << deg << " are listed below" << endl;
    for (int x = 0; x <= lastIndex; x++) {
        if (classRosterArray[x]->GetDegreeProgram() == degreeProgram) {
            classRosterArray[x]->Print(); //Calls the print method for each student with the specified degree
        }
    }
    cout << endl;
}
Roster::Roster()
{ //Sets classRosteArray to null pointers
    for (int x = 0; x <= lastIndex; x++) {
        classRosterArray[x] = nullptr;
    }
}
Roster::~Roster() //Destructor
{
    
       // delete *classRosterArray; 
    
    for (int x = 0; x <= lastIndex; x++) {
       delete classRosterArray[x];
    }
    //I chose to delete each student object in the roster, this will release the memory
    //No need to call destructor in main method
}

Student Roster::getStudent(int index)
{
    return *classRosterArray[index];
}





