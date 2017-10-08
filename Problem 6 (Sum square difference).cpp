#include <iostream>

using namespace std;

int main()
{
	int n = 100;
	cout << n * 1ll * (n + 1) / 2 * ((n * (n + 1)) / 2 - (2 * n + 1) / 3);
}