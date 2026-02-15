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

    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}
