#pragma once
#include <iostream>
#include <string>
#include "student.h"
#include "schoolyear.h"
#include "class.h"
using namespace std;

struct Course
{
	string courseName;
	string courseID;
	string dayofWeek;
	string sessionTime;
	string teacher;
	int numberofCredits;
	int numofstudent = 0;
	student *liststudent = nullptr;
	schoolyear sc;
	Course *next = nullptr;
};

void addStudentToCourse(Course *course);
void deleteCourse(Course *&course, student *sHead);
void addCourse(Course *&course, schoolyear s);
void viewliststudentincourse(Course *course);
void updatecourse(Course *course);
void changecoursename(Course *course);
void changecourseID(Course *course);
void changedayofweek(Course *course);
void changeteacher(Course *course);
void changesession(Course *course);
void addonestudent(Course *&course);
void deleteonestudent(Course *&course);
void viewcourse(Course *course, student *s, schoolyear sy);
void getmark(Course *course, student *sHead);
void viewscoreboard(Course *course, student *sHead);
void updateresult(Course *course, student *&sHead);
void viewscoreofclass(Course *course, schoolyear sy, Class *c, student *sHead);
void viewownscore(Course *course, student *s);
void exportToCSVFile(Course *course, student *sHead);
