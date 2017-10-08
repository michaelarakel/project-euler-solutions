#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int base = 1000 * 1000 * 1000;

void print(const vector <int>& a)
{
	cout << a.back();
	for (int i = (int)a.size() - 2; i >= 0; --i)
		printf("%09d", a[i]);
}

void sum(vector <int>& a, vector <int>& b)
{
	int carry = 0;
	for (int i = 0; i < max(a.size(), b.size()) || carry; ++i)
	{
		if (i == a.size())
			a.push_back(0);
		long long curr = a[i] + carry;
		if (i < b.size())
			curr += b[i];
		carry = (curr >= base);
		if (carry)
			curr -= base;
		a[i] = curr;
	}
	while (a.back() == 0)
		a.pop_back();
}

int main()
{
	vector <int> first(1, 1), second(1, 1);
	int counter = 2;
	while (second.size() * 9 < 1000)
	{
		sum(first, second);
		swap(first, second);
		++counter;
	}
	cout << counter;
}