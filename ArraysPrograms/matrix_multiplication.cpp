#include <iostream>
using namespace std;

int main() {
    int a[2][2], b[2][2], result[2][2];

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) {
            cout << "Enter element of first matrix at [" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) {
            cout << "Enter element of second matrix at [" << i << "][" << j << "]: ";
            cin >> b[i][j];
        }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 2; k++)
                result[i][j] += a[i][k] * b[k][j];
        }
    }

    cout << "Resultant matrix:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            cout << result[i][j] << " ";
        cout << endl;
    }

    return 0;
}
