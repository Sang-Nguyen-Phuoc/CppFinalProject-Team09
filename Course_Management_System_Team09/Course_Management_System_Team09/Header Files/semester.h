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
	bool s1 = 0;
	bool s2 = 0;
	bool s3 = 0;

    void init();
	void ImportfromCSVfile();
    void display();
};
