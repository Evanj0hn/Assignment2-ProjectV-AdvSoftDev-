#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

struct STUDENT_DATA {
    string firstName;
    string lastName;
};

int main() {
    ifstream file("StudentData.txt");  // This Open StudentData.txt

    // to check if file opened successfully
    if (!file.is_open()) {  
        cerr << "Error: Could not open StudentData.txt" << endl;
        return 1;  
    }

    vector<STUDENT_DATA> students;     // using a Vector to store student data
    string line;

    // Reading each line from the file and storing the student info
    while (getline(file, line)) {
        stringstream ss(line);
        string lastName, firstName;

        // Getting the last and first name
        getline(ss, lastName, ',');  
        getline(ss, firstName);      

        STUDENT_DATA student = { firstName, lastName };  

        // Adding to the list
        students.push_back(student);                   
    }

    file.close();

    // Only prints if compiled in debug mode
    #ifdef _DEBUG
        cout << "Student List (Debug Mode):" << endl;
        for (const auto& student : students) {
            cout << student.firstName << " " << student.lastName << endl;
        }
    #endif

    return 0;
}
