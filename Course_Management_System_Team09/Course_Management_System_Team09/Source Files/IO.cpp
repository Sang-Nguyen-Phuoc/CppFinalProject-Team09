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
		if (!c) c = temp;
		else {
			Class* run = c;
			while (run->next) run = run->next;
			run->next = temp;
		}
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
	int numofcourse;
	f4.open("liststudent.txt");
	while (!f4.eof()) {
		f4 >> studentID >> firstName >> lastName >> className >> gender >> dateOfBirth >> socialID>>numofcourse;
		if (studentID == "") break;
		student* temp = new student;
		temp->studentID = studentID;
		temp->firstName = firstName;
		temp->lastName = lastName;
		temp->className = className;
		temp->gender = gender;
		temp->dateOfBirth = dateOfBirth;
		temp->socialID = socialID;
		temp->numofcourse = numofcourse;
		int n = numofcourse;
		while (n) {
			coursedata* run = new coursedata;
			f4 >> run->courseName >> run->totalMark >> run->finalMark >>run->midtermMark >> run->otherMark;
			if (!temp->listcourse) temp->listcourse = run;
			else {
				coursedata* run2 = temp->listcourse;
				while (run2->next) run2 = run2->next;
				run2->next = run;
			}
			n--;
		}
		if (!sStart) sStart=temp;
		else {
			student* run = sStart;
			while (run->next) run = run->next;
			run->next = temp;
		}
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
	string year;
	int s1, s2, s3;
	f5.open("listcourse.txt");
	int i = 0;
	string line;
	while (getline(f5, courseName) && getline(f5, courseID) &&
	getline(f5, dayofWeek) &&
	getline(f5, sessionTime) &&
	getline(f5, teacher) &&
	f5 >> numofstudent >> numberofCredits >>year>>s1>>s2>>s3 ) {
		if (courseName == "") break;
		Course* temp = new Course;
		temp->courseName = courseName;
		temp->courseID = courseID;
		temp->dayofWeek = dayofWeek;
		temp->sessionTime = sessionTime;
		temp->teacher = teacher;
		temp->numofstudent = numofstudent;
		temp->numberofCredits = numberofCredits;
		temp->sc.year = year;
		temp->sc.s1 = s1;
		temp->sc.s2 = s2;
		temp->sc.s3 = s3;
		if (!cHead) cHead=temp;
		else {
			Course* run = cHead;
			while (run->next) run = run->next;
			run->next = temp;
		}
		string studentID;
		string firstName;
		string lastName;
		string className;
		int n = numofstudent;
		while (n) {
			f5 >> studentID >> firstName >> lastName >> className;
			student* cur = new student;
			cur->studentID = studentID;
			cur->firstName = firstName;
			cur->lastName = lastName;
			cur->className = className;
			if (!temp->liststudent) temp->liststudent=cur;
			else {
				student* run = temp->liststudent;
				while (run->next) run = run->next;
				run->next = cur;
			}
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
		of4 << sStart->studentID << endl << sStart->firstName << endl << sStart->lastName << endl << sStart->className << endl << sStart->gender << endl << sStart->dateOfBirth << endl << sStart->socialID << endl << sStart->numofcourse << endl;
		while (sStart->listcourse) {
			coursedata* temp = sStart->listcourse;
			of4 << sStart->listcourse->courseName << endl << sStart->listcourse->totalMark << endl << sStart->listcourse->finalMark << endl << sStart->listcourse->midtermMark << endl << sStart->listcourse->otherMark << endl;
			sStart->listcourse = sStart->listcourse->next;
			delete temp;
		}
		sStart = sStart->next;
		delete cur;
	}
	of4.close();
	ofstream of5;
	of5.open("listcourse.txt");
	while (cHead) {
		Course* cur = cHead;
		of5 << cHead->courseName << endl << cHead->courseID << endl << cHead->dayofWeek << endl << cHead->sessionTime << endl << cHead->teacher << endl << cHead->numofstudent << endl << cHead->numberofCredits << endl << cHead->sc.year << endl << cHead->sc.s1 << endl << cHead->sc.s2 << endl << cHead->sc.s3 << endl;
		while (cHead->liststudent) {
			student* temp = cHead->liststudent;
			of5 << cHead->liststudent->studentID << endl << cHead->liststudent->firstName << endl << cHead->liststudent->lastName << endl << cHead->liststudent->className << endl;
			cHead->liststudent = cHead->liststudent->next;
			delete temp;
		}
		cHead = cHead->next;
		delete cur;
	}
	of5.close();
}
