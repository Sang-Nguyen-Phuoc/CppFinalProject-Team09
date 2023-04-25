#pragma once
#include <string>
#include "student.h"
using namespace std;

struct Class
{
	string classname;
	Class *next = nullptr;
};
