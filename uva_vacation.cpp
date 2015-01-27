#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int dp[102][102];
string x,y;

void reset()
{
	memset(dp, -1, sizeof(dp));
}

int compute(int idx1, int idx2)
{
	if (idx1 == x.length()) return 0;
	if (idx2 == y.length()) return 0;

	if (dp[idx1][idx2] == -1)
	{
		int res = 0;

		res = max(compute(idx1+1, idx2), compute(idx1, idx2+1));
		if (x[idx1] == y[idx2]) res = max(res, compute(idx1+1, idx2+1) + 1);

		dp[idx1][idx2] = res;
	}

	return dp[idx1][idx2];
}

int computeLCS(string a, string b)
{
	int x[1002];
	int y[1002];

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

		for (int p=max(a.length(), b.length()); p>=0; p--) y[p] = x[p];
	}

	return y[0];
}

int main()
{
	int z=1;
	while (true)
	{
		getline(cin, x);
		if (x=="#") break;

		getline(cin, y);

		// reset();

		printf("Case #%d: you can visit at most %d cities.\n", z, computeLCS(0,0));
		z+=1;
	}
	return 0;
}