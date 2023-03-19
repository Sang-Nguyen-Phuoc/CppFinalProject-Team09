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


void Student::viewScoreBoard() {

}
void Student::display() {
    std::cout << "ID: " << studentID << std::endl;
    std::cout << "Name: " << firstName << " " << lastName << std::endl;
    std::cout << "Gender: " << gender << std::endl;
    std::cout << "Date of birth: " << dateOfBirth << std::endl;
    std::cout << "Social ID: " << socialID << std::endl;
}