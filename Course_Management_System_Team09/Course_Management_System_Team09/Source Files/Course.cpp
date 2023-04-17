#include "Course.h"
#include<string>
#include"class.h"
using namespace std;

void addCourse(Course*& course,schoolyear s) {
    if (!s.year.length()) {
        cout << "No schoolyear existed";
        cin.get();
        return;
    }
    if (s.s1!=1&&s.s2!=1&&s.s3!=1)  {
        cout << "No semester in progress";
        cin.get();
        return;
    }
	Course* temp = new Course;
	cout << "New course name: ";
	cin.ignore();
	getline(cin, temp->courseName);
	system("cls");
	cout << "Course ID: ";
	getline(cin, temp->courseID);
	system("cls");
	cout << "Day of week of the coure " << endl;
	cout << "1.Monday" << endl;
	cout << "2.Tuesday" << endl;
	cout << "3.Wednesday" << endl;
	cout << "4.Thursday" << endl;
	cout << "5.Friday" << endl;
	cout << "6.Saturday" << endl;
	cout << "7.Sunday" << endl;
	cout << "Your choice:";
	getline(cin, temp->dayofWeek);
	system("cls");
	cout << "Session time of the course: " << endl;
	cout << "1.S1(7:30)" << endl;
	cout << "2.S2(9:30)" << endl;
	cout << "3.S3(13:30)" << endl;
	cout << "4.S4(15:30)" << endl;
	cout << "Your choice:";
	getline(cin, temp->sessionTime);
	system("cls");
	cout << "Teacher of the course: ";
	getline(cin, temp->teacher);
	system("cls");
	cout << "Number of credits: ";
	cin >> temp->numberofCredits;
	cin.ignore();
	system("cls");
    temp->sc = s;
    if (!course) course = temp;
    else {
        Course* run = course;
        while (run->next) run = run->next;
        run->next = temp;
    }
	cout << "Add course success";
	cin.get();
}

void deleteCourse(Course*& course) {
    cin.ignore();
    if (!course) {
        cout << "No course existed";
        cin.get();
        return;
    }
    string name;
    cout << "Course you want to delete:";
    getline(cin, name);
    cin.ignore();
    Course* cur = course;
    if (cur->courseName == name) {
        course = course->next;
        delete cur;
        cout << "Delete success";
        cin.get();
        return;
    }
    Course* prev = cur;
    cur = cur->next;
    while (cur) {
        if (cur->courseName == name) {
            prev->next = cur->next;
            delete cur;
            cout << "Delete success";
            cin.get();
            return;
        }
    }
}

void viewliststudentincourse(Course* course) {
    cin.ignore();
    if (!course) {
        cout << "No course existed";
        cin.get();
        return;
    }
    Course* cur = course;
    int i = 1;
    cout << "Choose course you want:" << endl;
    while (cur) {
        cout << i << "." << cur->courseName << endl;
        i++;
        cur = cur->next;
    }
    string name;
    cout << "Input your choice:";
    cin >> name;
    cin.ignore();
    while (course->courseName != name) {
        course = course->next;
    }
    system("cls");
    cout << "No   Student ID  Last Name   First Name  " << endl;
    student* temp = course->liststudent;
    i = 1;
    while (temp) {
        cout << i << "    " << temp->studentID << "  " << temp->lastName << "    " << temp->firstName << endl;
        i++;
        temp = temp->next;
    }
    cin.get();
}

