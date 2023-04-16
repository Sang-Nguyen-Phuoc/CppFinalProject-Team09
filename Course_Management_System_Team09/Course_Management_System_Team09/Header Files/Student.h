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
    string totalMark = "x";
    string finalMark = "x";
    string midtermMark = "x";
    string otherMark = "x";
    student* next = nullptr;
    string password = "1";
};

};
student* login2(student* sStart);




