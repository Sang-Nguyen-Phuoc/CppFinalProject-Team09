#pragma once
#include<string>
#include"class.h"
using namespace std;
struct staff {
	string name; 
	string id;
	string password;
	staff* next = nullptr;
};

bool checkexist(staff* sHead, string id);

void regis(staff*& sHead);

staff* login(staff* s, string id, string password);
void staffmenu(staff* a, staff*& sHead, schoolyear& sy, semester& s);

void createschoolyear(schoolyear& sy);
void deleteschoolyear(schoolyear& sy);
void createsemester(schoolyear sy, semester& s);
void addsemester(schoolyear sy, semester s);
void endsemester(schoolyear sy, semester& s);
void createclass(Class*& listclass);


