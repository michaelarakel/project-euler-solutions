#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	vector <long long> triangle_num;
	for (int i = 1; i <= 1000; ++i)
		triangle_num.push_back((i * 1ll * (i + 1)) >> 1);
	ifstream in("words.txt");
	int counter = 0;
	string s;
	while (in >> s)
	{
		int sum = 0;
		for (int i = 0; i < s.size(); ++i)
			sum += s[i] - 'A' + 1;
		if (binary_search(triangle_num.begin(), triangle_num.end(), sum))
			++counter;
	}
	cout << counter;
}