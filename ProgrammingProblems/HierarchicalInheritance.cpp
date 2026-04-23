#include <iostream>
using namespace std;

class Vehicle {
public:
    string brand;
    float topSpeed;

    void inputData() {
        cout << "Enter brand and top speed: ";
        cin >> brand >> topSpeed;
    }

    void displayData() {
        cout << "Brand: " << brand << endl;
        cout << "Top Speed: " << topSpeed << endl;
    }
};

class Car : public Vehicle {
public:
    int numberOfDoors;

    void displayCar() {
        displayData();
        cout << "Doors: " << numberOfDoors << endl;
    }
};

class Bike : public Vehicle {
public:
    bool hasSidecar;

    void displayBike() {
        displayData();
        cout << "Sidecar: " << (hasSidecar ? "Yes" : "No") << endl;
    }
};

int main() {
    Car c;
    Bike b;

    c.brand = "Toyota";
    c.topSpeed = 180;
    c.numberOfDoors = 4;

    b.brand = "Yamaha";
    b.topSpeed = 120;
    b.hasSidecar = false;

    cout << "\nCar Details:\n";
    c.displayCar();

    cout << "\nBike Details:\n";
    b.displayBike();

    return 0;
}