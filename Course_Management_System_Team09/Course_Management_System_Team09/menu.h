#pragma once
#include"staff.h"

bool checkexist(staff* sHead, string id);

void regis(staff*& sHead, string id, string password);

staff* login(staff* s, string id, string password);
void staffmenu(staff* a);
void menu();
