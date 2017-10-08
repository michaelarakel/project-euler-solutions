#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1000000;
int lp[maxn + 1];
vector <int> prime;

void init()
{
	for (int i = 2; i <= maxn; ++i)
	{
		if (lp[i] == 0)
		{
			lp[i] = i;
			prime.push_back(i);
		}
		for (int j = 0; j < prime.size() && prime[j] <= lp[i] && i * 1ll * prime[j] <= maxn; ++j)
			lp[i * prime[j]] = prime[j];
	}
}

int main()
{
	init();
	cout << prime[10000];
}