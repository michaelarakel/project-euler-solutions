#include <iostream>
#include <cmath>
using namespace std;

const int EPS = 1e-10;

int main()
{
	for (int a = 1; a < 1000; ++a)
	for (int b = 1; b < 1000; ++b)
	{
		int temp = a * a + b * b;
		int c = sqrt(temp) + EPS;
		if (c * c == temp)
		{
			if (a + b + c == 1000)
			{
				cout << a * b * c;
				return 0;
			}
		}
	}
}