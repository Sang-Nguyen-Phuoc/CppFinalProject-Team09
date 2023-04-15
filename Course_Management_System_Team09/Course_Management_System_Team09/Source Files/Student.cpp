#include "Student.h"
// Declare a global pointer to the head of the linked list
Student* head = nullptr;

student* login2(student* sStart) {
	string id;
	string password;
	cout << "Input id: ";
	cin.ignore();
	getline(cin, id);
	cout << "Input password: ";
	getline(cin, password);

	while (sStart) {
		if (sStart->studentID == id && sStart->password == password) {
			cout << "Login success" << endl;
			return sStart;
		}
		sStart = sStart->next;
	}
	if (!sStart) cout << "ID doesn't exist" << endl;
	cout << "Press enter to continue";
	return nullptr;
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



void Student::viewCourses() {

}

void Student::viewScoreBoard() {


}



