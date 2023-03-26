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




