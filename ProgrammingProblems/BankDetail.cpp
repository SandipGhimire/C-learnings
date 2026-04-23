#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string holderName;
    float balance;

public:
    void setData(int accNo, string name, float bal) {
        accountNumber = accNo;
        holderName = name;
        balance = bal;
    }

    void deposit(float amount) {
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    void withdraw(float amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    void displayBalance() {
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    BankAccount acc;
    acc.setData(101, "Ram", 1000);

    acc.deposit(500);
    acc.withdraw(300);
    acc.displayBalance();

    return 0;
}