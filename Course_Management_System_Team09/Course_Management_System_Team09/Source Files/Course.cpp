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
void Course::addOnestudent() {
    Student* newStudent = new Student();
    cout << "Enter student ID: ";
    cin >> newStudent->studentID;
    cout << "Enter student first name: ";
    cin >> newStudent->firstName;
    cout << "Enter student last name: ";
    cin >> newStudent->lastName;
    cout << "Enter student gender: ";
    cin >> newStudent->gender;
    cout << "Enter student class name: ";
    cin >> newStudent->className;
    cout << "Enter student date of birth: ";
    cin >> newStudent->dateOfBirth;
    cout << "Enter student social ID: ";
    cin >> newStudent->socialID;
    Student* currStudent = students;
    while (currStudent->next != nullptr) {
        currStudent = currStudent->next;
    }

    currStudent->next = newStudent;
    newStudent->next = nullptr;
    cout << "Student added successfully!" << endl;
}
void Course::deleteOneStudent() {
    int studentID;
    cout << "Enter student ID to delete: ";
    cin >> studentID;

    Student* prevStudent = nullptr;
    Student* currStudent = students;
    while (currStudent != nullptr && currStudent->studentID != studentID) {
        prevStudent = currStudent;
        currStudent = currStudent->next;
    }
    if (currStudent == nullptr) {
        cout << "Error: Student not found" << endl;
        return;
    }

    if (prevStudent == nullptr) {
        students = currStudent->next;
    } else {
        prevStudent->next = currStudent->next;
    }

    delete currStudent;
    cout << "Student deleted successfully!" << endl;
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