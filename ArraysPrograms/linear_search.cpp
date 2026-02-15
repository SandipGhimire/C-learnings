#include <iostream>
using namespace std;

int main() {
    int n, key;
    cout << "Enter Array lenght: "; 
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter a number: ";
        cin >> arr[i];
    }

    cout << "Enter a key number: ";
    cin >> key;

    int index = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            index = i;
            break;
        }
    }

    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
