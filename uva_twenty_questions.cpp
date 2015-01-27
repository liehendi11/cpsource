#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int dp[30][6][7780];
int n, sum;

void reset()
{
	memset(dp, -1, sizeof(dp));
	sum=0;
}

int getQty(int state, int x)
{
	return (state / (int) pow(10,x)) % 10;
}

int compute(int idx, int prev, int state)
{
	if (idx==sum) return 1;

	if (dp[idx][prev][state] ==-1)
	{
		int res=0;
		for (int i=0; i<4; i++)
		{
			if (i!=prev)
			{
				for (int j=1; j<=min(3, getQty(state, i)); j++)
				{
					res += compute(idx+j, i, state - (j* (int)pow(10, i)));
				}
			}
		}

		dp[idx][prev][state] = res;

	}

	return dp[idx][prev][state];
}

int main()
{
	int tc;
	scanf("%d", &tc);
	for (int z=1; z<=tc; z++)
	{
		scanf("%d", &n);
		reset();

		int init=0;
		int x;
		for (int i=0; i<n; i++)
		{
			scanf("%d", &x);
			sum+=x;
			init += (x*pow(10, i));
		}

		printf("%d\n", compute(0, -1, init));
	}
	return 0;
}