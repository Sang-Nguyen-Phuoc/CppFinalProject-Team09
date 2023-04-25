#pragma once
#include <iostream>
#include <string>
#include "staff.h"
#include "Course.h"
using namespace std;

void menu();
void input(staff *&sHead, schoolyear &s, Class *&c, student *&sStart, Course *&course);
void output(staff *sHead, schoolyear s, Class *c, student *sStart, Course *cHead);

void staffmenu(staff *a, staff *&sHead, schoolyear &s, Class *&c, student *&sStart, Course *&course);
void studentmenu(student *s, Course *course, schoolyear sy);
