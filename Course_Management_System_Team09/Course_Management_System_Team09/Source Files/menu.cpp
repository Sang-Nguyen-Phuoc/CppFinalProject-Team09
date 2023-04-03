#include"menu.h"
#include<iostream>
#include<string>
#include<stdlib.h>
#include"class.h"
#include "menu.h"
using namespace std;



void menu(staff*& sHead) {
	Class* listclass;
	string schoolyear;
	string id;
	string password;
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
			cur=login(sHead, id, password);
			cout << "Press enter to continue";
			cin.get();
			system("cls");
			staffmenu(cur,sHead,schoolyear,listclass);
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

void staffmenu(staff* a,staff*& sHead,string& schoolyear,Class*& listclass ) {
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
				cout << "11.End of a semester" << endl;
				cout << "12.Create staff account" << endl;
				cout << "13.Back" << endl;
				cout << "Input your choice (1-13): ";
				cin >> choice2;
				switch (choice2) {
				case 1:
					system("cls");
					createschoolyear(schoolyear);
					break;
				case 2:
					system("cls");
					createclass(listclass);
					break;
				case 12:
					system("cls");
					regis(sHead);
					cin.get();
					break;
				case 13:
					system("cls");
					break;
				}
			} while (choice2 != 13);
			break;
		case 3:
			system("cls");
			break;
		}
	} while (choice != 3);
}
