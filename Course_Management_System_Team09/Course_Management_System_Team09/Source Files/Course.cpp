#include "Course.h"
#include<string>
#include"class.h"
using namespace std;

void addCourse(Course*& course) {
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
    cout << setw(30) << setfill('') << "" << endl;
    cout << setfill(' ');
    cout << setw(30) << "Add New Course" << endl;
    cout << setw(30) << setfill('') << "" << endl << endl;
    cout << "New course name: ";
    cin.ignore();
    getline(cin, temp->courseName);
    system("cls");
    cout << "Course ID: ";
    getline(cin, temp->courseID);
    system("cls");
    cout << "Day of week of the course " << endl;
    cout << setw(2) << "1." << setw(10) << left << "Monday" << endl;
    cout << setw(2) << "2." << setw(10) << left << "Tuesday" << endl;
    cout << setw(2) << "3." << setw(10) << left << "Wednesday" << endl;
    cout << setw(2) << "4." << setw(10) << left << "Thursday" << endl;
    cout << setw(2) << "5." << setw(10) << left << "Friday" << endl;
    cout << setw(2) << "6." << setw(10) << left << "Saturday" << endl;
    cout << setw(2) << "7." << setw(10) << left << "Sunday" << endl;
    cout << "Your choice:";
    getline(cin, temp->dayofWeek);
    system("cls");
    cout << "Session time of the course: " << endl;
    cout << setw(2) << "1." << setw(10) << left << "S1(7:30)" << endl;
    cout << setw(2) << "2." << setw(10) << left << "S2(9:30)" << endl;
    cout << setw(2) << "3." << setw(10) << left << "S3(13:30)" << endl;
    cout << setw(2) << "4." << setw(10) << left << "S4(15:30)" << endl;
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
    cout << setw(30) << setfill('') << "" << endl;
    cout << setfill(' ');
    cout << setw(30) << "Add course success" << endl;
    cout << setw(30) << setfill('') << "" << endl;
    cin.get();
    }

void deleteCourse(Course*& course,student*sHead) {
    cin.ignore();
    if (!course) {
    cout << setw(30) << setfill('') << "" << endl;
    cout << setfill(' ');
    cout << setw(30) << "Delete Course" << endl;
    cout << setw(30) << setfill('') << "" << endl << endl;
    cout << "No course existed" << endl;
    cin.get();
    return;
    }
    string name;
    cout << setw(30) << setfill('') << "" << endl;
    cout << setfill(' ');
    cout << setw(30) << "Delete Course" << endl;
    cout << setw(30) << setfill('') << "" << endl << endl;
    Course* cur = course;
    int i = 1;
    while (cur) {
        cout << i << "." << cur->courseName << endl;
        i++;
        cur = cur->next;
    }
    cout << "Course you want to delete:";
    getline(cin, name);
    
    student* run = sHead;
    while (run) {
        if (run->listcourse) {
            coursedata* run2 = run->listcourse;
            if (run2->courseName == name) {
                coursedata* temp = run2;
                run2 = run2->next;
                delete temp;
            }
            else {
                coursedata* prev = run2;
                run2 = run2->next;
                while (run2) {
                    if (run2->courseName == name) {
                        prev->next = run2->next;
                        delete run2;
                        break;
                    }
                    run2 = run2->next;
                }
            }
        }
        run = run->next;
    }
    
    cur = course;
    if (cur->courseName == name) {
    course = course->next;
    delete cur;
    cout << "Delete success" << endl;
    cin.get();
    return;
    }
    Course* prev = cur;
    cur = cur->next;
    while (cur) {   
    if (cur->courseName == name) {
    prev->next = cur->next;
    delete cur;
    cout << "Delete success" << endl;
    cin.get();
    return;
    }
    prev = cur;
    cur = cur->next;
    }
    cout << "Course not found" << endl;
    cin.get();
}

