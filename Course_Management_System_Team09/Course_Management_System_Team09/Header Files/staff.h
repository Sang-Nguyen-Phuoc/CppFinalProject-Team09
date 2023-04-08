#pragma once
#include<string>
#include"class.h"
#include"semester.h"
#include"schoolyear.h"
#include"student.h"
using namespace std;
struct staff {
	string id;
	string password;
	staff* next = nullptr;
};

bool checkexist(staff* sHead, string id);

void regis(staff*& sHead);

staff* login(staff* s, string id, string password);
void staffmenu(staff* a, staff*& sHead, schoolyear& sy, semester& s,Class*& c,student*& sSstart);

void createschoolyear(schoolyear& sy);
void deleteschoolyear(schoolyear& sy);
void createsemester(schoolyear sy, semester& s);
void addsemester(schoolyear sy, semester s);
void endsemester(schoolyear sy, semester& s);
void inputfile(semester s, student*& sStart);

void createclass(Class*& listclass);
void viewlistclass(Class* c);
void viewlistofstudentinclass(Class* c, student* sStart);
