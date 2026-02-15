#include <iostream>
using namespace std;

inline int square(int number) {
    return number * number;
}

int main() {
    int num;

    cout << "Enter a number: ";
    cin >> num;

    int result = square(num);

    cout << "Square is: " << result << "\n";

    return 0;
}
