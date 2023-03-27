#include"menu.h"
#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

bool checkexist(staff* sHead, string id) {
	while (sHead) {
		if (sHead->id == id) return 1;
		sHead = sHead->next;
	}
	return 0;
}

void regis(staff*& sHead, string id, string password) {
	if (checkexist(sHead, id)) {
		cout << "id da ton tai, vui long chon id khac" << endl;
		return;
	}
	staff* temp = new staff;
	temp->id = id;
	temp->password = password;
	temp->next = sHead;
	sHead = temp;
	cout << "Sign up successfully" << endl;
}

staff* login(staff* sHead, string id, string password) {
	while (sHead) {
		if (sHead->id == id && sHead->password == password) {
			cout << "Login success" << endl;
			return sHead;
		}
		sHead = sHead->next;
	}
	if (!sHead) cout << "ID doesn't exist" << endl;
	return nullptr;
}


void menu() {
	staff* sHead = new staff;
	sHead->id = "admin";
	sHead->password = "1";
	sHead->next = nullptr;
	string id;
	string password;
	int choice;
	staff* cur = nullptr;
	do {
		cout << "Course management system" << endl;
		cout << "1.Staff" << endl;
		cout << "2.Student" << endl;
		cout << "3.Exit" << endl;
		cout << "Input your choice(1-3): ";
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
			staffmenu(cur);
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

void staffmenu(staff* a) {
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
				cout << "5.Create a semester" << endl;
				cout << "6.View a list of class" << endl;
				cout << "7.View a list of all students in a class" << endl;
				cout << "8.View a list of all courses" << endl;
				cout << "9.View a list of students in a course" << endl;
				cout << "10.End of a semester" << endl;
				cout << "11.Back" << endl;
				cout << "Input your choice (1-11): ";
				cin >> choice2;
			} while (choice2 != 11);
			break;
		case 3:
			system("cls");
			break;
		}
	} while (choice != 3);
}