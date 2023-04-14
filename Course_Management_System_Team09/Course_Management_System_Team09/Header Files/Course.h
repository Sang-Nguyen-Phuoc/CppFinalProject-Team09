#include <iostream>
#include <string>
#include "Student.h"                                        
#include "staff.h"
#include "classes.h"
using namespace std;

struct Course {
	string courseName;
	string courseID;
	string dayofWeek;
	string sessionTime;
	string teacher;
	int numberofCredits;
	int numofstudent=0;
	student* liststudent;
	Course* next = nullptr;
};
