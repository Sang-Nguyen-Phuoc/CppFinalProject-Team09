#include"staff.h"
#include<iostream>
#include<fstream>
#include"student.h"
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
	ofstream ofs;
	ofs.open("schoolyear.txt.");
	ofs << sy.year << endl;
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
	cin.ignore();
	string temp;
	do {
		cout << "Input list class for 1st-year students (quit to stop): ";
		getline(cin, temp);
		if (temp != "quit") {
			Class* cur = new Class;
			cur->classname = temp;
			cur->next = listclass;
			listclass = cur;
			ofstream ofs;
			ofs.open("listclass.txt", ios::app);
			ofs << temp << endl;
			ofs.close();
		}
		else break;
	} while (true);
}

void AddStudentFromKeyBoard(student*& head) {
	// Input student information from keyboard
	student* newStudent = new student;
	cout << "Enter student ID: ";
	cin >> newStudent->studentID;
	cin.ignore();
	cout << "Enter first name: ";
	cin >> newStudent->firstName;
	cin.ignore();
	cout << "Enter last name: ";
	cin >> newStudent->lastName;
	cin.ignore();
	cout << "Enter gender: ";
	cin >> newStudent->gender;
	cin.ignore();
	cout << "Enter date of birth: ";
	cin >> newStudent->dateOfBirth;
	cin.ignore();
	cout << "Enter class name: ";
	cin >> newStudent->className;
	cin.ignore();
	cout << "Enter social ID: ";
	cin >> newStudent->socialID;
	cin.ignore();

	// Check if the student ID is unique
	student* current = head;
	while (current != nullptr) {
		if (current->studentID == newStudent->studentID) {
			cout << "Error: student ID already exists" << endl;
			return;
		}
		current = current->next;
	}
	newStudent->next = head;
	head = newStudent;
	ofstream of;
	of.open("liststudent.txt", ios::app);
	of << newStudent->studentID << endl << newStudent->firstName << endl << newStudent->lastName << endl << newStudent->className << endl << newStudent->gender << endl << newStudent->dateOfBirth << endl << newStudent->socialID << endl;
	of.close();
}



void inputfile(semester s, student*& sStart) {
	if (s.s1 != 1 && s.s2 != 1 && s.s3 != 1) {
		cin.ignore();
		cout << "No semester in progress";
		cin.get();
		return;
	}
	string filename;
	cin.ignore();
	cout << "Input file:";
	getline(cin, filename);
	ifstream f;
	f.open(filename);
	if (!f.is_open()) {

		cerr << "Error: could not open file " << filename << endl;
		cin.get();
		return;
	}

	string line;
	while (getline(f, line)) {
		stringstream ss(line);
		string field;
		vector<string> fields;
		while (getline(ss, field, ',')) {
			fields.push_back(field);
		}
		student* newStudent = new student;
		newStudent->studentID = stoi(fields[0]);
		newStudent->firstName = fields[1];
		newStudent->lastName = fields[2];
		newStudent->className = fields[3]; 
		newStudent->gender = fields[4];
		newStudent->dateOfBirth = fields[5];
		newStudent->socialID = fields[6];
		newStudent->next = sStart;
		sStart = newStudent;
	}
	f.close();
	ofstream of;
	of.open("liststudent.txt");
	student* cur = sStart;
	while (cur) {
		of << cur->studentID << endl << cur->firstName << endl << cur->lastName << endl << cur->className << endl << cur->gender << endl << cur->dateOfBirth << endl << cur->socialID << endl;
		cur = cur->next;
	}
	of.close();
	cin.ignore();
	cout << "Input success";
	cin.get();
}

void viewlistclass(Class* c) {
	cin.ignore();
	if (!c) {
		cout << "No class existed";
		cin.get();
		return;
	}
	cout << "LIST OF CLASS" << endl;
	int i = 1;
	while (c) {
		cout << i << "." << c->classname << endl;
		c = c->next;
		i++;
	}

	cout << "Enter to quit";
	cin.get();
}

void viewlistofstudentinclass(Class* c, student* sStart) {
	if (!c) {
		cin.ignore();
		cout << "No class existed";
		cin.get();
		return;
	}
	if (!sStart) {
		cin.ignore();
		cout << "No student existed";
		cin.get();
		return;
	}
	cin.ignore();

	cout << "Choose class you want" << endl;
	Class* cur = c;
	int i = 1;
	while (cur) {
		cout << i << "." << cur->classname << endl;
		i++;
		cur = cur->next;
	}
	string name;
	cout << "Input (name):";
	getline(cin, name);
	while (c->classname != name) {
		c = c->next;
	}

	system("cls");
	cout << "CLASS " << c->classname << endl;
	i = 1;
	cout << "No	Student ID	Last Name	First Name	Gender	Date of birth	Social ID" << endl;
	while (sStart) {
		if (sStart->className == name) {
			cout << i << "	" << sStart->studentID << "	" << sStart->lastName << "	" << sStart->firstName << "	" << sStart->gender << "	" << sStart->dateOfBirth << "	" << sStart->socialID << endl;
			i++;
		}
		sStart = sStart->next;
	}
	cin.get();
	return;
}


