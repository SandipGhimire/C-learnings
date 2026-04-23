#include <iostream>
#include <fstream>
#include <thread>
using namespace std;

// Base Class
class FoodItem {
protected:
    int itemCode;
    string itemName;
    string category; // Snack, Meal, Drink
    float pricePerUnit;

public:
    void inputItem() {
        cout << "Enter Item Code: ";
        cin >> itemCode;
        cout << "Enter Item Name: ";
        cin >> itemName;
        cout << "Enter Category (Snack/Meal/Drink): ";
        cin >> category;
        cout << "Enter Price Per Unit: ";
        cin >> pricePerUnit;
    }

    void displayItem() {
        cout << "Item Code: " << itemCode << endl;
        cout << "Item Name: " << itemName << endl;
        cout << "Category: " << category << endl;
        cout << "Price Per Unit: " << pricePerUnit << endl;
    }
};

// Derived Class
class Order : public FoodItem {
private:
    string customerName;
    int quantity;
    float totalBill;

public:
    void inputOrder() {
        cout << "Enter Customer Name: ";
        cin >> customerName;
        cout << "Enter Quantity: ";
        cin >> quantity;
    }

    // Overloaded generateBill()
    float generateBill() {
        totalBill = pricePerUnit * quantity;
        return totalBill;
    }

    float generateBill(float serviceChargePercent) {
        totalBill = pricePerUnit * quantity;
        totalBill += totalBill * (serviceChargePercent / 100);
        return totalBill;
    }

    void displayOrder() {
        cout << "\nOrder Summary:\n";
        cout << "Customer Name: " << customerName << endl;
        displayItem();
        cout << "Quantity: " << quantity << endl;
        cout << "Total Bill: " << totalBill << endl;
    }

    string getCustomerName() {
        return customerName;
    }

    void writeToFile(ofstream &outFile) {
        outFile << customerName << " " << itemName << " "
                << quantity << " " << totalBill << endl;
    }
};

// Thread Functions
void kitchen(Order orders[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Preparing Order for: " << orders[i].getCustomerName() << endl;
    }
}

void cashier(Order orders[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Bill Generated for: " << orders[i].getCustomerName() << endl;
    }
}

int main() {
    const int SIZE = 3;
    Order orders[SIZE];

    // Input Orders
    for (int i = 0; i < SIZE; i++) {
        cout << "\nEnter details for Order " << i + 1 << endl;
        orders[i].inputItem();
        orders[i].inputOrder();
    }

    // Generate Bills (some with service charge)
    for (int i = 0; i < SIZE; i++) {
        if (i % 2 == 0)
            orders[i].generateBill(); // no service charge
        else
            orders[i].generateBill(5); // 5% service charge
    }

    // Display Orders
    for (int i = 0; i < SIZE; i++) {
        orders[i].displayOrder();
    }

    // Save Records to File
    ofstream outFile("canteen_sales.txt", ios::app);
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }
    for (int i = 0; i < SIZE; i++) {
        orders[i].writeToFile(outFile);
    }
    outFile.close();
    cout << "\nRecords saved to canteen_sales.txt\n";

    // (b) Read Records
    ifstream inFile("canteen_sales.txt");
    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }
    cout << "\nReading all saved orders:\n";
    string cust, item;
    int qty;
    float bill;
    while (inFile >> cust >> item >> qty >> bill) {
        cout << "Customer: " << cust
             << ", Item: " << item
             << ", Quantity: " << qty
             << ", Total Bill: " << bill << endl;
    }
    inFile.close();

    // Append one new order
    Order newOrder;
    cout << "\nEnter details for a new order to append:\n";
    newOrder.inputItem();
    newOrder.inputOrder();
    newOrder.generateBill(5); // 5% service charge
    ofstream appendFile("canteen_sales.txt", ios::app);
    if (!appendFile) {
        cerr << "Error opening file for appending!" << endl;
        return 1;
    }
    newOrder.writeToFile(appendFile);
    appendFile.close();
    cout << "New order appended to file.\n";

    // (b) Multithreading Simulation
    thread t1(kitchen, orders, SIZE);
    thread t2(cashier, orders, SIZE);

    t1.join();
    t2.join();

    return 0;
}