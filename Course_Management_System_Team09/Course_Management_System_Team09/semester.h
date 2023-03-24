#include <iostream>
#include <string>
#include "Student.h"
#include "staff.h"

struct semester {
    classes* classes;
    int no;
    Course* Course;

    void init();
	void ImportfromCSVfile();
    void display();
};
