# Student Grade Analyzer

A beginner-friendly C++ console application that records student grades, calculates averages, ranks students, searches records, and saves a class report to a text file.

## Features

- Stores each student's name and five grades
- Validates grades to ensure they are between 0 and 100
- Accepts full names with spaces
- Sorts individual grades from highest to lowest
- Calculates student and class averages
- Ranks students by average using bubble sort
- Searches for students using a case-insensitive linear search
- Saves the class report to `student_averages.txt`
- Uses a menu-driven interface

## C++ Concepts Demonstrated

- Variables, loops, conditionals, and functions
- Arrays and vectors
- Structures (`struct`)
- Input validation
- Bubble sort and linear search
- File input/output
- Formatted console output

## Compile and Run

### macOS or Linux

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o grade_analyzer
./grade_analyzer
```

### Windows with MinGW

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o grade_analyzer.exe
grade_analyzer.exe
```

## Example Resume Description

**Student Grade Analyzer | C++**

- Developed a menu-driven C++ application that records and validates student grades, calculates individual and class averages, and ranks students by performance.
- Implemented bubble sort, linear search, structured data storage, case-insensitive matching, and text-file report generation.
- Improved program reliability through modular functions, full-name support, input validation, and error handling.

## Possible Future Improvements

- Load previously saved student records when the program starts
- Add letter-grade calculations
- Allow records to be edited or deleted
- Replace bubble sort with the C++ Standard Library sorting algorithm
