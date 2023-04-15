#include"menu.h"
#include<iostream>
#include<string>
#include<stdlib.h>
#include"class.h"
#include<fstream>
#include"semester.h"
#include"schoolyear.h"
#include"student.h"
#include"staff.h"
using namespace std;



void menu() {
	Course* cHead = nullptr;
	student* sStart = nullptr;
	Class* c = nullptr;
	staff* sHead = nullptr;
	schoolyear s;
	input(sHead, s, c, sStart, cHead);
	int choice;
	staff* cur1;
	student* cur2;
	do {
		cout << "Coursemanagement system" << endl;
		cout << "1.Staff" << endl;
		cout << "2.Student" << endl;
		cout << "3.Exit" << endl;
		cout << "Input your choice(1-3): ";
		cin >> choice;
		switch (choice) {
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
void staffmenu(staff* a, staff*& sHead, schoolyear& s, Class*& c, student*& sStart, Course*& course) {
	if (!a) return;
	int choice;
	do {
		system("cls");
		cout << "Welcome " << a->id << endl;
		cout << "1.My account" << endl;
		cout << "2.Staff's activities" << endl;
		cout << "3.Log out" << endl;
		cout << "Input your choice (1-3): ";
		cin >> choice;
		switch (choice) {
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
			do {
				system("cls");
				cout << "1.Create school year" << endl;
				cout << "2.Create new class" << endl;
				cout << "3.Add student into class" << endl;
				cout << "4.Import student from CSV file" << endl;
				cout << "5.Create semester" << endl;
				cout << "6.Course management" << endl;
				cout << "7.View a list of class" << endl;
				cout << "8.View a list of all students in a class" << endl;
				cout << "9.View a list of all courses" << endl;
				cout << "10.View a list of students in a course" << endl;
				cout << "11.End a semester" << endl;
				cout << "12.Delete school year " << endl;
				cout << "13.Create staff account" << endl;
				cout << "14.Back" << endl;
				cout << "Input your choice (1-14): ";
				cin >> choice2;
				switch (choice2) {
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
					do {
						system("cls");
						cout << "1.Create new course" << endl;
						cout << "2.Update course" << endl;
						cout << "3.Delete course" << endl;
						cout << "4.Add student to course" << endl;
						cout << "5.Add student to course from csv file" << endl;
						cout << "6.Remove student from course" << endl;
						cout << "7.Back" << endl;
						cout << "Input your choice(1-7):";
						cin >> choice3;
						switch (choice3) {
						case 1:
							system("cls");
							addCourse(course);
							break;
						case 2:
							system("cls");
							/*Course1.updateCourse();*/
							break;
						case 3:
							system("cls");
							deleteCourse(course);
							break;
						case 4:
							system("cls");
							/*Course1.addOnestudent();*/
							break;
						case 5:
							system("cls");

							break;
						case 6:
							system("cls");
							/*Course1.deleteOneStudent();*/
							break;
						case 7:
							system("cls");
							break;
						default:
							cout << "Invalid choice" << endl;
							break;
						}
					} while (choice3 != 7);
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
					break;
				default:
					cout << "Invalid choice" << endl;
					break;
				}
			} while (choice2 != 14);
			break;
		case 3:
			system("cls");
			break;
		}
	} while (choice != 3);
}


void studentmenu(student* s) {
	int choice;
	do {
		cout << "1. View courses" << endl;
		cout << "2. View score board" << endl;
		cout << "3. Logout" << endl;
		cout << "Enter your choice(1-3): ";
		cin >> choice;
		switch (choice) {
		case 1:
			system("cls");
			/*viewCourses();*/
			break;
		case 2:
			system("cls");
			/*viewScoreBoard();*/
			break;
		case 3:
			system("cls");
			break;
		default:
			cout << "Invalid choice" << endl;
			break;
		}
	} while (choice != 3);
}
