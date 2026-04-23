#include <iostream>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    float marks;

public:
    void setData(int r, string n, float m) {
        rollNo = r;
        name = n;
        marks = m;
    }

    void displayData() {
        cout << "Roll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main() {
    Student s;
    s.setData(1, "Sita", 85.5);
    s.displayData();

    return 0;
}