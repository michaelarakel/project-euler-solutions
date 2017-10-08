#include <iostream>
#include <vector>

using namespace std;

const int maxn = 100000000;
int lp[maxn + 1];
vector <int> pr;

inline void init()
{
	for (int i = 2; i <= maxn; ++i)
	{
		if (lp[i] == 0)
		{
			pr.push_back(i);
			lp[i] = i;
		}
		for (int j = 0; j < pr.size() && pr[j] <= lp[i] && i * 1ll * pr[j] <= maxn; ++j)
			lp[i * pr[j]] = pr[j];
	}
}

int num_of_div(int n)
{
	if (n == 1)
		return 1;
	int res = 1;
	while (n > 1)
	{
		int temp = lp[n];
		int counter = 1;
		while (temp == lp[n])
		{
			++counter;
			n /= lp[n];
		}
		res *= counter;
	}
	return res;
}

int main()
{
	init();
	int triang_num = 1;
	for (int i = 2;; ++i)
	{
		triang_num += i;
		if (num_of_div(triang_num) >= 500)
		{
			cout << triang_num << endl;
			return 0;
		}
	}
}