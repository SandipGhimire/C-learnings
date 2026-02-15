#include <iostream>
using namespace std;

void swapValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "After swap (Call by Value): " << a << " " << b << endl;
}

void swapReference(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x, y;

    cout << "Enter two numbers: ";
    cin >> x >> y;

    swapValue(x, y);

    swapReference(x, y);

    cout << "After swap (Call by Reference): " << x << " " << y << endl;

    return 0;
}
