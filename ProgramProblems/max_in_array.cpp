#include <iostream>
using namespace std;

int findMax(int arr[], int size) {
    int max = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

int main() {
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++) {
        cout << "Enter a number: ";
        cin >> arr[i];
    }

    cout << "Maximum element is: " << findMax(arr, size) << endl;
    return 0;
}
