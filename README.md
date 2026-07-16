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

