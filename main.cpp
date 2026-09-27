#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int getValidChoice() {

    int choice;

    while (true) {

        cout << "\nEnter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Invalid input! Enter a number from 1 to 8.\n";
        }
        else if (choice < 1 || choice > 8) {
            cout << "Please enter a choice from 1 to 8.\n";
        }
        else {
            return choice;
        }
    }
}

int getValidRollNo() {

    int rollNo;

    while (true) {

        cout << "\nEnter Roll Number: ";
        cin >> rollNo;

        if (cin.fail()) {

            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Invalid input! Enter a number.\n";
        }
        else if (rollNo <= 0) {

            cout << "Roll number must be greater than 0.\n";
        }
        else {

            return rollNo;
        }
    }
}

float getValidMarks(string subject) {

    float marks;

    while (true) {

        cout << subject << ": ";
        cin >> marks;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Invalid input! Enter a number.\n";
        }
        else if (marks < 0 || marks > 100) {

            cout << "Marks must be between 0 and 100.\n";
        }
        else {
            return marks;
        }
    }
}

class Student {
private:
    int rollNo;
    string name;

    float maths;
    float physics;
    float computer;
    float english;
    float electronics;

public:
    void input() {

        cin.ignore();

        cout << "Enter Student Name: ";
        getline(cin, name);

        cout << "\nEnter Marks (out of 100)\n";

        maths = getValidMarks("Mathematics");
        physics = getValidMarks("Physics");
        computer = getValidMarks("Computer Science");
        english = getValidMarks("English");
        electronics = getValidMarks("Electronics");
    }

    void saveToFile(ofstream &file) {
        file << rollNo << endl;
        file << name << endl;
        file << maths << endl;
        file << physics << endl;
        file << computer << endl;
        file << english << endl;
        file << electronics << endl;
    }

    bool loadFromFile(ifstream &file) {

        if (!(file >> rollNo))
            return false;

        file.ignore();

        getline(file, name);

        file >> maths;
        file >> physics;
        file >> computer;
        file >> english;
        file >> electronics;

    return true;
    }

    float calculateTotal() {
        return maths + physics + computer + english + electronics;
    }

    float calculatePercentage() {
        return calculateTotal() / 5.0;
    }

    char calculateGrade() {

        float percentage = calculatePercentage();

        if (percentage >= 90)
            return 'A';
        else if (percentage >= 80)
            return 'B';
        else if (percentage >= 70)
            return 'C';
        else if (percentage >= 60)
            return 'D';
        else
            return 'F';
    }

    void display() {

        cout << "\nRoll Number      : " << rollNo;
        cout << "\nName             : " << name;

        cout << "\nMathematics      : " << maths;
        cout << "\nPhysics          : " << physics;
        cout << "\nComputer Science : " << computer;
        cout << "\nEnglish          : " << english;
        cout << "\nElectronics      : " << electronics;

        cout << "\nTotal Marks      : " << calculateTotal() << "/500";
        cout << "\nPercentage       : " << calculatePercentage() << "%";
        cout << "\nGrade            : " << calculateGrade() << endl;
    }

    int getRollNo() {
        return rollNo;
    }

    void setRollNo(int r) {
        rollNo = r;
    }

    string getName() {
        return name;
    }

    void update() {

        cin.ignore();

        cout << "Enter New Name: ";
        getline(cin, name);

        cout << "\nEnter New Marks (out of 100)\n";

        maths = getValidMarks("Mathematics");

        physics = getValidMarks("Physics");

        computer = getValidMarks("Computer Science");

        english = getValidMarks("English");

        electronics = getValidMarks("Electronics");
    }
};

void saveStudents(vector<Student> &students) {

    ofstream file("students.txt");

    if (!file) {
        cout << "\nError opening file!\n";
        return;
    }

    for (int i = 0; i < students.size(); i++) {
        students[i].saveToFile(file);
    }

    file.close();
}

void loadStudents(vector<Student> &students) {

    ifstream file("students.txt");

    if (!file) {
        return;
    }

    Student student;

    while (student.loadFromFile(file)) {
        students.push_back(student);
    }

    file.close();
}

