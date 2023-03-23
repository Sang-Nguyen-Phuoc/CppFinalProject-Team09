#include <iostream>
#include <string>
#include "Student.h"
#include "staff.h"

struct classes {
    Student* students;
    string className;
    string classID;
    staff* teacher;

    void addoneStudent();
    void regis();
	void ImportfromCSVfile();
    void deletecourse();
    void display();
};
