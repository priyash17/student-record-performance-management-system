# Student Record & Performance Management System

A console-based Student Record and Performance Management System developed in C++. The project manages student academic records, calculates performance metrics, ranks students, and stores records using file handling.

## Features

- Add new student records
- Prevent duplicate roll numbers
- View all student records
- Search students using roll number
- Update existing student details
- Delete student records
- Store marks for five subjects
- Calculate total marks and percentage
- Assign grades based on percentage
- Rank students according to percentage
- Generate a class performance report
- Identify the class topper
- Calculate class average
- Display passed and failed student counts
- Validate roll numbers, marks, and menu input
- Save and load student records using file handling

## Subjects

The system currently manages marks for:

- Mathematics
- Physics
- Computer Science
- English
- Electronics

Each subject is evaluated out of 100 marks.

## Technologies Used

- C++
- Object-Oriented Programming (OOP)
- STL Vector
- STL Sort
- File Handling
- Lambda Expression
- Input Validation

## C++ Concepts Used

### Classes and Objects

The `Student` class represents individual student records and stores information such as roll number, name, and subject marks.

### Encapsulation

Student data is stored as private data members and accessed or modified through public member functions.

### Vector

`vector<Student>` is used to dynamically store multiple student objects during program execution.

### Searching

The program uses linear search to locate students using their roll number.

### Sorting

Students are ranked according to percentage using the STL `sort()` function with a lambda expression.

### File Handling

Student records are stored in `students.txt` using `ofstream` and loaded using `ifstream`. This allows records to remain available after the program is closed and restarted.

### Input Validation

The program validates marks to ensure they are between 0 and 100. It also validates numeric input and prevents duplicate roll numbers.

## Performance Report

The system generates a performance report containing:

- Total number of students
- Class average percentage
- Top-performing student
- Highest percentage
- Number of passed students
- Number of failed students

For this project, a percentage of 60% or above is considered passing.

## Menu

```text
1. Add Student
2. View All Students
3. Search Student
4. Update Student
5. Delete Student
6. Rank Students by Percentage
7. Performance Report
8. Exit
```

## How to Compile and Run

Using the GNU C++ compiler:

```bash
g++ main.cpp -o student
```

Run on Windows PowerShell:

```powershell
.\student.exe
```

## Project Structure

```text
StudentManagementSystem/
│
├── main.cpp
├── README.md
└── students.txt
```

`students.txt` is created and used by the program for storing student records.

## Future Improvements

Possible future improvements include:

- Subject-wise performance analysis
- Improved file format or database integration
- Separate administrator and student interfaces
- Graphical user interface
- More advanced reporting and filtering

## Purpose

This project was developed to strengthen practical understanding of C++ fundamentals, object-oriented programming, STL containers and algorithms, file handling, input validation, and basic record-management operations.