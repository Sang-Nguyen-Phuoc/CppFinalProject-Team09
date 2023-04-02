#include<iostream>
#include<string>
#include"menu.h"
#include<stdlib.h>
#include<fstream>
using namespace std;

int main() {
	fstream staffaccount;
	staffaccount.open("staffaccount.txt", fstream::in | fstream::out);
	staff* sHead = nullptr;
	if (!staffaccount.is_open())
	{
		cout << "Khong mo duoc file!";
		return 0;
	}
	string id;
	string password;
	while (!staffaccount.eof()) {
		staffaccount >> id;
		staffaccount >> password;
		staff* temp = new staff;
		temp->id.assign(id);
		temp->password.assign(password);
		temp->next = sHead;
		sHead = temp;
	}
	staffaccount.close();
	menu(sHead);
	return 0;
}
