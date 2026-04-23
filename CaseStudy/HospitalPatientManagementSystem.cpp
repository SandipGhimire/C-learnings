#include <iostream>
#include <fstream>
#include <thread>
using namespace std;

// Base Class
class Patient {
protected:
    int patientID;
    string name;
    int age;
    string disease;

public:
    void inputDetails() {
        cout << "Enter Patient ID: ";
        cin >> patientID;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Disease: ";
        cin >> disease;
    }

    void displayDetails() {
        cout << "Patient ID: " << patientID << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Disease: " << disease << endl;
    }

    int getID() {
        return patientID;
    }
};

// Derived Class
class Treatment : public Patient {
private:
    float consultationFee;
    float medicineCost;

public:
    void inputTreatment() {
        cout << "Enter Consultation Fee: ";
        cin >> consultationFee;
        cout << "Enter Medicine Cost: ";
        cin >> medicineCost;
    }

    // Overloaded Function (1)
    float calculateBill() {
        return consultationFee + medicineCost;
    }

    // Overloaded Function (2)
    float calculateBill(float discountPercent) {
        float total = consultationFee + medicineCost;
        float discount = total * (discountPercent / 100);
        return total - discount;
    }

    void writeToFile(ofstream &outFile) {
        outFile << patientID << " " << name << " " << age << " " << disease << " "
                << consultationFee << " " << medicineCost << endl;
    }
};

// Thread Functions
void admission(Treatment patients[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Registering Patient ID: "
             << patients[i].getID() << endl;
    }
}

void billing(Treatment patients[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Generating Bill for Patient ID: "
             << patients[i].getID() << endl;
    }
}

// Main Function
int main() {
    const int SIZE = 3;
    Treatment patients[SIZE];

    // Input
    for (int i = 0; i < SIZE; i++) {
        cout << "\nEnter details for Patient " << i + 1 << endl;
        patients[i].inputDetails();
        patients[i].inputTreatment();
    }

    // Display & Bill Calculation
    for (int i = 0; i < SIZE; i++) {
        cout << "\nPatient " << i + 1 << " Details:\n";
        patients[i].displayDetails();

        float bill = patients[i].calculateBill();
        float discountedBill = patients[i].calculateBill(10); // 10% discount

        cout << "Total Bill (No Discount): " << bill << endl;
        cout << "Total Bill (With 10% Discount): " << discountedBill << endl;
    }

    // File Writing
    ofstream outFile("hospital_records.txt");
    for (int i = 0; i < SIZE; i++) {
        patients[i].writeToFile(outFile);
    }
    outFile.close();

    cout << "\nRecords saved to file.\n";

    // (b)(i) File Reading
    ifstream inFile("hospital_records.txt");
    cout << "\nReading from file:\n";

    int id, age;
    string name, disease;
    float fee, med;

    while (inFile >> id >> name >> age >> disease >> fee >> med) {
        cout << "\nPatient ID: " << id
             << "\nName: " << name
             << "\nAge: " << age
             << "\nDisease: " << disease
             << "\nConsultation Fee: " << fee
             << "\nMedicine Cost: " << med << endl;
    }
    inFile.close();

    // (b)(ii) Multithreading
    thread t1(admission, patients, SIZE);
    thread t2(billing, patients, SIZE);

    t1.join();
    t2.join();

    return 0;
}