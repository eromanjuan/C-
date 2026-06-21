#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent a student
struct Student {
    string name;
    int rollNumber;
    string course;
    double gpa;
};

// Function prototypes
void mainMenu();
void addStudent(vector<Student>& students);
void viewStudents(const vector<Student>& students);
void searchStudent(const vector<Student>& students);
void updateStudent(vector<Student>& students);
void deleteStudent(vector<Student>& students);

int main() {
    vector<Student> students;

    while (true) {
        mainMenu();
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                viewStudents(students);
                break;
            case 3:
                searchStudent(students);
                break;
            case 4:
                updateStudent(students);
                break;
            case 5:
                deleteStudent(students);
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

// Main menu function
void mainMenu() {
    cout << "Student Information System" << endl;
    cout << "1. Add Student" << endl;
    cout << "2. View Students" << endl;
    cout << "3. Search Student" << endl;
    cout << "4. Update Student" << endl;
    cout << "5. Delete Student" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
}

// Add student function
void addStudent(vector<Student>& students) {
    Student student;
    cout << "Enter name: ";
    cin >> student.name;
    cout << "Enter roll number: ";
    cin >> student.rollNumber;
    cout << "Enter course: ";
    cin >> student.course;
    cout << "Enter GPA: ";
    cin >> student.gpa;
    students.push_back(student);
    cout << "Student added successfully." << endl;
}

// View students function
void viewStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students available." << endl;
    } else {
        cout << "Students:" << endl;
        for (const auto& student : students) {
            cout << "Name: " << student.name << endl;
            cout << "Roll Number: " << student.rollNumber << endl;
            cout << "Course: " << student.course << endl;
            cout << "GPA: " << student.gpa << endl;
            cout << endl;
        }
    }
}

// Search student function
void searchStudent(const vector<Student>& students) {
    int rollNumber;
    cout << "Enter roll number to search: ";
    cin >> rollNumber;

    for (const auto& student : students) {
        if (student.rollNumber == rollNumber) {
            cout << "Student found:" << endl;
            cout << "Name: " << student.name << endl;
            cout << "Course: " << student.course << endl;
            cout << "GPA: " << student.gpa << endl;
            return;
        }
    }

    cout << "Student not found." << endl;
}

// Update student function
void updateStudent(vector<Student>& students) {
    int rollNumber;
    cout << "Enter roll number to update: ";
    cin >> rollNumber;

    for (auto& student : students) {
        if (student.rollNumber == rollNumber) {
            cout << "Enter new name: ";
            cin >> student.name;
            cout << "Enter new course: ";
            cin >> student.course;
            cout << "Enter new GPA: ";
            cin >> student.gpa;
            cout << "Student updated successfully." << endl;
            return;
        }
    }

    cout << "Student not found." << endl;
}

// Delete student function
void deleteStudent(vector<Student>& students) {
    int rollNumber;
    cout << "Enter roll number to delete: ";
    cin >> rollNumber;

    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->rollNumber == rollNumber) {
            students.erase(it);
            cout << "Student deleted successfully." << endl;
            return;
        }
    }

    cout << "Student not found." << endl;
}
