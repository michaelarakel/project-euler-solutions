#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	long long num = 600851475143ll;

	long long max_fact = 0;

	for (int i = 2; i * 1ll * i <= num; ++i)
	{
		if (num % i == 0)
		{
			max_fact = max(i * 1ll, max_fact);
			while (num % i == 0)
				num /= i;
		}
	}

	if (num > 1)
		max_fact = max(max_fact, num);

	cout << max_fact;
}