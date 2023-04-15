#include"class.h"
#include"Course.h"
#include"schoolyear.h"
#include"staff.h"
#include"student.h"
#include<iostream>
#include<string>
#include<stdlib.h>
#include<fstream>
#include<vector>
#include <sstream>
#include<sstream>
using namespace std;

void input(staff*& sHead, schoolyear& s, Class*& c, student*& sStart, Course*& cHead) {
	ifstream f1;
	f1.open("staffaccount.txt");
	string id;
	string password;
	while (!f1.eof()) {
		f1 >> id;
		f1 >> password;
		if (id == "") break;
		staff* temp = new staff;
		temp->id.assign(id);
		temp->password.assign(password);
		temp->next = sHead;
		sHead = temp;
	}
	f1.close();
	ifstream f2;
	f2.open("schoolyear.txt");
	f2 >> s.year;
	f2 >> s.s1 >> s.s2 >> s.s3;
	f2.close();
	ifstream f3;
	string classname;
	f3.open("listclass.txt");
	while (!f3.eof()) {
		getline(f3, classname);
		if (classname == "") break;
		Class* temp = new Class;
		temp->classname = classname;
		temp->next = c;
		c = temp;
	}
	f3.close();
	ifstream f4;
	string studentID;
	string firstName;
	string lastName;
	string gender;
	string className;
	string dateOfBirth;
	string socialID;
	f4.open("liststudent.txt");
	while (!f4.eof()) {
		f4 >> studentID >> firstName >> lastName >> className >> gender >> dateOfBirth >> socialID;
		if (studentID == "") break;
		student* temp = new student;
		temp->studentID = studentID;
		temp->firstName = firstName;
		temp->lastName = lastName;
		temp->className = className;
		temp->gender = gender;
		temp->dateOfBirth = dateOfBirth;
		temp->socialID = socialID;
		temp->next = sStart;
		sStart = temp;
	}
	f4.close();
	ifstream f5;
	string courseName;
	string courseID;
	string dayofWeek;
	string sessionTime;
	string teacher;
	int numofstudent;
	int numberofCredits;
	f5.open("listcourse.txt");
	int i = 0;
	string line;
	while (!f5.eof()) {

		f5 >> courseName >> courseID >> dayofWeek >> sessionTime >> teacher >> numofstudent >> numberofCredits;
		if (courseName == "") break;
		Course* temp = new Course;
		temp->courseName = courseName;
		temp->courseID = courseID;
		temp->dayofWeek = dayofWeek;
		temp->sessionTime = sessionTime;
		temp->teacher = teacher;
		temp->numofstudent = numofstudent;
		temp->numberofCredits = numberofCredits;
		temp->next = cHead;
		cHead = temp;
		int studentID;
		string firstName;
		string lastName;
		string className;
		string point;
		int n = numofstudent;
		while (n) {
			f5 >> studentID >> firstName >> lastName >> className >> point;
			student* cur = new student;
			cur->studentID = studentID;
			cur->firstName = firstName;
			cur->lastName = lastName;
			cur->className = className;
			cur->point = point;
			cur->next = temp->liststudent;
			temp->liststudent = cur;
			n--;
		}
	}
	f5.close();
}


void output(staff* sHead, schoolyear s, Class* c, student* sStart, Course* cHead) {
	ofstream of1;
	of1.open("staffaccount.txt");
	while (sHead) {
		staff* cur = sHead;
		of1 << sHead->id << endl;
		of1 << sHead->password << endl;
		sHead = sHead->next;
		delete cur;
	}
	of1.close();
	ofstream of2;
	of2.open("schoolyear.txt");
	of2 << s.year << endl;
	of2 << s.s1 << " " << s.s2 << " " << s.s3;
	of2.close();
	ofstream of3;
	of3.open("listclass.txt");
	while (c) {
		Class* cur = c;
		of3 << c->classname << endl;
		c = c->next;
		delete cur;
	}
	of3.close();
	ofstream of4;
	of4.open("liststudent.txt");

	while (sStart) {
		student* cur = sStart;
		of4 << sStart->studentID << endl << sStart->firstName << endl << sStart->lastName << endl << sStart->className << endl << sStart->gender << endl << sStart->dateOfBirth << endl << sStart->socialID << endl;
		sStart = sStart->next;
		delete cur;
	}
	of4.close();
	ofstream of5;
	of5.open("listcourse.txt");
	while (cHead) {
		Course* cur = cHead;
		int n = cHead->numofstudent;
		of5 << cHead->courseName << endl << cHead->courseID << endl << cHead->dayofWeek << endl << cHead->sessionTime << endl << cHead->teacher << endl << cHead->numofstudent << endl << cHead->numberofCredits << endl;
		while (n) {
			student* temp = cHead->liststudent;
			of5 << cHead->liststudent->studentID << endl << cHead->liststudent->firstName << endl << cHead->liststudent->lastName << endl << cHead->liststudent->className << endl << cHead->liststudent->point << endl;
			n--;
			delete temp;
			cHead->liststudent = cHead->liststudent->next;
		}
		cHead = cHead->next;
		delete cur;
	}
	of5.close();
}