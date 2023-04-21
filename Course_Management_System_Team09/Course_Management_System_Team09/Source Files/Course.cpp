#include "Course.h"
#include<string>
using namespace std;

void addCourse(Course*& course) {
    Course* temp = new Course;
    cout << setw(30) << setfill('') << "" << endl;
    cout << setfill(' ');
    cout << setw(30) << "Add New Course" << endl;
    cout << setw(30) << setfill('') << "" << endl << endl;
    cout << "New course name: ";
    cin.ignore();
    getline(cin, temp->courseName);
    system("cls");
    cout << "Course ID: ";
    getline(cin, temp->courseID);
    system("cls");
    cout << "Day of week of the course " << endl;
    cout << setw(2) << "1." << setw(10) << left << "Monday" << endl;
    cout << setw(2) << "2." << setw(10) << left << "Tuesday" << endl;
    cout << setw(2) << "3." << setw(10) << left << "Wednesday" << endl;
    cout << setw(2) << "4." << setw(10) << left << "Thursday" << endl;
    cout << setw(2) << "5." << setw(10) << left << "Friday" << endl;
    cout << setw(2) << "6." << setw(10) << left << "Saturday" << endl;
    cout << setw(2) << "7." << setw(10) << left << "Sunday" << endl;
    cout << "Your choice:";
    getline(cin, temp->dayofWeek);
    system("cls");
    cout << "Session time of the course: " << endl;
    cout << setw(2) << "1." << setw(10) << left << "S1(7:30)" << endl;
    cout << setw(2) << "2." << setw(10) << left << "S2(9:30)" << endl;
    cout << setw(2) << "3." << setw(10) << left << "S3(13:30)" << endl;
    cout << setw(2) << "4." << setw(10) << left << "S4(15:30)" << endl;
    cout << "Your choice:";
    getline(cin, temp->sessionTime);
    system("cls");
    cout << "Teacher of the course: ";
    getline(cin, temp->teacher);
    system("cls");
    cout << "Number of credits: ";
    cin >> temp->numberofCredits;
    cin.ignore();
    system("cls");
    temp->next = course;
    course = temp;
    cout << setw(30) << setfill('') << "" << endl;
    cout << setfill(' ');
    cout << setw(30) << "Add course success" << endl;
    cout << setw(30) << setfill('') << "" << endl;
    cin.get();
    }

void deleteCourse(Course*& course) {
    cin.ignore();
    if (!course) {
    cout << setw(30) << setfill('') << "" << endl;
    cout << setfill(' ');
    cout << setw(30) << "Delete Course" << endl;
    cout << setw(30) << setfill('') << "" << endl << endl;
    cout << "No course existed" << endl;
    cin.get();
    return;
    }
    string name;
    cout << setw(30) << setfill('') << "" << endl;
    cout << setfill(' ');
    cout << setw(30) << "Delete Course" << endl;
    cout << setw(30) << setfill('') << "" << endl << endl;
    cout << "Course you want to delete:";
    getline(cin, name);
    cin.ignore();
    Course* cur = course;
    if (cur->courseName == name) {
    course = course->next;
    delete cur;
    cout << "Delete success" << endl;
    cin.get();
    return;
    }
    Course* prev = cur;
    cur = cur->next;
    while (cur) {   
    if (cur->courseName == name) {
    prev->next = cur->next;
    delete cur;
    cout << "Delete success" << endl;
    cin.get();
    return;
    }
    prev = cur;
    cur = cur->next;
    }
    cout << "Course not found" << endl;
    cin.get();
}

void viewliststudentincourse(Course* course) {
    cin.ignore();
    if (!course) {
        cout << "No course exists" << endl;
        cin.get();
        return;
    }
        int choice = 0;
    cout << setw(40) << "LIST OF COURSES" << endl;
    cout << setfill('-') << setw(80) << "" << endl;
    cout << setfill(' ');
    cout << setw(5) << "No." << setw(30) << "Course Name" << endl;
    cout << setfill('-') << setw(80) << "" << endl;
    cout << setfill(' ');
    int i = 1;
    Course* cur = course;
    while (cur) {
        cout << setw(5) << i << ". " << setw(30) << cur->courseName << endl;
        i++;
        cur = cur->next;
    }
        cout << "Enter the course number you want to view: ";
    cin >> choice;
        cur = course;
    i = 1;
    while (i != choice && cur) {
        cur = cur->next;
        i++;
    }
    
    if (!cur) {
        cout << "Invalid choice" << endl;
        cin.get();
        return;
    }
    system("cls");
    cout << setw(50) << "LIST OF STUDENTS IN " << cur->courseName << endl;
    cout << setfill('-') << setw(100) << "" << endl;
    cout << setfill(' ');
    cout << setw(5) << "No." << setw(20) << "Student ID" << setw(20) << "Last Name" << setw(20) << "First Name" << endl;
    cout << setfill('-') << setw(100) << "" << endl;
    cout << setfill(' ');
    
    i = 1;
    student* temp = cur->liststudent;
    while (temp) {
        cout << setw(5) << i << setw(20) << temp->socialID << setw(20) << temp->lastName << setw(20) << temp->firstName << endl;
        i++;
        temp = temp->next;
    }
    cin.get();
}


void addStudentToCourse(Course* course) {
    cin.ignore();
    if (!course) {
        cout << "No course existed";
        cin.get();
        return;
    }
    string filename;
    Course* cur = course;
    int i = 1;
    cout << setw(30) << "Choose course to add student into" << endl;
    cout << "-----------------------------------------------" << endl;
    while (course) {
        cout << setw(3) << i << ". " << course->courseName << endl;
        i++;
        course = course->next;
    }
    cout << "Input your choice: ";
    getline(cin, filename);
    filename = filename + ".csv";
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string studentID, firstName, lastName, className;
        getline(ss, studentID, ',');
        getline(ss, firstName, ',');
        getline(ss, lastName, ',');
        getline(ss, className, ',');

        student* newStudent = new student{ studentID, firstName, lastName, className, nullptr };
        if (cur->liststudent == nullptr) {
            cur->liststudent = newStudent;
        }
        else {
            student* current = cur->liststudent;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newStudent;
        }
        cur->numofstudent++;
    }

    file.close();
}