void addStudentToCourse(Course* course) {
    cin.ignore();
    if (!course) {
        cout << "No course existed";
        cin.get();
        return;
    }
    string filename;
    Course* cur = course;
    int i = 1;
    cout << "Choose course to add student into" << endl;
    while (course) {
        cout << i << "." << course->courseName << endl;
        i++;
        course = course->next;
    }
    cout << "Input your choice:";
    string name;
    getline(cin, name);
    while (cur) {
        if (cur->courseName != name) cur = cur->next;
        else break;
    }
    cout << "Input your file:";
    getline(cin, filename);
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string studentID, firstName, lastName, className;
        getline(ss, studentID, ',');
        getline(ss, firstName, ',');
        getline(ss, lastName, ',');
        getline(ss, className, ',');
        student* newStudent = new student;
        /*{ studentID, firstName, lastName, className, nullptr }*/
        newStudent->studentID = studentID;
        newStudent->firstName = firstName;
        newStudent->lastName = lastName;
        newStudent->className = className;
        if (cur->liststudent == nullptr) {
            cur->liststudent = newStudent;
        }
        else {
            student* current = cur->liststudent;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newStudent;
        }
        cur->numofstudent++;
    }
    file.close();
}

void getmark(Course* course,student* sHead) {
    cin.ignore();
    if (!course) {
        cout << "No course existed";
        cin.get();
        return;
    }
    Course* cur = course;
    cout << "List of course" << endl;
    int i = 1;
    while (cur) {
        cout << i << "." << cur->courseName << endl;
        cur = cur->next;
        i++;
    }
    string name;
    cout << "Choose course:";
    getline(cin, name);
    cur = course;
    while (cur) {
        if (cur->courseName == name) break;
        cur = cur->next;
    }
    string filename;
    cout << "Input file:";
    getline(cin, filename);
    ifstream file(filename);
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string data;
        student* temp = new student;
        string totalMark;
        string finalMark;
        string midtermMark;
        string otherMark;
        getline(ss, temp->studentID, ',');
        getline(ss, temp->firstName, ',');
        getline(ss, temp->lastName, ',');
        getline(ss, temp->className, ',');
        getline(ss, totalMark, ',');
        getline(ss, finalMark, ',');
        getline(ss, midtermMark, ',');
        getline(ss, otherMark, ',');
        student* run = sHead;
        while (run) {
            if (run->studentID == temp->studentID) break;
            run = run->next;
        }
        coursedata* Newdata = new coursedata;
        Newdata->courseName = name;
        Newdata->totalMark = totalMark;
        Newdata->finalMark = finalMark;
        Newdata->midtermMark = midtermMark;
        Newdata->otherMark = otherMark;
        run->numofcourse++;
        if (!run->listcourse) run->listcourse = Newdata;
        else {
            coursedata* run2 = run->listcourse;
            while (run2->next) run2 = run2->next;
            run2->next = Newdata;
        }
        delete temp;
    }
    file.close();
    cout << "Import succes";
    cin.get();
}

void updatecourse(Course* course) {
    cin.ignore();
    if (!course) {
        cout << "No course existed";
        cin.get();
        return;
    }
    Course* cur = course;
    cout << "List of course" << endl;
    int i = 1;
    while (cur) {
        cout << i << "." << cur->courseName << endl;
        cur = cur->next;
        i++;
    }
    string name;
    cout << "Choose course:";
    getline(cin, name);
    cur = course;
    while (cur) {
        if (cur->courseName == name) break;
        cur = cur->next;
    }
    cin.ignore();

    int choice;
    do {
        system("cls");
        cout << "Change properties" << endl;
        cout << "1.Course Name" << endl;
        cout << "2.Course ID" << endl;
        cout << "3.Day of week" << endl;
        cout << "4.Session time" << endl;
        cout << "5.Teacher" << endl;
        cout << "6.Back" << endl;
        cout << "Input your choice:";
        cin >> choice;
        switch (choice) {
        case 1:
            system("cls");
            changecoursename(cur);
            break;
        case 2:
            system("cls");
            changecourseID(cur);
            break;
        case 3:
            system("cls");
            changedayofweek(cur);
            break;
        case 4:
            system("cls");
            changesession(cur);
            break;
        case 5:
            system("cls");
            changeteacher(cur);
            break;
        case 6:
            system("cls");
            break;
        default:
            system("cls");
            cout << "Invalid choice";
            break;
        }
    } while (choice != 6);
}

