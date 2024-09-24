#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// Structure to store student data (first and last name)
struct STUDENT_DATA {
    string firstName;
    string lastName;
};

int main() {
    // This Opens StudentData.txt
    ifstream file("StudentData.txt");

    // to check if file opened successfully
    if (!file.is_open()) {
        cerr << "Error: Could not open StudentData.txt" << endl;
        return 1;
    }

    vector<STUDENT_DATA> students;  // using a Vector to store student data
    string line;

    // Reading each line from the file and storing the student info
    while (getline(file, line)) {
        stringstream ss(line);
        string lastName, firstName;

        // Getting the last and first name
        getline(ss, lastName, ',');
        getline(ss, firstName);

        // Store the student data in the vector
        STUDENT_DATA student = { firstName, lastName };

        // Adding to the list
        students.push_back(student);
    }

    file.close();

    // Only prints if compiled in Debug mode
#ifdef _DEBUG
    cout << "Student List (Debug Mode):" << endl;
    for (const auto& student : students) {
        cout << student.firstName << " " << student.lastName << endl;
    }
#endif

    // Pre-release mode to include emails
#ifdef PRE_RELEASE
    ifstream emailFile("StudentData_Emails.txt");

    // Check if the email file opened successfully
    if (!emailFile.is_open()) {
        cerr << "Error: Could not open StudentData_Emails.txt" << endl;
        return 1;
    }

    map<string, string> studentEmails;  // Map to store emails associated with full names

    // Read email file and map emails to full names
    while (getline(emailFile, line)) {
        stringstream ss(line);
        string lastName, firstName, email;

        // Extract last name, first name, and email
        getline(ss, lastName, ',');
        getline(ss, firstName, ',');
        getline(ss, email);

        string fullName = firstName + " " + lastName;
        studentEmails[fullName] = email;  // Map the full name to the email
    }

    emailFile.close();  // Close StudentData_Emails.txt file

    // Output student names and their associated emails
    cout << "Pre-release Mode: Student Data with Emails" << endl;
    for (const auto& student : students) {
        string fullName = student.firstName + " " + student.lastName;
        cout << fullName;
        if (studentEmails.find(fullName) != studentEmails.end()) {
            cout << " - " << studentEmails[fullName];
        }
        cout << endl;
    }
#endif

    return 0;
}
