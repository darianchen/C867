#pragma once
#include<string>

using std::string;

enum DegreeProgram
{
	SECURITY, NETWORK, SOFTWARE
};
//SECURITY = 0, NETWORK = 1, SOFTWARE = 2
static const string degreeStrings[] = {"SECURITY", "NETWORK", "SOFTWARE"};
//Create a parallel array that will return strings instead of numbers