#include <iostream>
using namespace std;

bool isArmstrong(int num) {
    int original = num;
    int sum = 0;

    while (num > 0) {
        int digit = num % 10;
        sum += digit * digit * digit;
        num = num / 10;
    }

    return original == sum;
}

int main() {
    int number;

    cout << "Enter a number: ";
    cin >> number;

    if (isArmstrong(number))
        cout << "Armstrong Number" << endl;
    else
        cout << "Not an Armstrong Number" << endl;

    return 0;
}
