#include "Student.h"

// Declare a global pointer to the head of the linked list
Student* head = nullptr;

void Student::login() {
    int id, password;
    cout << "Enter your student ID: ";
    cin >> id;
    cout << "Enter your password: ";
    cin >> password;

    // For simplicity, we'll assume the password is always 1
    if (id == studentID && password == 1) {
        cout << "Login successful!" << endl;
    } else {
        cout << "Invalid student ID or password." << endl;
    }
}


void Student::AddStudentFromKeyBoard() {
    // Input student information from keyboard
    Student* newStudent = new Student;
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
    cout << "Enter social ID: ";
    cin >> newStudent->socialID;
    cin.ignore();

     // Check if the student ID is unique
    Student* current = head;
    while (current != nullptr) {
        if (current->studentID == newStudent->studentID) {
            cout << "Error: student ID already exists" << endl;
            return;
        }
        current = current->next;
    }
    newStudent->next = head;
    head = newStudent;
}

void Student::AddStudentsFromCSVFile(string filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error: could not open file " << filename << endl;
        return;
    }
    
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string field;
        vector<string> fields;
        while (getline(ss, field, ',')) {
            fields.push_back(field);
        }
        if (fields.size() != 6) {
            cerr << "Error: invalid format in file " << filename << endl;
            continue;
        }
        Student* newStudent = new Student;
        newStudent->studentID = stoi(fields[0]);
        newStudent->firstName = fields[1];
        newStudent->lastName = fields[2];
        newStudent->gender = fields[3];
        newStudent->dateOfBirth = fields[4];
        newStudent->socialID = fields[5];
        newStudent->next = head;
        head = newStudent;
    }
    file.close();
}

void Student::display() {
    if (!head) {
        cout << "The list is empty";
        return;
    }
    Student* current = head;
    while (current != nullptr) {
        cout << "Student ID: " << current->studentID << endl;
        cout << "First Name: " << current->firstName << endl;
        cout << "Last Name: " << current->lastName << endl;
        cout << "Gender: " << current->gender << endl;
        cout << "Date of Birth: " << current->dateOfBirth << endl;
        cout << "Social ID: " << current->socialID << endl << endl;
        current = current->next;
    }
}

void Student::viewCourses() {
    // View student's courses
    // ...
}

void Student::viewScoreBoard() {
    // View student's score board
    // ...
}
