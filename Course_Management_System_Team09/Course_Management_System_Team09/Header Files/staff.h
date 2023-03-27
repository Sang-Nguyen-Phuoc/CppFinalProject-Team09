#pragma once
#include<iostream> 
#include<string> 

using namespace std;

struct staff {
	string id;
	string password;
	staff* next;


	void regis();
	void login();
	void viewaccount(staff a);
	void exit();
	void logout();

	//staff option 
	void staffmenu();
	void createschoolyear();
	void createsemester();
	void createclass();
	void addstudentintoclass();
	void ImportfromCSVfile();
	void view();
	void coursemanage();
};

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


