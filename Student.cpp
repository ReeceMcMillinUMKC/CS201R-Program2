#include <string>
#include <vector>

using namespace std;

class Student {
    public:
        //Class Logistics
        Student(int __studentID, string __studentName);

        //Get Private Variables
        int GetStudentID();
        string GetFirstName();
        string GetLastName();
        string FullName();
        vector<int> GetGrades();

        //Set Private Variables
        void SetStudentID(int __studentID);
        void SetFirstName(string __studentName);
        void SetLastName(string __studentName);
        void SetStudentGrades(vector<int> __gradesList);

        //Utility
        double FindAverage();

    private:
        int studentID;
        string studentFirstName;
        string studentLastName;
        vector<int> studentGrades;
};

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

string Student::FullName() {
    return studentLastName.append(", ").append(studentFirstName);
}

vector<int> Student::GetGrades() {
    return studentGrades;
}
        
//Set Private Variables
void Student::SetStudentID(int __studentID) {
    studentID = __studentID;
}

void Student::SetFirstName(string __studentName) {
    stringstream sstream(__studentName);
    sstream >> studentFirstName;
}

void Student::SetLastName(string __studentName) {
    stringstream sstream(__studentName);
    string firstName;
    sstream >> firstName;
    sstream >> studentLastName;
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