#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> seq;
int answer = 1;
int max_num;

void count_polatz(size_t n)
{
	if (n == 27)
	{
		n = 27;
	}
	int counter = 0;
	while (true)
	{
		if (n < seq.size())
		{
			counter += seq[n];
			if (answer < counter)
			{
				answer = counter;
				max_num = seq.size();
			}
			seq.push_back(counter);
			return;
		}
		++counter;
		if (n & 1)
			n = 3 * n + 1;
		else
			n /= 2;
	}
}

int main()
{
	seq.push_back(0);
	seq.push_back(1);
	for (size_t i = 2; i <= 1000000; ++i)
		count_polatz(i);
	cout << answer << endl << max_num << endl;
}