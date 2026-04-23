#include <iostream>
#include <fstream>
#include <thread>
using namespace std;

// Base Class
class Student {
protected:
    int rollNo;
    string name;
    string className;

public:
    void inputDetails() {
        cout << "Enter Roll No: ";
        cin >> rollNo;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Class: ";
        cin >> className;
    }

    void displayDetails() {
        cout << "Roll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Class: " << className << endl;
    }

    int getRollNo() {
        return rollNo;
    }
};

// Derived Class
class Result : public Student {
private:
    float marks[5];
    float total;
    float percentage;

public:
    void inputMarks() {
        total = 0;
        cout << "Enter marks for 5 subjects:\n";
        for (int i = 0; i < 5; i++) {
            cin >> marks[i];
            total += marks[i];
        }
        percentage = total / 5;
    }

    // Overloaded function (1)
    void displayResult() {
        cout << "Total: " << total << endl;
        cout << "Percentage: " << percentage << "%" << endl;
    }

    // Overloaded function (2)
    void displayResult(bool showGrade) {
        displayResult(); // reuse
        if (showGrade) {
            char grade;
            if (percentage >= 80) grade = 'A';
            else if (percentage >= 60) grade = 'B';
            else if (percentage >= 50) grade = 'C';
            else if (percentage >= 40) grade = 'D';
            else grade = 'F';

            cout << "Grade: " << grade << endl;
        }
    }

    void writeToFile(ofstream &outFile) {
        outFile << rollNo << " " << name << " " << className << " ";
        for (int i = 0; i < 5; i++) {
            outFile << marks[i] << " ";
        }
        outFile << total << " " << percentage << endl;
    }
};

// Thread Functions
void markAttendance(Result students[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Marking Attendance for Roll No: "
             << students[i].getRollNo() << endl;
    }
}

void calculateResults(Result students[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Calculating Result for Roll No: "
             << students[i].getRollNo() << endl;
    }
}

// Main Function
int main() {
    const int SIZE = 3;
    Result students[SIZE];

    // Input Data
    for (int i = 0; i < SIZE; i++) {
        cout << "\nEnter details for student " << i + 1 << endl;
        students[i].inputDetails();
        students[i].inputMarks();
    }

    // Display Results (both overloaded versions)
    for (int i = 0; i < SIZE; i++) {
        cout << "\nStudent " << i + 1 << " Details:\n";
        students[i].displayDetails();

        cout << "--- Without Grade ---\n";
        students[i].displayResult();

        cout << "--- With Grade ---\n";
        students[i].displayResult(true);
    }

    // File Writing
    ofstream outFile("grade_records.txt");
    for (int i = 0; i < SIZE; i++) {
        students[i].writeToFile(outFile);
    }
    outFile.close();

    cout << "\nRecords saved to file.\n";

    // (b)(i) File Reading
    ifstream inFile("grade_records.txt");
    cout << "\nReading from file:\n";

    int roll;
    string name, cls;
    float m[5], total, percentage;

    while (inFile >> roll >> name >> cls) {
        for (int i = 0; i < 5; i++) {
            inFile >> m[i];
        }
        inFile >> total >> percentage;

        cout << "\nRoll No: " << roll
             << "\nName: " << name
             << "\nClass: " << cls
             << "\nTotal: " << total
             << "\nPercentage: " << percentage << "%\n";
    }
    inFile.close();

    // (b)(ii) Multithreading
    thread t1(markAttendance, students, SIZE);
    thread t2(calculateResults, students, SIZE);

    t1.join();
    t2.join();

    return 0;
}