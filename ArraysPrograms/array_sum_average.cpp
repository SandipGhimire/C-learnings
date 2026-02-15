#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter Array Length: ";
    cin >> n;

    int arr[n];
    int sum = 0;

    for (int i = 0; i < n; i++) {
        cout << "Enter a number: ";
        cin >> arr[i];
        sum += arr[i];
    }

    double average = (double)sum / n;

    cout << "Sum: " << sum << endl;
    cout << "Average: " << average << endl;

    return 0;
}
