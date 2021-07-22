#include <iostream>
using namespace std;

int main()
{
    const int rows = 3, cols = 3;
    int a[rows][cols];
    int k, t;

    cout << "The array:" << endl;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            a[i][j] = rand() % 10;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << a[i][j] << "   ";
        cout << endl;
    }
    cout << "Enter number of array shifts: ";
    cin >> k;
    for (int i = 0; i < k; i++) {
        t = a[0][0];
        for (int j = 0; j < rows; j++) {
            for (int g = 0; g < cols-1; g++) 
                a[j][g] = a[j][g + 1];
            if (j < rows - 1)
                a[j][cols - 1] = a[j + 1][0];
            else a[j][cols - 1] = t;
        }
    }
    cout << endl << "Inversed array: " << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << a[i][j] << "   ";
        cout << endl;
    }

    return 0;
}