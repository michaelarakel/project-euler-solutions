#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

bool is_palindrom(int n)
{
	ostringstream oss;
	oss << n;
	string s(oss.str());

	for (int i = 0; i < s.size() / 2 + 1; ++i)
	{
		if (s[i] != s[s.size() - i - 1])
			return false;
	}
	return true;
}

int main()
{
	int ans = 0;
	for (int i = 100; i < 999; ++i)
	for (int j = i; j < 1000; ++j)
	{
		if (is_palindrom(i * j))
			ans = max(ans, i * j);
	}
	cout << ans;
}