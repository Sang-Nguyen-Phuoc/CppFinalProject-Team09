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
	int s1 = 0;
	int s2 = 0;
	int s3 = 0;

    void init();
	void ImportfromCSVfile();
    void display();
};
