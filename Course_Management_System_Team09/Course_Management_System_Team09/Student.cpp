#include "Student.h"


void Student::Login() {

}

void Student::Register() {

}

void Student::viewCourses() {
    if (numOfCourses == 0) {
        cout << "You are not enrolled in any courses." << endl;
        return;
    }
    cout << "Courses you are enrolled in:" << endl;
    for (int i = 0; i < numOfCourses; i++) {
        cout << i + 1 << ". " << course[i]->courseName << endl;
    }
}

void viewScoreboard() {
    if (numOfCourses == 0) {
        cout << "You are not enrolled in any courses." << endl;
        return;
    }
    for (int i = 0; i < numOfCourses; i++) {
        Course* c = course[i];
        cout << "Course: " << c->courseName << endl;
        cout << "Final Mark: " << c->getStudentFinalMark(id) << endl;
        cout << "Midterm Mark: " << c->getStudentMidtermMark(id) << endl;
        cout << "Other Mark: " << c->getStudentOtherMark(id) << endl;
        cout << "Total Mark: " << c->getStudentTotalMark(id) << endl;
        cout << endl;
    }
}
void Student::display() {
    std::cout << "ID: " << studentID << std::endl;
    std::cout << "Name: " << firstName << " " << lastName << std::endl;
    std::cout << "Gender: " << gender << std::endl;
    std::cout << "Date of birth: " << dateOfBirth << std::endl;
    std::cout << "Social ID: " << socialID << std::endl;
}