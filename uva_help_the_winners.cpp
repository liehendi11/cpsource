#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

long long dp[17][33000][4];
int pairing[17][17];
int n;
int npow;
int finish;

void reset()
{
	memset(dp, -1, sizeof(dp));
	memset(pairing, 0, sizeof(pairing));
	npow = pow(2, n);
	finish = 0;
}

long long compute(int idx, int state, int status)
{
	if (idx == n)
	{
		if ((status == 1) || (status == 2)) return 1;
		else
			return 0;
	}

	if (dp[idx][state][status] == -1)
	{
		long long res = 0;

		for (int i=0; i<n; i++)
		{
			if (state & (1<<i))
			{
				int masked = state - (1<<i);
				if (pairing[idx][i] == 0)
				{
					if (status == 2) res += compute(idx+1, masked, 2);
					else
						res += compute(idx+1, masked, 0);
				}
				else
					if (pairing[idx][i] == 2) res += compute(idx+1, masked, 2);
				else
					res += compute(idx+1, masked, status);
			}
		}

		dp[idx][state][status] = res;
	}

	return dp[idx][state][status];
}

int main()
{
	int tc;
	scanf("%d", &tc);
	for (int z=1; z<=tc; z++)
	{
		scanf("%d", &n);
		reset();

		for (int i=0; i<n; i++)
		{
			for (int j=0; j<n; j++)
			{
				scanf("%d", &pairing[i][j]);
			}
		}

		long long res = compute(0, npow-1, 1);
		printf("Case %d: %lld\n", z, res);

	}
	return 0;
}