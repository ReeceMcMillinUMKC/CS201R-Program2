#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <exception>
#include <unordered_map>
#include <unordered_set>
#include "Student.cpp"

using namespace std;

int MainMenu();
void PrintClassRoster(vector<Student> vec);
void PrintClassRosterWithGrades(vector<Student> vec);
void PrintClassRosterWithWeightedGrades(vector<Student> vec);
void printVector(vector<int> vec);
vector<int> splitString(string s);
unordered_map<int, vector<int>> ReadGrades(string filename);
vector<Student> ReadStudents(string filename);

int MainMenu() {
    int selection;
    unordered_set<int> options{1, 2, 3, 4};

    cout << "Please make a selection:" << endl;
    cout << "\t(1) Print class roster" << endl;
    cout << "\t(2) Print class roster with their grades" << endl;
    cout << "\t(3) Print class roster with students' weighted total" << endl;
    cout << "\t(4) Exit" << endl;
    cout << "Enter your choice: ";
    cin >> selection;

    //!cin checks whether the input has been deposited into selection.
    //!options.count(selection) checks that selection is NOT in {1, 2, 3, 4}.
    while (!cin || !options.count(selection)) {
        cout << "\nError: Please enter a choice from [1, 2, 3, 4]\n" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter your choice: ";
        cin >> selection;
    }
    return selection;
}

void PrintClassRoster(vector<Student> vec) {
    cout << "The class has " << vec.size() << " students." << endl;
    for (Student &x : vec) {
        cout << x.GetStudentID() << " " << x.GetFullName() << endl;
    }
    cout << endl;
}

void PrintClassRosterWithGrades(vector<Student> vec) {
    for (Student &x : vec) {
        cout << left << setw(18) << (x.GetFullName().append(": "));
        printVector(x.GetGrades());
    }
    cout << endl;
}

void PrintClassRosterWithWeightedGrades(vector<Student> vec) {
    cout << setprecision(4);
    for (auto student : vec) {
        cout << "Weighted average score of " << student.GetFullName() << " is " << student.FindAverage() << "\% out of 100%" << endl;
    }
    cout << endl;
}

void printVector(vector<int> vec) {
    for (const int &x : vec) {
        cout << x << " ";
    }
    cout << endl;
}

vector<int> splitString(string s) {
    //Utility - Splits a string of whitespace-delimited digits into a vector<int>.
    stringstream sstream(s);
    string numString;
    vector<int> intVec;
    while (sstream >> numString) {
        intVec.push_back(stoi(numString));
    }
    return intVec;
}

unordered_map<int, vector<int>> ReadGrades(string filename) {
    //Reads ID & Grade data from file, ensures file exists, and returns hash map.
    //Map allows for constant-time association for Student objects read in ReadStudents().
    fstream fin(filename);
    if (!fin.good()) {
        throw (runtime_error("Error reading file - please ensure \"" + filename + "\" exists"));
    }
    int id;
    string grades;
    unordered_map<int, vector<int>> idGradeMap;
    while (fin.good()) {
        fin >> id;
        getline(fin, grades);
        idGradeMap[id] = splitString(grades);
    }
    fin.close();
    return idGradeMap;
}

vector<Student> ReadStudents(string filename, unordered_map<int, vector<int>> idGradeMap) {
    fstream fin(filename);
    if (!fin.good()) {
        throw (runtime_error("Error reading file - please ensure \"" + filename + "\" exists"));
    }
    int id;
    string studentName;
    vector<Student> studentRoster;

    while (fin.good()) {
        //Read ID, ignore the following whitespace
        fin >> id;
        fin.ignore();
        getline(fin, studentName);
        //Pop a Student onto the stack
        Student newStudent = Student(id, studentName);
        //Use the hash map idGradeMap to assign the appropriate grades from Grades.txt to each student
        newStudent.SetStudentGrades(idGradeMap[newStudent.GetStudentID()]);
        //Finally, include the new Student in the roster we'll be returning to main().
        studentRoster.push_back(newStudent);
    }
    fin.close();
    return studentRoster;
}