#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

const int NUMBER_OF_GRADES = 5;
const string OUTPUT_FILE = "student_averages.txt";

// Stores all information for one student.
struct Student {
    string name;
    int grades[NUMBER_OF_GRADES]{};
    double average = 0.0;
};

// Removes leftover invalid input from cin.
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Gets a non-empty student name. getline allows first and last names.
string getStudentName() {
    string name;

    do {
        cout << "Enter the student's name: ";
        getline(cin, name);

        if (name.empty()) {
            cout << "Name cannot be empty. Please try again.\n";
        }
    } while (name.empty());

    return name;
}

// Gets one grade and makes sure it is between 0 and 100.
int getValidGrade(int gradeNumber) {
    int grade;

    while (true) {
        cout << "Enter grade " << gradeNumber << " (0-100): ";

        if (cin >> grade && grade >= 0 && grade <= 100) {
            clearInput();
            return grade;
        }

        cout << "Invalid grade. Enter a whole number from 0 to 100.\n";
        clearInput();
    }
}

// Sorts one student's grades from highest to lowest using bubble sort.
void sortGradesDescending(int grades[]) {
    for (int pass = 0; pass < NUMBER_OF_GRADES - 1; pass++) {
        for (int i = 0; i < NUMBER_OF_GRADES - 1 - pass; i++) {
            if (grades[i] < grades[i + 1]) {
                int temporaryGrade = grades[i];
                grades[i] = grades[i + 1];
                grades[i + 1] = temporaryGrade;
            }
        }
    }
}

// Calculates the average of the five grades.
double calculateAverage(const int grades[]) {
    int total = 0;

    for (int i = 0; i < NUMBER_OF_GRADES; i++) {
        total += grades[i];
    }

    return static_cast<double>(total) / NUMBER_OF_GRADES;
}

// Creates and returns a completed Student record.
Student enterStudent() {
    Student student;
    student.name = getStudentName();

    for (int i = 0; i < NUMBER_OF_GRADES; i++) {
        student.grades[i] = getValidGrade(i + 1);
    }

    sortGradesDescending(student.grades);
    student.average = calculateAverage(student.grades);

    cout << "\nSorted grades: ";
    for (int grade : student.grades) {
        cout << grade << ' ';
    }

    cout << fixed << setprecision(2);
    cout << "\n" << student.name << "'s average is "
         << student.average << ".\n\n";

    return student;
}

// Sorts students from highest average to lowest average using bubble sort.
void sortStudentsByAverage(vector<Student>& students) {
    for (size_t pass = 0; pass + 1 < students.size(); pass++) {
        for (size_t i = 0; i + 1 < students.size() - pass; i++) {
            if (students[i].average < students[i + 1].average) {
                Student temporaryStudent = students[i];
                students[i] = students[i + 1];
                students[i + 1] = temporaryStudent;
            }
        }
    }
}

// Calculates the average for the entire class.
double calculateClassAverage(const vector<Student>& students) {
    double total = 0.0;

    for (const Student& student : students) {
        total += student.average;
    }

    return students.empty() ? 0.0 : total / students.size();
}

// Displays all students and the class average.
void displayReport(const vector<Student>& students) {
    cout << "\n========== CLASS REPORT ==========\n";
    cout << left << setw(5) << "Rank"
         << setw(28) << "Student"
         << right << setw(10) << "Average" << '\n';
    cout << string(43, '-') << '\n';

    for (size_t i = 0; i < students.size(); i++) {
        cout << left << setw(5) << i + 1
             << setw(28) << students[i].name
             << right << setw(10) << fixed << setprecision(2)
             << students[i].average << '\n';
    }

    cout << string(43, '-') << '\n';
    cout << "Class average: " << fixed << setprecision(2)
         << calculateClassAverage(students) << "\n\n";
}

// Saves the report to a text file.
bool saveReportToFile(const vector<Student>& students) {
    ofstream outputFile(OUTPUT_FILE);

    if (!outputFile) {
        return false;
    }

    outputFile << "========== CLASS REPORT ==========\n";
    outputFile << left << setw(5) << "Rank"
               << setw(28) << "Student"
               << right << setw(10) << "Average" << '\n';
    outputFile << string(43, '-') << '\n';

    for (size_t i = 0; i < students.size(); i++) {
        outputFile << left << setw(5) << i + 1
                   << setw(28) << students[i].name
                   << right << setw(10) << fixed << setprecision(2)
                   << students[i].average << '\n';
    }

    outputFile << string(43, '-') << '\n';
    outputFile << "Class average: " << fixed << setprecision(2)
               << calculateClassAverage(students) << '\n';

    return true;
}

// Converts text to lowercase so searching is not case-sensitive.
string toLowerCase(string text) {
    for (char& character : text) {
        character = static_cast<char>(tolower(static_cast<unsigned char>(character)));
    }

    return text;
}

// Searches for a student by name using a linear search.
void searchForStudent(const vector<Student>& students) {
    string searchName;
    cout << "Enter the student's name: ";
    getline(cin, searchName);

    string lowercaseSearchName = toLowerCase(searchName);

    for (const Student& student : students) {
        if (toLowerCase(student.name) == lowercaseSearchName) {
            cout << fixed << setprecision(2);
            cout << student.name << " has an average of "
                 << student.average << ".\n\n";
            return;
        }
    }

    cout << "Student not found.\n\n";
}

// Gets a valid menu selection.
int getMenuChoice() {
    int choice;

    while (true) {
        cout << "1. Add a student\n"
             << "2. View class report\n"
             << "3. Search for a student\n"
             << "4. Save report to file\n"
             << "5. Exit\n"
             << "Choose an option: ";

        if (cin >> choice && choice >= 1 && choice <= 5) {
            clearInput();
            return choice;
        }

        cout << "Invalid choice. Enter a number from 1 to 5.\n\n";
        clearInput();
    }
}

int main() {
    vector<Student> students;
    bool programRunning = true;

    cout << "===================================\n"
         << "      STUDENT GRADE ANALYZER\n"
         << "===================================\n\n";

    while (programRunning) {
        int choice = getMenuChoice();
        cout << '\n';

        switch (choice) {
            case 1:
                students.push_back(enterStudent());
                sortStudentsByAverage(students);
                break;

            case 2:
                if (students.empty()) {
                    cout << "No student records have been entered yet.\n\n";
                } else {
                    displayReport(students);
                }
                break;

            case 3:
                if (students.empty()) {
                    cout << "No student records are available to search.\n\n";
                } else {
                    searchForStudent(students);
                }
                break;

            case 4:
                if (students.empty()) {
                    cout << "Add at least one student before saving a report.\n\n";
                } else if (saveReportToFile(students)) {
                    cout << "Report saved to " << OUTPUT_FILE << ".\n\n";
                } else {
                    cout << "The report could not be saved.\n\n";
                }
                break;

            case 5:
                programRunning = false;
                cout << "Goodbye!\n";
                break;
        }
    }

    return 0;
}
