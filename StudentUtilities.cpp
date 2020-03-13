#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
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
        cout << x.GetStudentID() << " " << x.FullName() << endl;
    }
    cout << endl;
}

void PrintClassRosterWithGrades(vector<Student> vec) {
    for (Student &x : vec) {
        cout << left << setw(18) << (x.FullName().append(": "));
        printVector(x.GetGrades());
    }
    cout << endl;
}

void PrintClassRosterWithWeightedGrades(vector<Student> vec) {
    cout << setprecision(4);
    const double QUIZWEIGHT = 10.0/220.0;
    const double EXAMWEIGHT = 100.0/220.0;
    for (auto student : vec) {
        cout << "Weighted average score of " << student.FullName() << " is ";
        cout << student.FindAverage() << "\% out of 100%" << endl;
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
    stringstream sstream(s);
    string numString;
    vector<int> intVec;
    while (sstream >> numString) {
        intVec.push_back(stoi(numString));
    }
    return intVec;
}

unordered_map<int, vector<int>> ReadGrades(string filename) {
    fstream fin(filename);
    int id;
    string grades;
    unordered_map<int, vector<int>> idGradeMap;
    while (fin.good()) {
        fin >> id;
        getline(fin, grades);
        idGradeMap[id] = splitString(grades);
    }
    return idGradeMap;
}

vector<Student> ReadStudents(string filename, unordered_map<int, vector<int>> idGradeMap) {
    fstream fin(filename);
    int id;
    string studentName;
    vector<Student> studentRoster;

    while (fin.good()) {
        fin >> id;
        fin.ignore();
        getline(fin, studentName);
        Student newStudent = Student(id, studentName);
        newStudent.SetStudentGrades(idGradeMap[newStudent.GetStudentID()]);
        studentRoster.push_back(newStudent);
    }
    return studentRoster;
}