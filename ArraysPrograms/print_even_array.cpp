#include <iostream>
using namespace std;

void printEven(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0)
            cout << arr[i] << " ";
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "Even numbers are: ";
    printEven(arr, n);
    cout << endl;

    return 0;
}
