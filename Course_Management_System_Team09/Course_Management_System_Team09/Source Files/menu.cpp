#include "menu.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include "class.h"
#include <fstream>
#include "semester.h"
#include "schoolyear.h"
#include "student.h"
#include "staff.h"
using namespace std;

void menu()
{
	Course *cHead = nullptr;
	student *sStart = nullptr;
	Class *c = nullptr;
	staff *sHead = nullptr;
	schoolyear s;
	input(sHead, s, c, sStart, cHead);
	int choice;
	staff *cur1;
	student *cur2;
	do
	{
		cout << "Course Management System" << endl;
		cout << "-------------------------------" << endl;
		cout << setw(25) << setfill(' ') << "1. Staff" << endl;
		cout << setw(25) << setfill(' ') << "2. Student" << endl;
		cout << setw(25) << setfill(' ') << "3. Exit" << endl;
		cout << "-------------------------------" << endl;
		cout << "Input your choice (1-3): ";

		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			cur1 = login1(sHead);
			cin.get();
			system("cls");
			staffmenu(cur1, sHead, s, c, sStart, cHead);
			break;
		case 2:
			system("cls");
			cur2 = login2(sStart);
			cin.get();
			system("cls");
			studentmenu(cur2);
			break;
		case 3:
			system("cls");
			output(sHead, s, c, sStart, cHead);
			cout << "Thanks for using";
			cin.get();
			return;
		default:
			cout << "Invalid choice" << endl;
			break;
		}

	} while (choice != 3);
}
void staffmenu(staff *a, staff *&sHead, schoolyear &s, Class *&c, student *&sStart, Course *&course)
{
	if (!a)
		return;
	int choice;
	do
	{
		system("cls");
		cout << "****************************************" << endl;
		cout << setw(20) << "Welcome " << a->id << endl;
		cout << "****************************************" << endl;
		cout << setw(20) << "1. My account" << endl;
		cout << setw(20) << "2. Staff's activities" << endl;
		cout << setw(20) << "3. Log out" << endl;
		cout << "****************************************" << endl;
		cout << "Input your choice (1-3): ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			cout << "Staff profile" << endl;
			cout << "Your id: " << a->id << endl;
			cout << "Your account's password: " << a->password << endl;
			cin.ignore();
			cin.get();
			break;
		case 2:
			int choice2;
			do
			{
				system("cls");
				std::cout << std::setw(50) << std::setfill('*') << "" << std::endl;
				std::cout << std::setw(50) << std::setfill(' ') << std::left << "SCHOOL YEAR" << std::endl;
				std::cout << std::setw(50) << std::setfill('*') << "" << std::endl;
				std::cout << std::setw(50) << std::setfill(' ') << std::left << "1. Create School Year" << std::endl;
				std::cout << std::setw(50) << std::setfill(' ') << std::left << "2. Create New Class" << std::endl;
				std::cout << std::setw(50) << std::setfill(' ') << std::left << "3. Add Student into Class" << std::endl;
				std::cout << std::setw(50) << std::setfill(' ') << std::left << "4. Import Student from CSV File" << std::endl;
				std::cout << std::setw(50) << std::setfill(' ') << std::left << "5. Create Semester" << std::endl;
				std::cout << std::setw(50) << std::setfill(' ') << std::left << "6. Course Management" << std::endl;
				std::cout << std::setw(50) << std::setfill(' ') << std::left << "7. View a List of Class" << std::endl;
				std::cout << std::setw(50) << std::setfill(' ') << std::left << "8. View a List of All Students in a Class" << std::endl;
				std::cout << std::setw(50) << std::setfill(' ') << std::left << "9. View a List of All Courses" << std::endl;
				std::cout << std::setw(50) << std::setfill(' ') << std::left << "10. View a List of Students in a Course" << std::endl;
				std::cout << std::setw(50) << std::setfill(' ') << std::left << "11. End a Semester" << std::endl;
				std::cout << std::setw(50) << std::setfill(' ') << std::left << "12. Delete School Year" << std::endl;
				std::cout << std::setw(50) << std::setfill(' ') << std::left << "13. Create Staff Account" << std::endl;
				cout << "14.Change account's password" << endl;
				std::cout << std::setw(50) << std::setfill(' ') << std::left << "15. Back" << std::endl;
				std::cout << std::setw(50) << std::setfill('*') << "" << std::endl;
				std::cout << std::setw(50) << std::setfill(' ') << std::left << "Enter your choice (1-15): ";
				cin >> choice2;
				switch (choice2)
				{
				case 1:
					system("cls");
					createschoolyear(s);
					break;
				case 2:
					system("cls");
					createclass(c);
					break;
				case 3:
					system("cls");
					AddStudentFromKeyBoard(sStart);
					break;
				case 4:
					system("cls");
					inputfile(s, sStart);
					break;
				case 5:
					system("cls");
					createsemester(s);
					break;
				case 6:
					int choice3;
					do
					{
						system("cls");
						cout << "****************************************************" << endl;
						cout << "*              COURSE MANAGEMENT MENU               *" << endl;
						cout << "****************************************************" << endl;
						cout << setw(30) << left << "* 1. Create new course"
							 << "*" << endl;
						cout << setw(30) << left << "* 2. Update course"
							 << "*" << endl;
						cout << setw(30) << left << "* 3. Delete course"
							 << "*" << endl;
						cout << setw(30) << left << "* 4. Add student to course"
							 << "*" << endl;
						cout << setw(30) << left << "* 5. Add student to course from csv file"
							 << "*" << endl;
						cout << setw(30) << left << "* 6. Remove student from course"
							 << "*" << endl;
						cout << "7.Import scoreboard for course" << endl;
						cout << "8.View scoreboard" << endl;
						cout << "9.Update a student's result" << endl;
						cout << "10.View scoreboard of a class" << endl;
						cout << "11.Export student to a csv file" << endl;
						cout << setw(30) << left << "* 12. Back"
							 << "*" << endl;
						cout << "****************************************************" << endl;
						cout << "Input your choice (1-12): ";

						cin >> choice3;
						switch (choice3)
						{
						case 1:
							system("cls");
							addCourse(course);
							break;
						case 2:
							system("cls");
							updatecourse(course);
							break;
						case 3:
							system("cls");
							deleteCourse(course);
							break;
						case 4:
							system("cls");
							addonestudent(course);
							break;
						case 5:
							system("cls");
							addStudentToCourse(course);
							break;
						case 6:
							system("cls");
							deleteonestudent(course);
							break;
						case 7:
							system("cls");
							getmark(course, sStart);
							break;
						case 8:
							system("cls");
							viewscoreboard(course, sStart);
							break;
						case 9:
							system("cls");
							updateresult(course, sStart);
							break;
						case 10:
							system("cls");
							viewscoreofclass(course, s, c, sStart);
							break;
						case 11:
							system("cls");
							exportToCSVFile(course, sStart);
							break;
						default:
							cout << "Invalid choice" << endl;
							break;
						}
					} while (choice3 != 12);
					break;
				case 7:
					system("cls");
					viewlistclass(c);
					break;
				case 8:
					system("cls");
					viewlistofstudentinclass(c, sStart);
					break;
				case 9:
					system("cls");
					viewlistcourse(course);
					break;
				case 11:
					system("cls");
					endsemester(s);
					cin.get();
					break;
				case 12:
					system("cls");
					deleteschoolyear(s);
					cin.get();
					break;
				case 13:
					system("cls");
					regis(sHead);
					cin.get();
					break;
				case 14:
					system("cls");
					changepassword1(a);
					break;
				default:
					cout << "Invalid choice" << endl;
					break;
				}
			} while (choice2 != 15);
			break;
		case 3:
			system("cls");
			break;
		}
	} while (choice != 3);
}

