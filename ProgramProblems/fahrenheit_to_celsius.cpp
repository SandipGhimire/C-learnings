#include <iostream>
using namespace std;

double convert(double f) {
    return (f - 32) * 5 / 9;
}

int main() {
    double fahrenheit;

    cout << "Enter temperature in Fahrenheit: ";
    cin >> fahrenheit;

    cout << "Temperature in Celsius: " << convert(fahrenheit) << endl;

    return 0;
}
