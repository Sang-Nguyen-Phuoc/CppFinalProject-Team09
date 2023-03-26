#include <iostream>
#include <string>
using namespace std;

struct Student {
    int studentID;
    std::string firstName;
    std::string lastName;
    std::string gender;
    std::string dateOfBirth;
    std::string socialID;
    Student* next; 

    void Register();
    void Login();
    void display();
    void viewCourses();
    void viewScoreBoard();

};