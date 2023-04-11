#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

// Define the number of students per class and per stream
const int NUM_STUDENTS_BIO = 3 * 40;
const int NUM_STUDENTS_MATH = 5 * 40;

// Define the number of subjects per student
const int NUM_SUBJECTS_BIO = 3;
const int NUM_SUBJECTS_MATH = 3;

// Define the class structure
struct Student {
    string name;
    double marks[NUM_SUBJECTS_BIO]; // or NUM_SUBJECTS_MATH for Maths students
    double totalMarks;
    int rank;
};

// Define the functions to sort the students based on their total marks
bool compareTotalMarks(Student a, Student b) {
    return a.totalMarks > b.totalMarks;
}

// Define the function to calculate the ranks of the students
void calculateRanks(vector<Student>& students) {
    sort(students.begin(), students.end(), compareTotalMarks);
    int rank = 1;
    for (int i = 0; i < students.size(); i++) {
        if (i > 0 && students[i].totalMarks < students[i-1].totalMarks) {
            rank = i+1;
        }
        students[i].rank = rank;
    }
}

int main() {

    // Define the vectors to hold the students
    vector<Student> bioStudents;
    vector<Student> mathStudents;

    // Get the marks of the students for each subject
    for (int i = 0; i < NUM_STUDENTS_BIO; i++) {

        // Create a new student
        Student s;
        cout << "Enter the name of Bio student " << i+1 << ": ";
        getline(cin, s.name);

        // Get the marks of the student for each subject
        cout << "Enter the marks of " << s.name << " for Biology, Physics and Chemistry (out of 100): ";
        for (int j = 0; j < NUM_SUBJECTS_BIO; j++) {
            cin >> s.marks[j];
            s.totalMarks += s.marks[j];
        }

        // Add the student to the Bio stream
        bioStudents.push_back(s);
        cin.ignore();
    }

    for (int i = 0; i < NUM_STUDENTS_MATH; i++) {

        // Create a new student
        Student s;
        cout << "Enter the name of Math student " << i+1 << ": ";
        getline(cin, s.name);

        // Get the marks of the student for each subject
        cout << "Enter the marks of " << s.name << " for Combined Maths, Physics and Chemistry (out of 100): ";
        for (int j = 0; j < NUM_SUBJECTS_MATH; j++) {
            cin >> s.marks[j];
            s.totalMarks += s.marks[j];
        }

        // Add the student to the Math stream
        mathStudents.push_back(s);
        cin.ignore();
    }

    // Calculate the ranks of the students
    calculateRanks(bioStudents);
    calculateRanks(mathStudents);

    // Print the school rank list
    vector<Student> schoolStudents = bioStudents;
    schoolStudents.insert(schoolStudents.end(), mathStudents.begin(), mathStudents.end());
    calculateRanks(schoolStudents);

    cout << endl << "------------------ School Rank List ------------------" << endl << endl;
    cout << "Rank" << setw(10) << "Name" << setw
