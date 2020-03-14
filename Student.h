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
        string GetFullName();
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