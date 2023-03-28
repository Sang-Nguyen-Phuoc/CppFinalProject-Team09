#include <iostream> 
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Student {
    int studentID;
    std::string firstName;
    std::string lastName;
    std::string gender;
    std::string dateOfBirth;
    std::string socialID;
    Student* next;

    void login(); 
    static void AddStudentsFromCSVFile(string filename);
    void display();
    void AddStudentFromKeyBoard();
    void viewCourses();
    void viewScoreBoard();
};

void Student::login(); 
oid Student::AddStudentFromKeyBoard();
void Student::AddStudentsFromCSVFile(string filename);
void Student::display();
void Student::viewCourses();
void Student::viewScoreBoard();

