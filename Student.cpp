#include "Student.h"

//Class Logistics
Student::Student(int __studentID, string __studentName) {
    SetStudentID(__studentID);
    SetFirstName(__studentName);
    SetLastName(__studentName);
}

//Get Private Variables
int Student::GetStudentID() {
    return studentID;
}

string Student::GetFirstName() {
    return studentFirstName;
}

string Student::GetLastName() {
    return studentLastName;
}

string Student::GetFullName() {
    return studentLastName.append(", ").append(studentFirstName);
}

vector<int> Student::GetGrades() {
    return studentGrades;
}
        
//Set Private Variables
void Student::SetStudentID(int __studentID) {
    studentID = __studentID <= 0 ? -1 : __studentID;
}

void Student::SetFirstName(string __studentName) {
    stringstream sstream(__studentName);
    sstream >> studentFirstName;
    sstream.clear();
}

void Student::SetLastName(string __studentName) {
    //If a blank character exists in __studentname, we can assume the argument was passed as a full name.
    //We want to be careful about accepting either option, as the file I/O constructs Student objects with full names.
    if (__studentName.find(' ') != string::npos) {
        stringstream sstream(__studentName);
        string firstName;
        sstream >> firstName;
        sstream >> studentLastName;
    } else {
        studentLastName = __studentName;
    }
}

void Student::SetStudentGrades(vector<int> __gradesList) {
    studentGrades = __gradesList;
}

//Utility
double Student::FindAverage() {
    double quizGrade = ((studentGrades.at(0) * 10) + (studentGrades.at(1) * 10)) / 8.0;
    double midtermGrade = studentGrades.at(2) / 4.0;
    double finalExamGrade = studentGrades.at(3) / 2.0;
    return quizGrade + midtermGrade + finalExamGrade;
}