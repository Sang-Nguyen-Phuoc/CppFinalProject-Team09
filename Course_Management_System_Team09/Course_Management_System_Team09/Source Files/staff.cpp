#include"staff.h"
#include<iostream>
#include<fstream>

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
	ofstream ofs;
	ofs.open("staffaccount.txt", ios::app);
	ofs << id << endl;
	ofs << password << endl;
	ofs.close();
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


void createschoolyear(schoolyear& sy) {
	if (sy.year.length()) {
		cout << "schoolyear existed";
		cin.ignore();
		cin.get();
		return;
	}
	cout << "Input schoolyear: ";
	cin.ignore();
	getline(cin, sy.year);
	cout << "School year begin from:";
	cin.ignore();
	getline(cin, sy.datestart);
	cout << "To:";
	cin.ignore();
	getline(cin, sy.dateend);
	ofstream ofs;
	ofs.open("schoolyear.txt.");
	ofs << sy.year << " " << sy.datestart << " " << sy.dateend;
	ofs.close();
	cout << "create success";
	cin.get();
}

void deleteschoolyear(schoolyear& sy) {
	if (!sy.year.length()) {
		cout << "No existed schoolyear";
		cin.get();
		return;
	}
	fstream f;
	f.open("schoolyear.txt", ios::out);
	f << "";
	f.close();
	sy.year = "";
	cout << "Delete success";
	cin.get();
}

void createsemester(schoolyear sy, semester& s) {
	if (!sy.year.length()) {
		cout << "No schoolyear existed";
		cin.ignore();
		cin.get();
		return;
	}
	if (s.s1 || s.s2 || s.s3) {
		cout << "Semester in progress";
		cin.ignore();
		cin.get();
		return;
	}
	int choice;
	do {
		cout << "Choose semester you want to create" << endl;
		cout << "1.Semester 1" << endl;
		cout << "2.Semester 2" << endl;
		cout << "3.Semester 3" << endl;
		cout << "4.Back" << endl;
		cout << "Input your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			system("cls");
			s.s1 = 1;
			cout << "Create success";
			addsemester(sy, s);
			cin.ignore();
			cin.get();
			return;
		case 2:
			system("cls");
			s.s2 = 1;
			cout << "Create success";
			addsemester(sy, s);
			cin.ignore();
			cin.get();
			return;
		case 3:
			system("cls");
			s.s3 = 1;
			cout << "Create success";
			addsemester(sy, s);
			cin.ignore();
			cin.get();
			return;
		}
	} while (choice != 4);
}

void addsemester(schoolyear sy, semester s) {
	ofstream ofs;
	ofs.open("schoolyear.txt");
	ofs << sy.year << " " << sy.datestart << " " << sy.dateend;
	ofs << s.s1 << " " << s.s2 << " " << s.s3;
	ofs.close();
}

void endsemester(schoolyear sy, semester& s) {
	if (!s.s1 && !s.s2 && !s.s3) {
		cout << "No semester in progress";
		cin.ignore();
		return;
	}
	s.s1 = 0;
	s.s2 = 0;
	s.s3 = 0;
	ofstream ofs;
	ofs.open("schoolyear.txt");
	ofs << sy.year << " " << sy.datestart << " " << sy.dateend;
	ofs << s.s1 << " " << s.s2 << " " << s.s3;
	ofs.close();
	cout << "The current semester has ended";
	cin.ignore();
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
