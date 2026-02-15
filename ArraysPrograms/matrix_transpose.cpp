#include <iostream>
using namespace std;

int main() {
    int matrix[2][3], transpose[3][2];

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++) {
            cout << "Enter element at [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            transpose[j][i] = matrix[i][j];

    cout << "Transpose of the matrix:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++)
            cout << transpose[i][j] << " ";
        cout << endl;
    }

    return 0;
}
