#include <iostream>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct student {
    string studentID;
    string firstName;
    string lastName;
    string gender;
    string className;
    string dateOfBirth;
    string socialID;
    student* next = nullptr;
    string point="x";
    string password = "1";

};
student* login2(student* sStart);




