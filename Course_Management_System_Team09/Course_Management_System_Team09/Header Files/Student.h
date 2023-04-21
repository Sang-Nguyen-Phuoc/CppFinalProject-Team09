#pragma once
#include <iostream> 
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
struct coursedata {
    string courseName;
    string totalMark = "x";
    string finalMark = "x";
    string midtermMark = "x";
    string otherMark = "x";
    coursedata* next = nullptr;
};


struct student {
    string studentID;
    string firstName;
    string lastName;
    string gender;
    string className;
    string dateOfBirth;
    string socialID;
    int numofcourse = 0;
    student* next = nullptr;
    coursedata* listcourse = nullptr;
    string password = "1";

};
student* login2(student* sStart);

