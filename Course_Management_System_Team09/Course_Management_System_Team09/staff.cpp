#include"staff.h"
#include<fstream>
#include<stdlib.h>
#include<string>


using namespace std;
void staff::login() {
	
}

void staff::regis() {

}

void staff::exit() {

}

void staff::logout() {

}

void staffmenu(staff a) {
	system("cls");
	int choice;
	cout << "Welcome" <<a.id<< endl;
	cout << "1.My account" << endl;
	cout << "2.Staff's activities" << endl;
	cout << "3.Log out" << endl;
	cout << "Input your choice (1-3): ";
	cin >> choice;
	switch (choice) {
		case 1:
			system("cls");
			cout << "Staff profile" << endl;
			cout << "Your id: " << a.id << endl;
			cout << "Your account's password: " << a.password << endl;
		case 2:
			system("cls");
			int choice2;
			cout << "1.Create school year" << endl;
			cout << "2.Create new class" << endl;
			cout << "3.Add student into class" << endl;
			cout << "4.Import student from CSV file" << endl;
			cout << "5.Create semester" << endl;
			cout << "6.View a list of class" << endl;
			cout << "7.View a list of all students in a class" << endl;
			cout << "8.View a list of all courses" << endl;
			cout << "9.View a list of students in a course" << endl;
			cout << "10.End of a semester" << endl;
			cout << "11.Back" << endl;
			cout << "Input your choice (1-11): ";
			cin >> choice2;
			switch (choice2) {
				case 1:
					createschoolyear();
				case 2:
					createclass();
				case 3:

			}
		case 3: 

	}
}

void createschoolyear() {
	cout << "Enter school year: ";
	cin>>schoolyear;
}

void viewaccount(staff a) {
	cout << "Your id: " << a.id << endl;
	cout << "Your password: " << a.password << endl;
}

//void createsemester() {
//	if (schoolyear) {
//		cout << "You don't have school year";
//		return;
//	}
//	
//}