#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

#define MOD 1000000007LL

long long dp[102][12][1025];
int n,m;
int npow;

void reset()
{
	memset(dp, -1, sizeof(dp));
}

long long compute(int idx, int prev, int state)
{
	if (idx==m)
	{
		if (state == 0) return 1;
		else
			return 0;
	}

	if (idx==0)
	{
		long long res = 0;
		for (int i=1; i<n; i++)
		{
			res = (res + compute(idx+1, i, (npow-1) - (1<<i))) % MOD;
		}
		return res;
	}

	if (dp[idx][prev][state] == -1)
	{
		long long res = 0;
		if (state == 0) res = 1;

		if (prev > 0)
		{
			int masked = state & ((npow-1) - (1<<(prev-1)));
			res = (res + compute(idx+1, prev-1, masked)) % MOD;
		}


		if (prev < n-1)
		{
			int masked = state & ((npow-1) - (1<<(prev+1)));
			res = (res + compute(idx+1, prev+1, masked)) % MOD;
		}

		// res +=1;

		// printf("%d %d = %lld\n", idx, prev, res);
		dp[idx][prev][state] = res%MOD;
	}

	return dp[idx][prev][state];
}

int main()
{
	int tc;
	scanf("%d", &tc);

	for (int z=1; z<=tc; z++)
	{
		scanf("%d%d", &n, &m);
		reset();

		npow = pow(2, n);

		cout << compute(0,0, npow-1) << endl;
	}
	return 0;
}