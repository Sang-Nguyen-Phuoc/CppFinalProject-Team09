#pragma once
#include<string>
#include"student.h"
using namespace std;

struct Class {
	string classname;
	Student* liststudent=nullptr;
	Class* next=nullptr;
};
