#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 1000000;
int lp[maxn + 1];
vector <int> pr;

void init()
{
	for (int i = 2; i <= maxn; ++i)
	{
		if (lp[i] == 0)
		{
			pr.push_back(i);
			lp[i] = i;
		}
		for (int j = 0; j < pr.size() && pr[j] <= lp[i] && i * pr[j] <= maxn; ++j)
			lp[i * pr[j]] = pr[j];
	}
}

int cons_primes(int a, int b)
{
	int counter = 0;
	for (int n = 0;; ++n)
	{
		int temp = n * 1ll * n + a * 1ll * n + b;
		if (temp < 0)
			return counter;
		if (!binary_search(pr.begin(), pr.end(), temp))
			return counter;
		++counter;
	}
}

int main()

{
	init();
	int res = 0, mul = 1;
	for (int a = -999; a < 1000; ++a)
	for (int b = -999; b < 1000; ++b)
	{
		int temp = cons_primes(a, pr[b]);
		if (res < temp)
		{
			mul = a * b;
			res = temp;
		}
	}
	cout << mul;
}