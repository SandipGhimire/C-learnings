#include <iostream>
using namespace std;

double simpleInterest(double p, double r, double t) {
    return (p * r * t) / 100;
}

int main() {
    double p, r, t;

    cout << "Enter principal, rate and time: ";
    cin >> p >> r >> t;

    cout << "Simple Interest: " << simpleInterest(p, r, t) << endl;

    return 0;
}
