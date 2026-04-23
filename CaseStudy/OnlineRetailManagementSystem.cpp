#include <iostream>
#include <fstream>
#include <thread>
using namespace std;

// Base Class
class Product {
protected:
    int productCode;
    string productName;
    float unitPrice;

public:
    void inputProduct() {
        cout << "Enter Product Code: ";
        cin >> productCode;
        cout << "Enter Product Name: ";
        cin >> productName;
        cout << "Enter Unit Price: ";
        cin >> unitPrice;
    }

    void displayProduct() {
        cout << "Product Code: " << productCode << endl;
        cout << "Product Name: " << productName << endl;
        cout << "Unit Price: " << unitPrice << endl;
    }

    int getCode() {
        return productCode;
    }
};

// Derived Class
class Order : public Product {
private:
    int quantity;
    string customerName;

public:
    void inputOrder() {
        cout << "Enter Customer Name: ";
        cin >> customerName;
        cout << "Enter Quantity: ";
        cin >> quantity;
    }

    // Overloaded Function (1)
    float computeTotal() {
        return unitPrice * quantity;
    }

    // Overloaded Function (2)
    float computeTotal(float taxRate) {
        float total = unitPrice * quantity;
        float tax = total * (taxRate / 100);
        return total + tax;
    }

    void displayOrder() {
        displayProduct();
        cout << "Customer Name: " << customerName << endl;
        cout << "Quantity: " << quantity << endl;
    }

    void writeToFile(ofstream &outFile) {
        outFile << productCode << " " << productName << " " << unitPrice << " "
                << customerName << " " << quantity << endl;
    }
};

// Thread Functions
void orderProcessor(Order orders[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Order Confirmed for Product: "
             << orders[i].getCode() << endl;
    }
}

void stockUpdater(Order orders[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Stock Updated for Product: "
             << orders[i].getCode() << endl;
    }
}

// Main Function
int main() {
    const int SIZE = 3;
    Order orders[SIZE];

    // Input
    for (int i = 0; i < SIZE; i++) {
        cout << "\nEnter details for Order " << i + 1 << endl;
        orders[i].inputProduct();
        orders[i].inputOrder();
    }

    // Display & Bill Calculation
    for (int i = 0; i < SIZE; i++) {
        cout << "\nOrder " << i + 1 << " Details:\n";
        orders[i].displayOrder();

        float total = orders[i].computeTotal();
        float totalWithTax = orders[i].computeTotal(13); // 13% tax

        cout << "Total (No Tax): " << total << endl;
        cout << "Total (With Tax 13%): " << totalWithTax << endl;
    }

    // File Writing
    ofstream outFile("orders.txt");
    for (int i = 0; i < SIZE; i++) {
        orders[i].writeToFile(outFile);
    }
    outFile.close();

    cout << "\nRecords saved to file.\n";

    // (b)(i) File Reading
    ifstream inFile("orders.txt");
    cout << "\nReading from file:\n";

    int code, qty;
    string pname, cname;
    float price;

    while (inFile >> code >> pname >> price >> cname >> qty) {
        cout << "\nProduct Code: " << code
             << "\nProduct Name: " << pname
             << "\nUnit Price: " << price
             << "\nCustomer Name: " << cname
             << "\nQuantity: " << qty << endl;
    }
    inFile.close();

    // (b)(ii) Multithreading
    thread t1(orderProcessor, orders, SIZE);
    thread t2(stockUpdater, orders, SIZE);

    t1.join();
    t2.join();

    return 0;
}