void studentmenu(student *s, Course *course, schoolyear sy)
{
	int choice;
	do
	{
		cout << "***************************************************" << endl;
		cout << "*             STUDENT SCORE MANAGEMENT            *" << endl;
		cout << "***************************************************" << endl;
		cout << "1. My profile" << endl;
		cout << "*         2. View courses                          *" << endl;
		cout << "*         3. View score board                      *" << endl;
		cout << "4. Change account's password" << endl;
		cout << "*         5. Logout                                *" << endl;
		cout << "***************************************************" << endl;
		cout << "Enter your choice (1-5): ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			cin.ignore();
			cout << "YOUR PROFILE" << endl;
			cout << "Student ID:" << s->studentID << endl;
			cout << "Last Name:" << s->lastName << endl;
			cout << "First Name:" << s->firstName << endl;
			cout << "Day of birth:" << s->dateOfBirth << endl;
			cout << "Gender:" << s->gender << endl;
			cout << "Class:" << s->className << endl;
			cout << "Social ID:" << s->socialID << endl;
			cout << "Enter to quit";
			cin.get();
			break;
		case 2:
			system("cls");
			viewcourse(course, s, sy);
			break;
		case 3:
			system("cls");
			viewownscore(course, s);
			break;
		case 4:
			system("cls");
			break;
		case 5:
			system("cls");
			break;
		default:
			cout << "Invalid choice" << endl;
			break;
		}
	} while (choice != 5);
}
