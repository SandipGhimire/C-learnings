#include <iostream>
using namespace std;

double area(double radius) {
    return 3.14 * radius * radius;
}

double area(double length, double width) {
    return length * width;
}

int main() {
    double radius, length, width;

    cout << "Enter radius of circle: ";
    cin >> radius;

    cout << "Area of circle: " << area(radius) << endl;

    cout << "Enter length and width of rectangle: ";
    cin >> length >> width;

    cout << "Area of rectangle: " << area(length, width) << "\n";

    return 0;
}
