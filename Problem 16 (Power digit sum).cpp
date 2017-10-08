#include <iostream>
#include <sstream>
#include <string>
#include "C:/Users/1/Documents/Visual Studio 2013/Projects/BigInt/BigInt.h"

using namespace std;

int main()
{
	BigInt a("1");
	for (int i = 0; i < 1000; ++i)
		a *= 2;
	ostringstream oss;
	oss << a;
	string s = oss.str();
	int ans = 0;
	for (int i = 0; i < s.size(); ++i)
		ans += (s[i] - '0');
	cout << ans;
}