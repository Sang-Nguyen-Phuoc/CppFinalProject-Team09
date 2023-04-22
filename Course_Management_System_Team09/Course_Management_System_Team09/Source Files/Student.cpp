#include "Student.h"
#include<string>
#include"Course.h"
using namespace std;
//// Declare a global pointer to the head of the linked list
//Student* head = nullptr;
//
student* login2(student* sStart) {
	string id;
	string password;
	cout << "Input id: ";
	cin.ignore();
	getline(cin, id);
	cout << "Input password: ";
	getline(cin, password);

	cout << endl << setw(20) << "ID" << setw(20) << "First Name" << setw(20) << "Last Name" << endl;
	cout << setfill('-') << setw(60) << "-" << endl;
	cout << setfill(' ');

	while (sStart) {
		if (sStart->studentID == id && sStart->password == password) {
			cout << setw(20) << sStart->studentID << setw(20) << sStart->firstName << setw(20) << sStart->lastName << endl;
			cout << "Login success" << endl;
			return sStart;
		}
		sStart = sStart->next;
	}

	cout << "ID doesn't exist" << endl;
	cout << "Press enter to continue";

	return nullptr;
}


void viewcourse(Course* course, student* s, schoolyear sy) {
    cin.ignore();
    cout << "YOUR COURSE" << endl;
    int i = 1;
    cout << setw(2) << "#" << setw(12) << "Course ID" << setw(20) << "Course name" << setw(20) << "Number of credits" << setw(20) << "Schedule" << setw(20) << "Teacher" << endl;
    while (course) {
        student* temp = course->liststudent;
        while (temp) {
            if (temp->studentID == s->studentID) {
                if (course->sc.s1 <= sy.s1 && course->sc.s2 <= sy.s2 && course->sc.s3 <= sy.s3) {
                    cout << setw(2) << i << setw(12) << course->courseID << setw(20) << course->courseName << setw(20) << course->numberofCredits << setw(20) << course->dayofWeek << " " << course->sessionTime << setw(20) << course->teacher << endl;
                    break;
                }
            }
            temp = temp->next;
        }
        course = course->next;
    }
    cin.get();
}

void viewownscore(Course* course, student* s) {
	cin.ignore();
	cout << "Your Scoreboard" << endl;
	int i = 1;
	cout << "#    Course name        Other mark    Midterm Mark    Final Mark    Total Mark" << endl;
	coursedata* run = s->listcourse;
	while (run) {
		cout << i << "    " << setw(20) << left << run->courseName << "    " << setw(12) << left << run->otherMark << "    " << setw(14) << left << run->midtermMark << "    " << setw(11) << left << run->finalMark << "    " << setw(10) << left << run->totalMark << endl;
		i++;
		run = run->next;
	}
	cin.get();
}


