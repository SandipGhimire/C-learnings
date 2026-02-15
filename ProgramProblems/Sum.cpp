#include <iostream>
using namespace std;

int add(int a, int b) {
    return a + b;
}

int main() {
    int num1, num2;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    int result = add(num1, num2);

    cout << "Sum is: " << result << "\n";

    return 0;
}