void changecoursename(Course* course) {
    cin.ignore();
    string name;
    cout << "Current course name:" << course->courseName << endl;
    cout << "Input new course name (quit to quit):";
    getline(cin, name);
    if (name == "quit") return;
    course->courseName = name;
    cin.ignore();
    cout << "Change course name success" << endl;
    cout << "Enter to quit";
    cin.get();
}

void changecourseID(Course* course) {
    cin.ignore();
    string name;
    cout << "Current course ID:" << course->courseID<< endl;
    cout << "Input new course ID (quit to quit):";
    getline(cin, name);
    if (name == "quit") return;
    course->courseID = name;
    cin.ignore();
    cout << "Change course ID success" << endl;
    cout << "Enter to quit";
    cin.get();
}
void changedayofweek(Course* course) {
    cin.ignore();
    string name;
    cout << "Current day of week:" << course->dayofWeek << endl;
    cout << "Input new day of week (quit to quit):";
    getline(cin, name);
    if (name == "quit") return;
    course->dayofWeek = name;
    cin.ignore();
    cout << "Change day of week success" << endl;
    cout << "Enter to quit";
    cin.get();
}

void changesession(Course* course) {
    cin.ignore();
    string name;
    cout << "Current session time:" << course->sessionTime << endl;
    cout << "Input new session time (quit to quit):";
    getline(cin, name);
    if (name == "quit") return;
    course->sessionTime = name;
    cin.ignore();
    cout << "Change session time success" << endl;
    cout << "Enter to quit";
    cin.get();
}

void changeteacher(Course* course) {
    cin.ignore();
    string name;
    cout << "Current teacher:" << course->teacher << endl;
    cout << "Input new teacher name (quit to quit):";
    getline(cin, name);
    if (name == "quit") return;
    course->teacher = name;
    cin.ignore();
    cout << "Change teacher success" << endl;
    cout << "Enter to quit";
}


void addonestudent(Course* course) {
    cin.ignore();
    if (!course) {
        cout << "No course existed";
        cin.get();
        return;
    }
    Course* cur = course;
    cout << "List of course" << endl;
    int i = 1;
    while (cur) {
        cout << i << "." << course->courseName << endl;
        cur = cur->next;
        i++;
    }
    string name;
    cout << "Choose course:";
    getline(cin, name);
    cur = course;
    while (cur) {
        if (cur->courseName == name) break;
        cur = cur->next;
    }
    system("cls");
    student* temp = new student;
    cout << "Input student ID:";
    getline(cin, temp->studentID);
    cin.ignore();
    cout << "Input first name:";
    getline(cin, temp->firstName);
    cin.ignore();
    cout << "Input last name:";
    getline(cin, temp->lastName);
    cin.ignore();
    cout << "Input class name:";
    getline(cin, temp->className);
    cin.ignore();
    if (cur->liststudent == nullptr) {
        cur->liststudent = temp;
    }
    else {
        student* current = cur->liststudent;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = temp;
    }
    cur->numofstudent++;
    cout << "Input success" << endl;
    cout << "Enter to quit";
    cin.get();
}

void deleteonestudent(Course* course) {
    cin.ignore();
    if (!course) {
        cout << "No course existed";
        cin.get();
        return;
    }
    Course* cur = course;
    cout << "List of course" << endl;
    int i = 1;
    while (cur) {
        cout << i << "." << course->courseName << endl;
        cur = cur->next;
        i++;
    }
    string name;
    cout << "Choose course:";
    getline(cin, name);
    cur = course;
    while (cur) {
        if (cur->courseName == name) break;
        cur = cur->next;
    }
    system("cls");
    cout << "List of student in " << cur->courseName << endl;
    i = 1;
    student* temp = cur->liststudent;
    while (temp) {
        cout << i << ".(" << temp->studentID<< ")" << temp->firstName << " " << temp->lastName << endl;
        i++;
        cur = cur->next;
    }
    cout << "Choose student you want to delete (studentID):";
    getline(cin, name);
    temp = cur->liststudent;
    if (cur->liststudent->studentID == name) {
        cur->liststudent = cur->liststudent->next;
        delete temp;
    }
    else {
        student* prev = temp;
        while (temp->studentID != name) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        delete temp;
    }
    cout << "Delete success" << endl;
    cout << "Enter to quit";
    cin.get();
}

