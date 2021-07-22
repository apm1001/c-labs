#include <iostream>
using namespace std;
int main()
{
	const int n = 3;
	int a[n] = { 1,2,3 }, b[n] = { 4,5,6 }, c[n];
	int* p;

	for (int i = 0, p = *a; i < n; i++) {
		c[i] = (p + i) + b[i];
		cout << c[i] << " ";
	}
}