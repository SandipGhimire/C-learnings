#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outFile("lending_records.txt");

    if (!outFile) {
        cout << "Error opening file for writing!" << endl;
        return 1;
    }

    outFile << "1 C++ Basics Ram 2026-04-01\n";
    outFile << "2 OOP Concepts Sita 2026-04-02\n";
    outFile << "3 Data Structures Hari 2026-04-03\n";
    outFile.close();

    ifstream inFile("lending_records.txt");

    if (!inFile) {
        cout << "Error opening file for reading!" << endl;
        return 1;
    }

    string line;
    cout << "\nRecords:\n";
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();

    ofstream appendFile("lending_records.txt", ios::app);

    if (!appendFile) {
        cout << "Error opening file for appending!" << endl;
        return 1;
    }

    appendFile << "4 Algorithms Gita 2026-04-05\n";
    appendFile.close();

    return 0;
}