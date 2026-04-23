#include <iostream>
#include <fstream>
#include <thread>
using namespace std;

// Base Class: Room
class Room {
protected:
    int roomNumber;
    string roomType; // Standard, Deluxe, Suite
    float pricePerNight;
    bool isAvailable;

public:
    void inputRoom() {
        cout << "Enter Room Number: ";
        cin >> roomNumber;
        cout << "Enter Room Type (Standard/Deluxe/Suite): ";
        cin >> roomType;
        cout << "Enter Price per Night: ";
        cin >> pricePerNight;
        isAvailable = true; // default available
    }

    void displayRoom() {
        cout << "Room Number: " << roomNumber << endl;
        cout << "Room Type: " << roomType << endl;
        cout << "Price per Night: " << pricePerNight << endl;
        cout << "Availability: " << (isAvailable ? "Available" : "Occupied") << endl;
    }
};

// Derived Class: Reservation
class Reservation : public Room {
private:
    string guestName;
    int guestID;
    int numberOfNights;
    float totalCharge;

public:
    void inputReservation() {
        cout << "Enter Guest Name: ";
        cin >> guestName;
        cout << "Enter Guest ID: ";
        cin >> guestID;
        cout << "Enter Number of Nights: ";
        cin >> numberOfNights;
        isAvailable = false; // mark room as occupied
    }

    // Overloaded calculateCharge()
    float calculateCharge() {
        totalCharge = pricePerNight * numberOfNights;
        return totalCharge;
    }

    float calculateCharge(float taxPercent, float serviceFee) {
        totalCharge = pricePerNight * numberOfNights;
        totalCharge += totalCharge * (taxPercent / 100) + serviceFee;
        return totalCharge;
    }

    void displayReservation() {
        cout << "\nReservation Summary:\n";
        cout << "Guest Name: " << guestName << endl;
        cout << "Guest ID: " << guestID << endl;
        displayRoom();
        cout << "Number of Nights: " << numberOfNights << endl;
        cout << "Total Charge: " << totalCharge << endl;
    }

    string getGuestName() { return guestName; }
    int getRoomNumber() { return roomNumber; }

    void writeToFile(ofstream &outFile) {
        outFile << guestName << " " << guestID << " " << roomNumber << " "
                << roomType << " " << numberOfNights << " " << totalCharge << endl;
    }
};

// Thread Functions
void frontDesk(Reservation reservations[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Checking in Guest: " << reservations[i].getGuestName()
             << " — Room " << reservations[i].getRoomNumber() << endl;
    }
}

void housekeeping(Reservation reservations[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Preparing Room " << reservations[i].getRoomNumber()
             << " for " << reservations[i].getGuestName() << endl;
    }
}

int main() {
    const int SIZE = 3;
    Reservation reservations[SIZE];

    // Input Reservations
    for (int i = 0; i < SIZE; i++) {
        cout << "\nEnter details for Reservation " << i + 1 << endl;
        reservations[i].inputRoom();
        reservations[i].inputReservation();
    }

    // Calculate Charges
    reservations[0].calculateCharge();            // no tax/service
    reservations[1].calculateCharge(12, 50);     // tax 12%, service fee 50
    reservations[2].calculateCharge(15, 75);     // tax 15%, service fee 75

    // Display Reservations
    for (int i = 0; i < SIZE; i++) {
        reservations[i].displayReservation();
    }

    // Save to file
    ofstream outFile("reservations.txt", ios::app);
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }
    for (int i = 0; i < SIZE; i++) {
        reservations[i].writeToFile(outFile);
    }
    outFile.close();
    cout << "\nReservations saved to reservations.txt\n";

    // Read and display saved records
    ifstream inFile("reservations.txt");
    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }
    cout << "\nAll Saved Reservations:\n";
    string name, type;
    int id, roomNum, nights;
    float charge;
    while (inFile >> name >> id >> roomNum >> type >> nights >> charge) {
        cout << "Guest: " << name << ", ID: " << id
             << ", Room: " << roomNum << ", Type: " << type
             << ", Nights: " << nights << ", Total Charge: " << charge << endl;
    }
    inFile.close();

    // Append a new late reservation
    Reservation lateReservation;
    cout << "\nEnter details for a late reservation:\n";
    lateReservation.inputRoom();
    lateReservation.inputReservation();
    lateReservation.calculateCharge(10, 40);
    ofstream appendFile("reservations.txt", ios::app);
    if (!appendFile) {
        cerr << "Error opening file to append!" << endl;
        return 1;
    }
    lateReservation.writeToFile(appendFile);
    appendFile.close();
    cout << "Late reservation appended.\n";

    // Multithreading Simulation
    thread t1(frontDesk, reservations, SIZE);
    thread t2(housekeeping, reservations, SIZE);
    t1.join();
    t2.join();

    return 0;
}