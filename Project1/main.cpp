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
    return 0;
}
