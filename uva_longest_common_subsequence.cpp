#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

void computeLCS(string a, string b)
{
	int x[2002];
	int y[2002];

	memset(x, 0, sizeof(x));
	memset(y, 0, sizeof(y));

	for (int i=a.length(); i>=0; i--)
	{
		for (int j=b.length(); j>=0; j--)
		{
			if ((i==a.length()) || (j==b.length())) x[j] = 0;
			else
			if (a[i] == b[j]) x[j] = 1+y[j+1];
			else
			x[j] = max(y[j], x[j+1]);
		}

		for (int p=2001; p>=0; p--) y[p] = x[p];
	}

	printf("%d\n", y[0]);
}

void OPEN(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main()
{
	string s1, s2;
	// OPEN("lcs");
	while (!cin.eof())
	{
		getline(cin, s1);
		getline(cin, s2);

		computeLCS(s1,s2);
	}
	return 0;
}