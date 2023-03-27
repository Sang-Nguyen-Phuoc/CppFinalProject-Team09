#include"staff.h"
#include<fstream>
#include<stdlib.h>
#include<string>


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