void viewliststudentincourse(Course* course) {
    cin.ignore();
    if (!course) {
        cout << "No course exists" << endl;
        cin.get();
        return;
    }
        int choice = 0;
    cout << setw(40) << "LIST OF COURSES" << endl;
    cout << setfill('-') << setw(80) << "" << endl;
    cout << setfill(' ');
    cout << setw(5) << "No." << setw(30) << "Course Name" << endl;
    cout << setfill('-') << setw(80) << "" << endl;
    cout << setfill(' ');
    int i = 1;
    Course* cur = course;
    while (cur) {
        cout << setw(5) << i << ". " << setw(30) << cur->courseName << endl;
        i++;
        cur = cur->next;
    }
        cout << "Enter the course number you want to view: ";
    cin >> choice;
        cur = course;
    i = 1;
    while (i != choice && cur) {
        cur = cur->next;
        i++;
    }
    
    if (!cur) {
        cout << "Invalid choice" << endl;
        cin.get();
        return;
    }
    system("cls");
    cout << setw(50) << "LIST OF STUDENTS IN " << cur->courseName << endl;
    cout << setfill('-') << setw(100) << "" << endl;
    cout << setfill(' ');
    cout << setw(5) << "No." << setw(20) << "Student ID" << setw(20) << "Last Name" << setw(20) << "First Name" << endl;
    cout << setfill('-') << setw(100) << "" << endl;
    cout << setfill(' ');
    
    i = 1;
    student* temp = cur->liststudent;
    while (temp) {
        cout << setw(5) << i << setw(20) << temp->studentID << setw(20) << temp->lastName << setw(20) << temp->firstName << endl;
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
    cout << setw(30) << "Choose course to add student into" << endl;
    cout << "-----------------------------------------------" << endl;
    while (course) {
        cout << setw(3) << i << ". " << course->courseName << endl;
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
    cout << setw(20) << left << "List of course" << endl;
    int i = 1;
    while (cur) {
        cout << setw(5) << left << i << setw(20) << left << cur->courseName << endl;
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
        cout << setw(20) << left << "Change properties" << endl;
        cout << setw(5) << left << "1." << setw(20) << left << "Course Name" << endl;
        cout << setw(5) << left << "2." << setw(20) << left << "Course ID" << endl;
        cout << setw(5) << left << "3." << setw(20) << left << "Day of week" << endl;
        cout << setw(5) << left << "4." << setw(20) << left << "Session time" << endl;
        cout << setw(5) << left << "5." << setw(20) << left << "Teacher" << endl;
        cout << setw(5) << left << "6." << setw(20) << left << "Back" << endl;
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
    cout << setw(30) << left << "Current course name:" << course->courseName << endl;
    cout << setw(30) << left << "Input new course name (quit to quit):";
    getline(cin, name);
    if (name == "quit") return;
    course->courseName = name;
    cout << setw(30) << left << "Change course name success" << endl;
    cout << setw(30) << left << "Enter to quit";
    cin.get();
}

void changecourseID(Course* course) {
    cin.ignore();
    string name;
    cout << setw(30) << left << "Current course ID:" << course->courseID << endl;
    cout << setw(30) << left << "Input new course ID (quit to quit):";
    getline(cin, name);
    if (name == "quit") return;
    course->courseID = name;
    cout << setw(30) << left << "Change course ID success" << endl;
    cout << setw(30) << left << "Enter to quit";
    cin.get();
}
void changedayofweek(Course* course) {
    cin.ignore();
    string name;
    cout << setw(30) << left << "Current day of week:" << course->dayofWeek << endl;
    cout << setw(30) << left << "Input new day of week (quit to quit):";
    getline(cin, name);
    if (name == "quit") return;
    course->dayofWeek = name;
    cout << setw(30) << left << "Change day of week success" << endl;
    cout << setw(30) << left << "Enter to quit";
    cin.get();
}

void changesession(Course* course) {
    cin.ignore();
    string name;
    cout << setw(30) << left << "Current session time:" << course->sessionTime << endl;
    cout << setw(30) << left << "Input new session time (quit to quit):";
    getline(cin, name);
    if (name == "quit") return;
    course->sessionTime = name;
    cout << setw(30) << left << "Change session time success" << endl;
    cout << setw(30) << left << "Enter to quit";
    cin.get();
}

void changecourseID(Course* course) {
    cin.ignore();
    string name;
    cout << "Current course ID: " << setw(10) << course->courseID << endl;
    cout << "Input new course ID (quit to quit): ";
    getline(cin, name);
    if (name == "quit") return;
    course->courseID = name;
    cout << "Change course ID success" << endl;
    cout << "Enter to quit ";
    cin.get();


void addonestudent(Course* course) {
    cin.ignore();
    if (!course) {
        cout << "No course existed";
        cin.get();
        return;
    }
    Course* cur = course;
    cout << setw(20) << left << "List of course" << endl;
    int i = 1;
    while (cur) {
        cout << setw(5) << right << i << "." << setw(20) << left << course->courseName << endl;
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
    cout << setw(20) << left << "Input student ID:";
    getline(cin, temp->studentID);
    cin.ignore();
    cout << setw(20) << left << "Input first name:";
    getline(cin, temp->firstName);
    cin.ignore();
    cout << setw(20) << left << "Input last name:";
    getline(cin, temp->lastName);
    cin.ignore();
    cout << setw(20) << left << "Input class name:";
    getline(cin, temp->className);
    cin.ignore();
   if (!cur->liststudent) {
        cur->liststudent = temp;
    }
    else {
        student* current = cur->liststudent;
        while (current->next) {
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
    cout << "List of courses" << endl;
    int i = 1;
    while (cur) {
        cout << setw(2) << i << ". " << cur->courseName << endl;
        cur = cur->next;
        i++;
    }
    string name;
    cout << "Choose course: ";
    getline(cin, name);
    cur = course;
    while (cur) {
        if (cur->courseName == name) break;
        cur = cur->next;
    }
    system("cls");
    cout << "List of students in " << cur->courseName << endl;
    i = 1;
    student* temp = cur->liststudent;
    cout << left << setw(4) << "No" << setw(15) << "Student ID" << setw(20) << "First Name" << "Last Name" << endl;
    while (temp) {
        cout << setw(4) << i << ". " << setw(15) << temp->studentID << setw(20) << temp->firstName << temp->lastName << endl;
        i++;
        temp = temp->next;
    }
    cout << "Choose student you want to delete (student ID): ";
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
    cout << "Press enter to quit...";
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


void updateresult(Course* course, student* sHead) {
    cin.ignore();
    if (!course) {
        cout << "No course existed";
        cin.get();
        return;
    }

    Course* cur = course;
    cout << "List of courses" << endl;
    int i = 1;
    cout << left << setw(5) << "No" << setw(25) << "Course Name" << endl;
    while (cur) {
        cout << left << setw(5) << i << setw(25) << cur->courseName << endl;
        cur = cur->next;
        i++;
    }
    string name;
    cout << "Choose course: ";
    getline(cin, name);

    cur = course;
    while (cur) {
        if (cur->courseName == name) break;
        cur = cur->next;
    }

    system("cls");
    i = 1;
    cout << "Scoreboard of " << name << endl;
    cout << left << setw(5) << "No" << setw(12) << "Student ID" << setw(12) << "Last Name" << setw(12) << "First Name" << setw(15) << "Other Mark" << setw(15) << "Midterm Mark" << setw(15) << "Final Mark" << setw(15) << "Total Mark" << endl;
    student* temp = sHead;
    while (temp) {
        if (temp->listcourse) {
            if (temp->listcourse->courseName == name) {
                cout << left << setw(5) << i << setw(12) << temp->studentID << setw(12) << temp->lastName << setw(12) << temp->firstName << setw(15) << temp->listcourse->otherMark << setw(15) << temp->listcourse->midtermMark << setw(15) << temp->listcourse->finalMark << setw(15) << temp->listcourse->totalMark << endl;
                i++;
            }
        }
        temp = temp->next;
    }

    cin.get();
    cout << "Choose student (student ID): ";
    getline(cin, name);
    student* run = sHead;
    while (run) {
        if (run->studentID == name) break;
        run = run->next;
    }

    coursedata* run2 = run->listcourse;
    while (run2) {
        if (run2->courseName == cur->courseName) break;
        run2 = run2->next;
    }

    system("cls");
    int choice;
    cout << "Scoreboard" << endl;
    cout << "1. Midterm mark: " << run2->midtermMark << endl;
    cout << "2. Final mark: " << run2->finalMark << endl;
    cout << "3. Other mark: " << run2->otherMark << endl;
    cout << "4. Total mark: " << run2->totalMark << endl;
    cout << "Your choice (1-4): ";
    cin >> choice;
    string mark;
    if (choice == 1) {
        cout << "Input new midterm mark: ";
        getline(cin, mark);
        run2->midtermMark = mark;
        cout << "Change success";
        cin.get();
    }
    else if (choice == 2) {
        cout << "Input new final mark: ";
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

void viewscoreofclass(Course* course, schoolyear sy, Class* c, student* sHead) {
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
cout << setw(5) << "No" << setw(15) << "Student ID" << setw(15) << "First Name" << setw(15) << "Last Name";
Course* cur1 = course;
while (cur1) {
if (cur1->sc.s1 <= sy.s1 && cur1->sc.s2 <= sy.s2 && cur1->sc.s3 <= sy.s3) {
cout << setw(10) << cur1->courseName;
}
cur1 = cur1->next;
}
cout << setw(10) << "GPA" << endl;

student* run = sHead;
while (run) {
    if (run->className == name) {
        cout << setw(5) << i << setw(15) << run->studentID << setw(15) << run->firstName << setw(15) << run->lastName;
        cur1 = course;
        float gpa = 0;
        while (cur1) {
            if (cur1->sc.s1 == sy.s1 && cur1->sc.s2 == sy.s2 && cur1->sc.s3 == sy.s3) {
                coursedata* check = run->listcourse;
                while (check) {
                    gpa += stof(check->totalMark);
                    if (check->courseName == cur1->courseName) {
                        cout << setw(10) << check->totalMark;
                        break;
                    }
                    check = check->next;
                }
                if (!check) cout << setw(10) << "x";
            }
            cur1 = cur1->next;
        }
        cout << setw(10) << fixed << setprecision(2) << gpa / run->numofcourse;
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
