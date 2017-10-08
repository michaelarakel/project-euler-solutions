#include <iostream>
#include <vector>

using namespace std;

const int base = 999999017;
const long long n = 99999999019;

long long gcd(long long a, long long b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main()
{

}