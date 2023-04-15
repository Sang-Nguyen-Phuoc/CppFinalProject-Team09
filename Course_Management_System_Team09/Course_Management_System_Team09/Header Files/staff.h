#pragma once
#include"schoolyear.h"
#include"class.h"
#include"Course.h"
#include"student.h"
#include<string>

using namespace std;
struct staff {
	string id;
	string password;
	staff* next = nullptr;
};
bool checkexist(staff* sHead, string id);
void regis(staff*& sHead);
void createclass(Class*& listclass);
void AddStudentFromKeyBoard(student*& head);
void inputfile(schoolyear s, student*& sStart);
void viewlistclass(Class* c);
void viewlistofstudentinclass(Class* c, student* sStart);

staff* login1(staff* sHead);

void createschoolyear(schoolyear& s);
void deleteschoolyear(schoolyear& s);
void createsemester(schoolyear& s);

void endsemester(schoolyear s);
void createclass(Class*& listclass);

void viewlistcourse(Course* course);
