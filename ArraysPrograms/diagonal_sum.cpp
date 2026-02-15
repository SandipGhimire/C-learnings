#include <iostream>
using namespace std;

int main() {
    int matrix[3][3], sum = 0;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            cout << "Enter element at [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }

    for (int i = 0; i < 3; i++)
        sum += matrix[i][i];

    cout << "Sum of primary diagonal: " << sum << endl;

    return 0;
}
