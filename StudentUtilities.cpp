#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include "Student.cpp"

using namespace std;

void printVector(vector<int> vec) {
    for (const int &x : vec) {
        cout << x << " ";
    }
    cout << endl;
}

void printVector(vector<Student> vec) {
    for (Student &x : vec) {
        cout << "ID #" << x.GetStudentID() << ": " << x.FullName() << " " << endl;
    }
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

vector<Student> ReadStudents(string filename) {
    fstream fin(filename);
    int id;
    string studentName;
    vector<Student> studentRoster;

    while (fin.good()) {
        fin >> id;
        fin.ignore();
        getline(fin, studentName);
        Student newStudent = Student(id, studentName);
        studentRoster.push_back(newStudent);
    }
    return studentRoster;
}