#include <iostream>
using namespace std;

int main()
{
    int a[] = { 1,2,3,4,5,6,7,8 };
    int n = 8, t, k;

    cout << "Enter the number of displacements in array: ";
    cin >> k;
    k = k % 8;

    for (int i = 0; i < k; i++) {
        t = a[n - 1];
        for (int i = n - 1; i >= 0; i--)
        {
            a[i] = a[i - 1];
        }
        a[0] = t;
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}

