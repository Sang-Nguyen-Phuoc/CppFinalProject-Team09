#include"staff.h"
#include<iostream>
#include<fstream>
#include"student.h"
#include"schoolyear.h"
using namespace std;

void exportToCSVFile(Course* course)
{
    string filename = course->courseID + "_Students.csv"; // The filename is the course ID followed by "_Students.csv"
    ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        cout << "Failed to create the file." << endl;
        return;
    }

    // Write the header row
    outputFile << "Student ID,First Name,Last Name,Gender,Class Name,Date of Birth,Social ID,Total Mark,Final Mark,Midterm Mark,Other Mark\n";

    // Iterate over the list of students and write each one to the file
    student* pHead = course->liststudent;
    while (pHead != nullptr) {
        outputFile << pHead->studentID << ",";
        outputFile << pHead->firstName << ",";
        outputFile << pHead->lastName << ",";
        outputFile << pHead->gender << ",";
        outputFile << pHead->className << ",";
        outputFile << pHead->dateOfBirth << ",";
        outputFile << pHead->socialID << ",";
        outputFile << pHead->totalMark << ",";
        outputFile << pHead->finalMark << ",";
        outputFile << pHead->midtermMark << ",";
        outputFile << pHead->otherMark << "\n";
        pHead = pHead->next;
    }

    // Close the file
    outputFile.close();
    cout << "Exported the list of students to " << filename << "." << endl;
}

void getPoints(string filename, student *&head)
{
    ifstream file(filename);
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string data;
        student *temp = new student;
        getline(ss, temp->studentID, ',');
        getline(ss, temp->firstName, ',');
        getline(ss, temp->lastName, ',');
        getline(ss, temp->className, ',');
        getline(ss, temp->totalMark, ',');
        getline(ss, temp->finalMark, ',');
        getline(ss, temp->midtermMark, ',');
        getline(ss, temp->otherMark, ',');
        if (head == nullptr)
        {
            head = temp;
        }
        else
        {
            student *curr = head;
            while (curr->next != nullptr)
            {
                curr = curr->next;
            }
            curr->next = temp;
        }
    }
    file.close();
}

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

staff* login1(staff* sHead) {
	string id;
	string password;
	cout << "Input id: ";
	cin.ignore();
	getline(cin, id);
	cout << "Input password: ";
	getline(cin, password);

	while (sHead) {
		if (sHead->id == id && sHead->password == password) {
			cout << "Login success" << endl;
			return sHead;
		}
		sHead = sHead->next;
	}
	if (!sHead) cout << "ID doesn't exist" << endl;
	cout << "Press enter to continue";
	return nullptr;
}


void createschoolyear(schoolyear& s) {
	if (s.year.length()) {
		cout << "schoolyear existed";
		cin.ignore();
		cin.get();
		return;
	}
	cout << "Input schoolyear: ";
	cin.ignore();
	getline(cin, s.year);
	cout << "create success";
	cin.get();
}

void deleteschoolyear(schoolyear& s) {
	if (!s.year.length()) {
		cout << "No existed schoolyear";
		cin.get();
		return;
	}
	s.year = "";
	cout << "Delete success";
	cin.get();
}

void createsemester(schoolyear& s) {
	if (!s.year.length()) {
		cout << "No schoolyear existed";
		cin.ignore();
		cin.get();
		return;
	}
	if (s.s1 == 1 || s.s2 == 1 || s.s3 == 1) {
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
			if (s.s1 == 2) {
				cin.ignore();
				cout << "Semester 1 has ended before";
				cin.get();
				system("cls");
				break;
			}
			s.s1 = 1;
			cout << "Create success";
			cin.ignore();
			cin.get();
			return;
		case 2:
			system("cls");
			if (s.s1 == 0) {
				cin.ignore();
				cout << "Semester 1 end required";
				cin.get();
				system("cls");
				break;
			}
			if (s.s2 == 2) {
				cin.ignore();
				cout << "Semester 2 has ended before";
				cin.get();
				system("cls");
				break;
			}
			s.s2 = 1;
			cout << "Create success";
			cin.ignore();
			cin.get();
			return;
		case 3:
			system("cls");
			if (s.s2 == 0) {
				cin.ignore();
				cout << "Semester 2 end required";
				cin.get();
				system("cls");
				break;
			}
			if (s.s3 == 2) {
				cin.ignore();
				cout << "Semester 3 has ended before";
				cin.get();
				system("cls");
				break;
			}
			s.s3 = 1;
			cout << "Create success";
			cin.ignore();
			cin.get();
			return;
		}
	} while (choice != 4);
}


void endsemester(schoolyear s) {
	if (s.s1 != 1 && s.s2 != 1 && s.s3 != 1) {
		cout << "No semester in progress";
		cin.ignore();
		return;
	}
	if (s.s1 == 1) s.s1 = 2;
	if (s.s2 == 1) s.s2 = 2;
	if (s.s3 == 1) s.s3 = 2;
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
		}
		else break;
	} while (true);
}
//
//void AddStudentFromKeyBoard(student*& head) {
//	// Input student information from keyboard
//	student* newStudent = new student;
//	cout << "Enter student ID: ";
//	cin >> newStudent->studentID;
//	cin.ignore();
//	cout << "Enter first name: ";
//	cin >> newStudent->firstName;
//	cin.ignore();
//	cout << "Enter last name: ";
//	cin >> newStudent->lastName;
//	cin.ignore();
//	cout << "Enter gender: ";
//	cin >> newStudent->gender;
//	cin.ignore();
//	cout << "Enter date of birth: ";
//	cin >> newStudent->dateOfBirth;
//	cin.ignore();
//	cout << "Enter class name: ";
//	cin >> newStudent->className;
//	cin.ignore();
//	cout << "Enter social ID: ";
//	cin >> newStudent->socialID;
//	cin.ignore();
//
//	// Check if the student ID is unique
//	student* current = head;
//	while (current != nullptr) {
//		if (current->studentID == newStudent->studentID) {
//			cout << "Error: student ID already exists" << endl;
//			return;
//		}
//		current = current->next;
//	}
//	newStudent->next = head;
//	head = newStudent;
//	ofstream of;
//	of.open("liststudent.txt", ios::app);
//	of << newStudent->studentID << endl << newStudent->firstName << endl << newStudent->lastName << endl << newStudent->className << endl << newStudent->gender << endl << newStudent->dateOfBirth << endl << newStudent->socialID << endl;
//	of.close();
//}



void inputfile(schoolyear s, student*& sStart) {
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
		newStudent->studentID = fields[0];
		newStudent->firstName = fields[1];
		newStudent->lastName = fields[2];
		newStudent->className = fields[3];
		newStudent->gender = fields[4];
		newStudent->dateOfBirth = fields[5];
		newStudent->socialID = fields[6];
		newStudent->next = sStart;
		sStart = newStudent;
	}
	cin.ignore();
	cout << "Input success";
	cin.get();
	f.close();
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
}



void viewlistcourse(Course* course) {
	cin.ignore();
	if (!course) {
		cout << "No course existed";
		cin.get();
		return;
	}
	cout << "LIST OF COURSE" << endl;
	int i = 1;
	while (course) {
		cout << i << "." << course->courseName << endl;
		i++;
		course = course->next;
	}
	cout << "Enter to quit";
	cin.get();
}



