#include <iostream>
#include <vector>
#include <fstream>
#include "C:/Users/1/Documents/Visual Studio 2013/Projects/BigInt/BigInt.h"

using namespace std;

int main()
{
	ifstream in("Problem 13.txt");
	BigInt b[100];
	for (int i = 0; i < 100; ++i)
		in >> b[i];
	BigInt a = b[0];
	for (int i = 1; i < 100; ++i)
		a += b[i];
	cout << a;
}