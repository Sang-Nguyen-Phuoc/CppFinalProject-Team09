#include"staff.h"
#include<iostream>


using namespace std;

bool checkexist(staff* sHead, string id) {
	while (sHead) {
		if (sHead->id == id) return 1;
		sHead = sHead->next;
	}
	return 0;
}

void regis(staff*& sHead) {
	string id;
	string password;
	cout << "Input id: ";
	cin.ignore();
	getline(cin, id);
	cout << "Input password: ";
	getline(cin, password);
	if (checkexist(sHead, id)) {
		cout << "id da ton tai, vui long chon id khac" << endl;
		return;
	}
	staff* temp = new staff;
	temp->id = id;
	temp->password = password;
	temp->next = sHead;
	sHead = temp;
	cout << "Register success" << endl;
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

void createschoolyear(string& schoolyear) {
	cout << "Input schoolyear: ";
	getline(cin, schoolyear);
	cin.get();
}


void createclass(Class*& listclass) {
	string temp;
	cout << "Input list class for 1st-year students (quit to stop): ";
	do {
		getline(cin, temp);
		if (temp != "quit") {
			Class* cur = new Class;
			cur->classname = temp;
			cur->next = listclass;
			listclass = cur;
		}
		else break;
	} while (true);
}
