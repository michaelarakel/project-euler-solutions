#include <iostream>
#include <vector>

using namespace std;

const int bound = 4 * 1000 * 1000;

int main()
{
	vector <int> fib;
	fib.push_back(1);
	fib.push_back(2);
	unsigned long long ans = 2;
	while (fib[fib.size() - 1] <= bound)
	{
		fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
		if (!(fib.back() & 1))
			ans += fib.back();
	}
	cout << ans;
}