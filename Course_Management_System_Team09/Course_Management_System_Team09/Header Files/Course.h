#include <iostream>
#include <string>
#include "Student.h"
#include "staff.h"
using namespace std;

struct Course {
    Student* students;
    string courseName;
    string courseID;
    classes* classID;
    string dayofWeek;
    string sessionTime;
    staff* teacher;
    double* score;
    int numberofCredits;

    void init();
	void ImportfromCSVfile();
    void deleteCourse();
    void display();
    void updateCourse();
};
