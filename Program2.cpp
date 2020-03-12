#include <iostream>
#include <string>
#include <unordered_map>
#include "StudentUtilities.cpp"

using namespace std;

int main() {
    unordered_map<int, vector<int>> studentIDtoGrades;
    vector<Student> studentRoster;

    studentIDtoGrades = ReadGrades("Grades.txt");
    studentRoster = ReadStudents("INFO.txt");

    for (Student x : studentRoster) {
        cout << "ID: " << x.GetStudentID() << ", Grades: ";
        printVector(studentIDtoGrades[x.GetStudentID()]);
    }
}