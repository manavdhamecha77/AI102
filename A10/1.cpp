<<<<<<< HEAD
/*
1. You are given a text file, named “students.txt” that contains students’ records. Each 
Line contains information of a single student in the form of <Student Name, Roll No,
Department>.
A. Read the records from the file into an array of structures.
B. Three Options will turn up: (1) Bubble Sort, (2) Binary Search, and (3) Quit. In the
following we describe what your C/C++ program will do on Selecting the options.
(1) Bubble Sort: Sorts the records based on Student Name. If more than One students has
the same name, then sort them on their roll no.
(2) Binary Search: Given a student name, the function will return all the Student records
<Student Name, Roll No, Department> having the Student name.
(3) Quit: Exit the program.
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

// Structure to store student details
struct Student {
    string name;
    string rollNo;
    string department;
};

// Function to trim spaces from both ends of a string
string trim(const string& str) {
    size_t first = str.find_first_not_of(" \t");
    if (first == string::npos) return "";
    size_t last = str.find_last_not_of(" \t");
    return str.substr(first, last - first + 1);
}

// Function to read student records from file
void readStudentsFromFile(vector<Student>& students, const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Unable to open file!" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Student student;
        
        getline(ss, student.name, ',');
        getline(ss, student.rollNo, ',');
        getline(ss, student.department, ',');
        
        // Trim spaces
        student.name = trim(student.name);
        student.rollNo = trim(student.rollNo);
        student.department = trim(student.department);
        
        if (!student.name.empty()) {
            students.push_back(student);
        }
    }
    file.close();
}

// Function to display student records
void displayStudents(const vector<Student>& students) {
    cout << "\nStudent Records:\n";
    for (const auto& student : students) {
        cout << "Name: " << student.name << ", Roll No: " << student.rollNo 
             << ", Department: " << student.department << endl;
    }
}

// Function to perform Bubble Sort on student records
void bubbleSort(vector<Student>& students) {
    int n = students.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].name > students[j + 1].name) {
                swap(students[j], students[j + 1]);
            }
        }
    }
}

// Function to perform Binary Search for a student's name
void binarySearch(const vector<Student>& students, const string& target) {
    int left = 0, right = students.size() - 1;
    bool found = false;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (students[mid].name == target) {
            found = true;
            int start = mid, end = mid;

            while (start > 0 && students[start - 1].name == target) start--;
            while (end < students.size() - 1 && students[end + 1].name == target) end++;

            cout << "\nStudent(s) Found:\n";
            for (int i = start; i <= end; i++) {
                cout << "Name: " << students[i].name 
                     << ", Roll No: " << students[i].rollNo 
                     << ", Department: " << students[i].department << endl;
            }
            return;
        } 
        else if (students[mid].name < target) {
            left = mid + 1;
        } 
        else {
            right = mid - 1;
        }
    }

    if (!found) {
        cout << "Student with name '" << target << "' not found.\n";
    }
}

int main() {
    vector<Student> students;
    string filename = "students.csv";

    readStudentsFromFile(students, filename);
    if (students.empty()) {
        cerr << "No student records found in file.\n";
        return 1;
    }

    bubbleSort(students); // Sort before binary search

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Display Sorted Students\n";
        cout << "2. Binary Search\n";
        cout << "3. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore newline

        switch (choice) {
            case 1:
                displayStudents(students);
                break;

            case 2: {
                string target;
                cout << "Enter student name to search: ";
                getline(cin, target);
                target = trim(target); // Trim input
                binarySearch(students, target);
                break;
            }

            case 3:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
=======
/*
1. You are given a text file, named “students.txt” that contains students’ records. Each 
Line contains information of a single student in the form of <Student Name, Roll No,
Department>.
A. Read the records from the file into an array of structures.
B. Three Options will turn up: (1) Bubble Sort, (2) Binary Search, and (3) Quit. In the
following we describe what your C/C++ program will do on Selecting the options.
(1) Bubble Sort: Sorts the records based on Student Name. If more than One students has
the same name, then sort them on their roll no.
(2) Binary Search: Given a student name, the function will return all the Student records
<Student Name, Roll No, Department> having the Student name.
(3) Quit: Exit the program.
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

// Structure to store student details
struct Student {
    string name;
    string rollNo;
    string department;
};

// Function to read student records from file
void readStudentsFromFile(vector<Student>& students, const string& filename) {
    ifstream file("students.csv");
    if (!file) {
        cerr << "Error: Unable to open file!" << endl;
        return;
    }
    
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Student student;
        getline(ss, student.name, ',');
        getline(ss, student.rollNo, ',');
        getline(ss, student.department, ',');
        
        students.push_back(student);
    }
    file.close();
}

// Function to display student records
void displayStudents(const vector<Student>& students) {
    cout << "\nStudent Records:\n";
    for (const auto& student : students) {
        cout << "Name: " << student.name << ", Roll No: " << student.rollNo << ", Department: " << student.department << endl;
    }
}

// Function to perform Bubble Sort on student records
void bubbleSort(vector<Student>& students) {
    int n = students.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].name > students[j + 1].name || 
                (students[j].name == students[j + 1].name && students[j].rollNo > students[j + 1].rollNo)) {
                swap(students[j], students[j + 1]);
            }
        }
    }
}

void binarySearch(vector<Students>& students,string target)
{
    int left = 0, right = students.size() - 1;
    bool found = false;
    
    while (left <= right) 
    {
        int mid = left + (right - left) / 2;
        if (students[mid].name == targetName)
        {
            found = true;
            int start = mid, end = mid;

            while(start > 0 && students[start-1].name == target) start--;
            while(end < students.size()-1 && students[end+1].name == target) end++;

            for(int i = start; i <= end; i++)
            {
                cout << "Name : " << students[i].name << "Roll no : " << students[i].rollNo << "Department : " << students[i].department << endl; 
            }
            return;

        }

        else if (students[mid].name < targetName) 
        {
            left = mid + 1;
        }
        
        else 
        {
            right = mid - 1;
        } 
    }
}

int main() 
{
    vector<Student> students;
    string filename = "students.txt";
    string target = "Vedant Iyer";
    
    readStudentsFromFile(students, filename);
    //displayStudents(students);
    bubbleSort(students);
    //displayStudents(students);
    binarySearch(students,target);




    
    return 0;
}
>>>>>>> ae489f3517636dca531ec86bd26d2f25b6163b49
