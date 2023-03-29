#include <iostream>
#include <string>
#include "Student.h"
#include "staff.h"

struct classes {
    Student* students;
    string className;
    string classID;
    staff* teacher;
    classes* next = nullptr;

    void addoneStudent();
    void init();
	void ImportfromCSVfile();
    void deleteclass();
    void display();
};
