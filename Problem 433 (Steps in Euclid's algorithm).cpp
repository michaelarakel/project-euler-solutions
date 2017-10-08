#include <iostream>
#include <vector>

using namespace std;

const int maxn = 5 * 1000000;

int euclid_steps(int a, int b)
{
	if (b == 0)
		return 0;
	return 1 + euclid_steps(b, a % b);
}