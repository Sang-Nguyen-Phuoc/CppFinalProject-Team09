#include "Course.h"

void Course::init(){
    students = nullptr;
    courseName = "";
    courseID = "";
    classID = nullptr;
    dayofWeek = "";
    sessionTime = "";
    teacher = nullptr;
    score = nullptr;
    numberofCredits = 0;
}
	
void Course::ImportfromCSVfile() {

}
    
void Course::display(){
    
}

void Course::updateCourse(){
    cout << "Enter new course name: ";
    cin >> courseName;

    cout << "Enter new course ID: ";
    cin >> courseID;

    cout << "Enter new class ID: ";
    if (classID == nullptr) {
        classID = new classes;
    }
    cin >> classID->classID;

    cout << "Enter new day of week: ";
    cin >> dayofWeek;

    cout << "Enter new session time: ";
    cin >> sessionTime;

    cout << "Enter new teacher's name: ";
    if (teacher->name == "") {
        teacher = new staff;
    }
    cin >> teacher->name;

    cout << "Enter new number of credits: ";
    cin >> numberofCredits;
}

void Course::deleteCourse(){
    delete[] students;
    students = nullptr;
    delete classID;
    classID = nullptr;
    delete teacher;
    teacher = nullptr;
    delete[] score;
    score = nullptr;
    numberofCredits = 0;
}