void viewscoreboard(Course* course,student*sHead) {
    cin.ignore();
    if (!course) {
        cout << "No course existed";
        cin.get();
        return;
    }
    Course* cur = course;
    cout << "List of course" << endl;
    int i = 1;
    while (cur) {
        cout << i << "." << course->courseName << endl;
        cur = cur->next;
        i++;
    }
    string name;
    cout << "Choose course:";
    getline(cin, name);
    
    cur = course;
    while (cur) {
        if (cur->courseName == name) break;
        cur = cur->next;
    }
    system("cls");
    i = 1;
    cout << "Scoreboard of " << name << endl;
    cout << "No   Student ID  Last Name  First Name   Other Mark    Midterm Mark    Final Mark    Total Mark" << endl;
    student* temp = sHead;
    while (temp) {
        if (temp->listcourse) {
            if (temp->listcourse->courseName == name) {
                cout << i << "  " << temp->studentID << "   " << temp->lastName << "   " << temp->firstName << "    " << temp->listcourse->otherMark << "   " << temp->listcourse->midtermMark << "     " << temp->listcourse->finalMark << "   " << temp->listcourse->totalMark << endl;
                i++;
            }
       }
      temp = temp->next;
    }
    cin.get();
}


void updateresult(Course* course,student*sHead) {
    cin.ignore();
    if (!course) {
        cout << "No course existed";
        cin.get();
        return;
    }
    Course* cur = course;
    cout << "List of course" << endl;
    int i = 1;
    while (cur) {
        cout << i << "." << course->courseName << endl;
        cur = cur->next;
        i++;
    }
    string name;
    cout << "Choose course:";
    getline(cin, name);

    cur = course;
    while (cur) {
        if (cur->courseName == name) break;
        cur = cur->next;
    }
    system("cls");
    i = 1;
    cout << "Scoreboard of " << name << endl;
    cout << "No   Student ID  Last Name  First Name   Other Mark    Midterm Mark    Final Mark    Total Mark" << endl;
    student* temp = sHead;
    while (temp) {
        if (temp->listcourse) {
            if (temp->listcourse->courseName == name) {
                cout << i << "  " << temp->studentID << "   " << temp->lastName << "   " << temp->firstName << "    " << temp->listcourse->otherMark << "   " << temp->listcourse->midtermMark << "     " << temp->listcourse->finalMark << "   " << temp->listcourse->totalMark << endl;
                i++;
            }
        }
        temp = temp->next;
    }
    cin.get();
    cout << "Choose student (student ID):";
    getline(cin, name);
    student* run = sHead;
    while (run) {
        if (run->studentID == name) break;
        run = run->next;
    }
    coursedata*run2 = run->listcourse;
    while (run2) {
        if (run2->courseName == cur->courseName) break;
        run2 = run2->next;
    }
    system("cls");
    int choice;
    cout << "Scoreboard" << endl;
    cout << "1.Midterm mark:" << run2->midtermMark << endl;
    cout << "2.Final mark:" << run2->finalMark << endl;
    cout << "3.Other mark:" << run2->otherMark << endl;
    cout << "4.Total mark:" << run2->totalMark << endl;
    cout << "Your choice(1-4):";
    cin >> choice;
    string mark;
    if (choice == 1) {
        cout << "Input new midterm mark:";
        getline(cin, mark);
        run2->midtermMark = mark;
        cout << "Change success";
        cin.get();
    }
    else if (choice == 2) {
        cout << "Input new final mark:";
        getline(cin, mark);
        run2->finalMark = mark;
        cout << "Change success";
        cin.get();
    }
    else if (choice == 3) {
        cout << "Input new other mark:";
        getline(cin, mark);
        run2->otherMark = mark;
        cin.get();
    }
    else if (choice == 4) {
        cout << "Input new total mark:";
        getline(cin, mark);
        run2->totalMark = mark;
        cin.get();
    }
    else {
        cout << "Invalid choice";
        cin.get();
    }
}

