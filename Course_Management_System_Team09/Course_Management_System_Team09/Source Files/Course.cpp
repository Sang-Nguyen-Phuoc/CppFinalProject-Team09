#include "Course.h"
#include<string>
using namespace std;

void addCourse(Course*& course) {
	Course* temp = new Course;
	cout << "New course name: ";
	cin.ignore();
	getline(cin, temp->courseName);
	system("cls");
	cout << "Course ID: ";
	getline(cin, temp->courseID);
	system("cls");
	cout << "Day of week of the coure " << endl;
	cout << "1.Monday" << endl;
	cout << "2.Tuesday" << endl;
	cout << "3.Wednesday" << endl;
	cout << "4.Thursday" << endl;
	cout << "5.Friday" << endl;
	cout << "6.Saturday" << endl;
	cout << "7.Sunday" << endl;
	cout << "Your choice:";
	getline(cin, temp->dayofWeek);
	system("cls");
	cout << "Session time of the course: " << endl;
	cout << "1.S1(7:30)" << endl;
	cout << "2.S2(9:30)" << endl;
	cout << "3.S3(13:30)" << endl;
	cout << "4.S4(15:30)" << endl;
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
	cout << "Add course success";
	cin.get();
}

void deleteCourse(Course*& course) {
    cin.ignore();
    if (!course) {
        cout << "No course existed";
        cin.get();
        return;
    }
    string name;
    cout << "Course you want to delete:";
    getline(cin, name);
    cin.ignore();
    Course* cur = course;
    if (cur->courseName == name) {
        course = course->next;
        delete cur;
        cout << "Delete success";
        cin.get();
        return;
    }
    Course* prev = cur;
    cur = cur->next;
    while (cur) {
        if (cur->courseName == name) {
            prev->next = cur->next;
            delete cur;
            cout << "Delete success";
            cin.get();
            return;
        }
    }
}

void viewliststudentincourse(Course* course) {
    cin.ignore();
    if (!course) {
        cout << "No course existed";
        cin.get();
        return;
    }
    Course* cur = course;
    int i = 1;
    cout << "Choose course you want:" << endl;
    while (cur) {
        cout << i << "." << cur->courseName << endl;
        i++;
        cur = cur->next;
    }
    string name;
    cout << "Input your choice:";
    cin >> name;
    while (course->courseName != name) {
        course = course->next;
    }
    system("cls");
    cout << "No   Student ID  Last Name   First Name  " << endl;
    student* temp = course->liststudent;
    while (temp) {
        cout << i << "    " << temp->socialID << "  " << temp->lastName << "    " << temp->firstName << endl;
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
    cout << "Choose course to add student into" << endl;
    while (course) {
        cout << i << "." << course->courseName << endl;
        i++;
        course = course->next;
    }
    cout << "Input your choice:";
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
        if (course->liststudent == nullptr) {
            course->liststudent = newStudent;
        }
        else {
            student* current = course->liststudent;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newStudent;
        }
        course->numofstudent++;
    }

    file.close();
}
