#include"menu.h"
#include<iostream>
#include<string>
#include<stdlib.h>
#include"class.h"
#include<fstream>
#include"semester.h"
#include"schoolyear.h"
using namespace std;


void menu() {
	semester s;
	fstream staffaccount;
	staffaccount.open("staffaccount.txt", fstream::in | fstream::out);
	staff* sHead = nullptr;
	string id;
	string password;
	while (!staffaccount.eof()) {
		staffaccount >> id;
		staffaccount >> password;
		staff* temp = new staff;
		temp->id.assign(id);
		temp->password.assign(password);
		temp->next = sHead;
		sHead = temp;
	}
	staffaccount.close();
	schoolyear sy;
	ifstream f;
	f.open("schoolyear.txt");
	f >> sy.year;
	f >> sy.datestart >> sy.dateend;
	f >> s.s1 >> s.s2 >> s.s3;
	f.close();
	int choice;
	staff* cur;
	do {
		cout << "Coursemanagement system" << endl;
		cout << "1.Staff" << endl;
		cout << "2.Student" << endl;
		cout << "3.Exit" << endl;
		cout << "Input your choice(1-2): ";
		cin >> choice;
		switch (choice) {
		case 1:
			system("cls");
			cout << "Input id: ";
			cin.ignore();
			getline(cin, id);
			cout << "Input password: ";
			getline(cin, password);
			cur = login(sHead, id, password);
			cout << "Press enter to continue";
			cin.get();
			system("cls");
			staffmenu(cur, sHead, sy, s);
			break;
		case 2:
			//same as 1
			break;
		case 3:
			system("cls");
			cout << "Thanks for using";
			cin.get();
			return;
		}

	} while (choice != 3);
}
void staffmenu(staff* a, staff*& sHead, schoolyear& sy, semester& s) {
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
					createschoolyear(sy);
					break;
				case 2:
					system("cls");
					break;
				case 5:
					system("cls");
					createsemester(sy, s);
					break;
				case 6:
					system("cls");
					Course Course1;
					cin >> choice3;
					cout << "1.Create new course" << endl;
					cout << "2.Update course" << endl;
					cout << "3.Delete course" << endl;
					cout << "4.Add student to course" << endl;
					cout << "5.Remove student from course" << endl;	
					switch (choice3) {
					case 1:
					system("cls");
					Course1.init();
					break;
					case 2:
					system("cls");
					Course1.updateCourse();
					break;
					case 3:
					system("cls");
					Course1.deleteCourse();
					break;
					case 4:
					system("cls");
					Course1.addOnestudent();
					break;
					case 5:
					system("cls");
					Course1.deleteOneStudent();
					break;
				}
				while (choice3 != 5);
				break;
				case 11:
					system("cls");
					endsemester(sy, s);
					cin.get();
					break;
				case 12:
					system("cls");
					deleteschoolyear(sy);
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
				}
			} while (choice2 != 14);
			break;
		case 3:
			system("cls");
			break;
		}
	} while (choice != 3);
}
