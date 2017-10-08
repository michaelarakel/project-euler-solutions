#include <iostream>
#include <vector>
#include <numeric>
#include <sstream>
#include <string>

using namespace std;

const int base = 1000 * 1000 * 1000;

void print(const vector <int>& a)
{
	cout << a.back();
	for (int i = a.size() - 2; i >= 0; --i)
		printf("%09d", a[i]);
}

void mul(vector <int>& a, int b)
{
	int carry = 0;
	for (int i = 0; i < a.size() || carry; ++i)
	{
		if (i == a.size())
			a.push_back(0);
		long long curr = a[i] * 1ll * b + carry;
		a[i] = (int) (curr % base);
		carry = (int) (curr / base);
	}
	while (a.back() == 0)
		a.pop_back();
}

int dig_sum(int n)
{
	ostringstream oss;
	oss << n;
	string s(oss.str());
	int res = 0;
	for (int i = 0; i < s.size(); ++i)
		res += s[i] - '0';
	return res;
}

int main()
{
	vector <int> fact(1, 1);
	for (int i = 2; i <= 100; ++i)
		mul(fact, i);
	print(fact);
	cout << endl;
	int res = 0;
	for (auto it : fact)
	{
		res += dig_sum(it);
	}
	cout << res << endl;
}