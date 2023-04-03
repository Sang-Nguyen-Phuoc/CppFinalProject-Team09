#include <iostream>
#include <string>
#include "Student.h"
#include "staff.h"
#include "classes.h"
#include "Course.h"

struct semester {
    classes* classes;
    int no;
    Course* Course;
    semester* next = nullptr;

    void init();
	void ImportfromCSVfile();
    void display();
};
