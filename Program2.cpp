//Reece McMillin

#include "StudentUtilities.cpp"

using namespace std;

int main() {
    vector<Student> studentRoster;
    int userChoice {1};
    
    /* In following common design principles, I've elected to implement file I/O separate from the Student class.
     * As each file contains information about *every* student as opposed to an individual, it doesn't make sense as a method on individual objects.
     * 
     * Students are generated with grades automatically collected via ReadStudents(), which takes as input a filename and a map (via ReadGrades()) from a student's ID to that student's grades.
     * Individual objects are collected into a vector<Student>, studentRoster, which can be given as a collection to below Print* functions.
     */
    try {
        studentRoster = ReadStudents("INFO.txt", ReadGrades("Grades.txt"));
    } catch (runtime_error &excpt) {
        //If we can't read the file, we want to exit gracefully but immediately.
        //excpt.what() holds information on which file was unreadable.
        cout << excpt.what() << endl;
        return -1;
    }
    
    //userChoice is verified against unordered_set {1, 2, 3, 4} in MainMenu(), cannot evaluate to 0 in main().
    //This causes while (userChoice) to effectively operate as an indefinite loop, but with a clearer intention towards when to break.
    while (userChoice) {
        userChoice = MainMenu();
        switch (userChoice) {
            case 1:
                PrintClassRoster(studentRoster);
                break;
            case 2:
                PrintClassRosterWithGrades(studentRoster);
                break;
            case 3:
                PrintClassRosterWithWeightedGrades(studentRoster);
                break;
            case 4:
                return 0;
        }
    }
}