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
    std::string className;
    std::string dateOfBirth;
    std::string socialID;
    std::string course1Mark;
    std::string course2Mark;
    std::string course3Mark;
    Student* next;

    void init();
    void login(); 
    static void AddStudentsFromCSVFile(string filename);
    void displayOnScreen();
    void AddStudentFromKeyBoard();
    void viewCourses();
    void viewScoreBoard();
    void displayOnFile();
    void menu();
    void logout();
};




