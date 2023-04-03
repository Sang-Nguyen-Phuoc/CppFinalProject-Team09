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
void staffmenu(staff* a, staff*& sHead,string& schoolyear,Class*& listclass);

void createschoolyear(string& schoolyear);
void createclass(Class*& listclass);


