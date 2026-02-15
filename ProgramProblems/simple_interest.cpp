#include <iostream>
using namespace std;

double calculateInterest(double principal, double rate = 5, double time = 1) {
    return (principal * rate * time) / 100;
}

int main() {
    double principal;

    cout << "Enter principal amount: ";
    cin >> principal;

    double interest = calculateInterest(principal);

    cout << "Simple Interest is: " << interest << "\n";

    return 0;
}
