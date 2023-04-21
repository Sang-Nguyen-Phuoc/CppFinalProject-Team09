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

	while (sStart) {
		if (sStart->studentID == id && sStart->password == password) {
			cout << "Login success" << endl;
			return sStart;
		}
		sStart = sStart->next;
	}
	if (!sStart) cout << "ID doesn't exist" << endl;
	cout << "Press enter to continue";
	return nullptr;
}

void viewcourse(Course* course,student* s,schoolyear sy) {
	cin.ignore();
	cout << "YOUR COURSE" << endl;
	int i = 1;
	cout << "#	Course ID	Course name		Number of credits	Schedule	Teacher" << endl;
	while (course) {
		student* temp = course->liststudent;
		while (temp) {
			if (temp->studentID == s->studentID) {
				if (course->sc.s1 <= sy.s1 && course->sc.s2 <= sy.s2 && course->sc.s3 <= sy.s3) {
					cout << i << "	" << course->courseID << "	" << course->courseName << "	" << course->numberofCredits << "	" << course->dayofWeek << " " << course->sessionTime << "	" << course->teacher << endl;
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
	cout << "#	Course name		Other mark	Midterm Mark	Final Mark	Total Mark" << endl;
	coursedata* run = s->listcourse;
	while (run) {
		cout << i << "	" << run->courseName << "	" << run->otherMark << "	" << run->midtermMark << "	" << run->finalMark << "	" << run->totalMark << endl;
		i++;
		run = run->next;
	}
	cin.get();
}



