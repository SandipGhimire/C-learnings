#include <iostream>
using namespace std;

int main() {
    int a[2][2], b[2][2], sum[2][2];

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

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            sum[i][j] = a[i][j] + b[i][j];

    cout << "Sum of matrices:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            cout << sum[i][j] << " ";
        cout << endl;
    }

    return 0;
}