void viewscoreofclass(Course* course, schoolyear sy, Class* c,student*sHead) {
    cin.ignore();
    if (!c) {
        cout << "No class existed";
        cin.get();
        return;
    }
    if (!course) {
        cout << "No course existed";
        cin.get();
        return;
    }
    cout << "LIST OF CLASS" << endl;
    int i = 1;
    Class* cur = c;
    while (cur) {
        cout << i << "." << cur->classname << endl;
        cur = cur->next;
        i++;
    }
    cout << "Choose class you want" << endl;
    string name;
    cout << "Input (name):";
    getline(cin, name);
    cur = c;
    while (cur->classname != name) {
        cur = cur->next;
    }
    system("cls");
    cout << "CLASS " << cur->classname << endl;
    i = 1;
    cout << "No   Student ID  First Name   Last Name    ";
    Course* cur1 = course;
    while (cur1) {
        if (cur1->sc.s1 <= sy.s1 && cur1->sc.s2 <= sy.s2 && cur1->sc.s3 <= sy.s3) {
            cout << cur1->courseName << "   ";
        }
        cur1 = cur1->next;
       
    }
    cout<< "GPA" << endl;
    
    student* run = sHead;
    while (run) {
        if (run->className == name) {
            cout << i << "  " << run->studentID << "    " << run->firstName << "    " << run->lastName << "     ";
            cur1 = course;
            float gpa = 0;
            while (cur1) {
                if (cur1->sc.s1 <= sy.s1 && cur1->sc.s2 <= sy.s2 && cur1->sc.s3 <= sy.s3) {
                    coursedata* check = run->listcourse;
                    while (check) {
                        gpa += stof(check->totalMark);
                        if (check->courseName == cur1->courseName) {
                            cout << check->totalMark << "   ";
                            break;
                        }
                        check = check->next;
                    }
                    if (!check) cout << "x      ";
                }
                cur1 = cur1->next;
            }
            cout << gpa / run->numofcourse;
            i++;
            cout << endl;
        }
        run = run->next;
    }
    cin.get();
}

void exportToCSVFile(Course* course,student*sHead) {
    cin.ignore();
    if (!course) {
        cout << "No course existed";
        cin.get();
        return;
    }
    Course* cur = course;
    int i = 1;
    cout << "List of course" << endl;
    while (cur) {
        cout << i << "." << course->courseName << endl;
        i++;
        cur = cur->next;
    }
    cout << "Input your choice (name):";
    string name;
    getline(cin, name);
    string filename = name + "_Students.csv"; // The filename is the course ID followed by "_Students.csv"
    ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        cout << "Failed to create the file." << endl;
        return;
    }

    // Write the header row
    outputFile << "Student ID,First Name,Last Name,Gender,Class Name,Date of Birth,Social ID,Total Mark,Final Mark,Midterm Mark,Other Mark\n";

    // Iterate over the list of students and write each one to the file
    student* pHead = sHead;
    while (pHead != nullptr) {
        coursedata* temp = pHead->listcourse;
        while (temp) {
            if (temp->courseName == name) {
                outputFile << pHead->studentID << ",";
                outputFile << pHead->firstName << ",";
                outputFile << pHead->lastName << ",";
                outputFile << pHead->gender << ",";
                outputFile << pHead->className << ",";
                outputFile << pHead->dateOfBirth << ",";
                outputFile << pHead->socialID << ",";
                outputFile << pHead->listcourse->totalMark << ",";
                outputFile << pHead->listcourse->finalMark << ",";
                outputFile << pHead->listcourse->midtermMark << ",";
                outputFile << pHead->listcourse->otherMark << "\n";
                break;
            }
            temp = temp->next;
        }
       
        pHead = pHead->next;
    }

    // Close the file
    outputFile.close();
    cout << "Exported the list of students to " << filename << "." << endl;
    cin.get();
}
