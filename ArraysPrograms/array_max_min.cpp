#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter Array lenght: "; 
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter a number: ";
        cin >> arr[i];
    }

    int max = arr[0];
    int min = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }

    cout << "Maximum: " << max << endl;
    cout << "Minimum: " << min << endl;

    return 0;
}
