#include <iostream>
#include <string>
#include "Student.h"                                        
#include "staff.h"
#include "classes.h"
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
    Course* next=nullptr;

    void init();
	void ImportfromCSVfile();
    void deleteCourse();
    void display();
    void updateCourse();
    void addOnestudent();
};