int main() {
    vector<Student> students;
    loadStudents(students);
    int choice;

    do {
        cout << "\n====================================\n";
        cout << "   STUDENT MANAGEMENT SYSTEM\n";
        cout << "====================================\n";

        cout << "1. Add Student\n";
        cout << "2. View All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Rank Students by Percentage\n";
        cout << "7. Performance Report\n";
        cout << "8. Exit\n";

        choice = getValidChoice();

        switch (choice) {

        case 1: {

            int newRollNo;
            bool duplicate = false;

            newRollNo = getValidRollNo();

            // Check whether roll number already exists
            for (int i = 0; i < students.size(); i++) {

                if (students[i].getRollNo() == newRollNo) {
                    duplicate = true;
                    break;
                }
            }

            if (duplicate) {
                cout << "\nError: Roll number already exists!\n";
            }
            else {

                Student newStudent;

                newStudent.setRollNo(newRollNo);

                newStudent.input();

                students.push_back(newStudent);

                saveStudents(students);

                cout << "\nStudent added successfully!\n";
            }

            break;
        }

        case 2:
            if (students.empty()) {
            cout << "\nNo student records found.\n";
            }
            else {
            cout << "\n========== STUDENT RECORDS ==========\n";

            for (int i = 0; i < students.size(); i++) {

                cout << "\nStudent " << i + 1 << endl;
                cout << "-------------------------";

                students[i].display();
            }
            }

            break;

        case 3: {
            int searchRollNo;
            bool found = false;

            cout << "\nSearch Student\n";
            searchRollNo = getValidRollNo();

            for (int i = 0; i < students.size(); i++) {

                if (students[i].getRollNo() == searchRollNo) {

                    cout << "\nStudent Found!\n";
                    cout << "-------------------------\n";

                students[i].display();

                found = true;
            break;
            }
        }

        if (!found) {
            cout << "\nStudent not found.\n";
        }

        break;
        }

        case 4: {
            int updateRollNo;
            bool found = false;

            cout << "\nUpdate Student\n";
            updateRollNo = getValidRollNo();

            for (int i = 0; i < students.size(); i++) {

                if (students[i].getRollNo() == updateRollNo) {

                    cout << "\nCurrent Student Details:\n";
                    students[i].display();

                    cout << "\nEnter New Details:\n";
                    students[i].update();

                    saveStudents(students);

                    cout << "\nStudent updated successfully!\n";

                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "\nStudent not found.\n";
            }

            break;
        }

        case 5: {
            int deleteRollNo;
            bool found = false;

            cout << "\nDelete Student\n";
            deleteRollNo = getValidRollNo();

            for (int i = 0; i < students.size(); i++) {

                if (students[i].getRollNo() == deleteRollNo) {

                    students.erase(students.begin() + i);

                    saveStudents(students);

                    cout << "\nStudent deleted successfully!\n";

                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "\nStudent not found.\n";
            }

            break;
        }

        case 6: {

            if (students.empty()) {
                cout << "\nNo student records available.\n";
                break;
            }

            sort(students.begin(), students.end(),
                [](Student &a, Student &b) {
                    return a.calculatePercentage() > b.calculatePercentage();
                }
            );

            cout << "\nStudents sorted by percentage successfully!\n";

            cout << "\n========== RANKING ==========\n";

            for (int i = 0; i < students.size(); i++) {
                cout << "\nRank " << i + 1;
                students[i].display();
                cout << "-----------------------------\n";
            }

            break;
        }

        case 7: {

            if (students.empty()) {
                cout << "\nNo student records available.\n";
                break;
            }

            float totalPercentage = 0;
            float highestPercentage = students[0].calculatePercentage();

            string topperName = students[0].getName();

            int passCount = 0;
            int failCount = 0;

            for (int i = 0; i < students.size(); i++) {

                float percentage = students[i].calculatePercentage();

                totalPercentage += percentage;

                // Find topper
                if (percentage > highestPercentage) {
                    highestPercentage = percentage;
                    topperName = students[i].getName();
                }

                // Count pass/fail
                if (percentage >= 60)
                    passCount++;
                else
                    failCount++;
            }       

            float classAverage =
                totalPercentage / students.size();
        
            cout << "\n====================================\n";
            cout << "       PERFORMANCE REPORT\n";
            cout << "====================================\n";

            cout << "Total Students     : "
                 << students.size() << endl;

            cout << "Class Average      : "
                 << classAverage << "%" << endl;

            cout << "Topper             : "
                << topperName << endl;

            cout << "Highest Percentage : "
                 << highestPercentage << "%" << endl;

            cout << "Passed Students    : "
                 << passCount << endl;

            cout << "Failed Students    : "
                 << failCount << endl;

            cout << "====================================\n";

            break;
        }

        case 8:
            cout << "\nThank you for using the system!\n";
            break;

        default:
            cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 8);

    return 0;
}