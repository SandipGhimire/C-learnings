#include <iostream>
using namespace std;

int main() {
    int matrix[2][3];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Enter value for row " << i << " and column " << j << ": ";
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < 2; i++) {
        int sum = 0;
        for (int j = 0; j < 3; j++) {
            sum += matrix[i][j];
        }
        cout << "Sum of row " << i << ": " << sum << endl;
    }

    return 0;
}
