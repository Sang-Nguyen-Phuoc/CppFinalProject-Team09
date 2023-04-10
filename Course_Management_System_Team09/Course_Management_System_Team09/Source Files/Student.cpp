#include "Student.h"
// Declare a global pointer to the head of the linked list
Student* head = nullptr;

void Student::login() {
    int id, password;
    
    do {
        cout << "Enter your ID: ";
        cin >> id;
        cout << "Enter your password: ";
        cin >> password;

        Student *cur = head; // Create a pointer to traverse the linked list
        while (cur != nullptr) {
            if (cur->studentID == id && password == 1) {
                cout << "Login successfully" << endl;
                cout << "Press enter to continue" << endl;
                system("cls");
                return;
            }
            cur = cur->next;
            if (cur == nullptr) {
                cout << "Login failed" << endl;
                cout << "Press enter to continue" << endl;
                system("cls");
            }
        }
    } while (true);

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
    cout << "Enter class name: ";
    cin >> newStudent->className; 
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

void Student::displayOnScreen() {
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

void Student::displayOnFile() {
    if (!head) {
        cout << "The list is empty";
        return;
    }

    // Open the output file for writing
    ofstream output_file("output.csv");

    // Write the header row to the CSV file
    output_file << "Student ID,First Name,Last Name,Gender,Date of Birth,Social ID\n";

    Student* current = head;
    while (current != nullptr) {
        // Write each student's data to a row in the CSV file
        output_file << current->studentID << ","
                    << current->firstName << ","
                    << current->lastName << ","
                    << current->gender << ","
                    << current->dateOfBirth << ","
                    << current->socialID << "\n";
        current = current->next;
    }

    // Close the output file
    output_file.close();

    cout << "Data has been output to output.csv\n";
}

void Student::menu() {
    int choice;
    do {
        cout << "1. View courses" << endl;
        cout << "2. View score board" << endl;
        cout << "3. Logout" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            viewCourses();
            break;
        case 2:
            viewScoreBoard();
            break;
        case 3:
            logout();
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (choice != 3);
}

void Student::viewCourses() {

}

void Student::viewScoreBoard() {


}


void Student::logout() {
    cout << "Logout successfully" << endl;
    cout << "Press enter to continue" << endl;
    system("cls");

}
