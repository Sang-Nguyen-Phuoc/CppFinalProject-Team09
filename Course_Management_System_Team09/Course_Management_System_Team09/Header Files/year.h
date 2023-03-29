#include <iostream>
#include <string>
#include "Student.h"
#include "staff.h"
#include "semester.h"

struct year {
    semester semester[3];
    int nYear;
    Course* Course;
    year* next=nullptr;

    void init();
	void ImportfromCSVfile();
    void display();
};
