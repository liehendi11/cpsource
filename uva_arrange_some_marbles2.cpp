#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int sum;
int dp[30][5][4][780];
int first, firstSize;
int colours[5];

void reset()
{
	memset(dp, -1, sizeof(dp));
	memset(colours, 0, sizeof(colours));
	sum=0;
}

int getQty(int state, int x)
{
	return (state / (int) pow(10,x)) % 10;
}

long long compute(int idx, int prev, int prevSize, int state)
{
	if (idx == sum)
	{
		printf("%d %d / %d %d / %d / %d\n", prev, prevSize, first, firstSize, state, (((prev != first) && (prevSize != firstSize)) ? 1 : 0));
		if ((prev != first) && (prevSize != firstSize)) return 1;
		else
			return 0;
	}

	if (dp[idx][prev][prevSize][state] == -1)
	{
		long long res = 0;

		int used = 0;
		for (int i=0; i<n-1; i++) used += (colours[i] - getQty(state, i));
		int last = (colours[n-1] - (idx-used));

		for (int i=0; i<n-1; i++)
		{
			if (prev != i)
			{
				for (int j=1; j<=min(3, getQty(state, i)); j++)
				{
					if (j!= prevSize)
					res += compute(idx+j, i, j, state - (pow(10, i) * j));
				}	
			}
		}

		if (prev != n-1)
		{
			for (int j=1; j<=min(3, last); j++)
			{
				if (j!= prevSize)
				res += compute(idx+j, n-1, j, state);
			}
		}

		// printf("%d %d %d %d last %d = %lld\nfirst = %d firstSize = %d\n", idx, prev, prevSize, state, last, res, first, firstSize);

		dp[idx][prev][prevSize][state] = res;
	}

	return dp[idx][prev][prevSize][state];
}

void startComputing(int state)
{
	long long res = 0;
	for (int i=0; i<n-1; i++)
	{
		for (int j=1; j<=min(3, colours[i]); j++)
		{
			// memset(dp, -1, sizeof(dp));
			first = i;
			firstSize = j;
			res += compute(j, i, j, state - (pow(10, i) * j));
		}
	}

	first = n-1;
	for (int j=1; j<= min(3, colours[n-1]); j++)
	{
		// memset(dp, -1, sizeof(dp));
		firstSize = j;
		res += compute(j, n-1, j, state);
	}

	printf("%lld\n", res);
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
			colours[i] = x;

			if (i<(n-1)) init += (x* (int) pow(10, i));
		}

		startComputing(init);
	}
	return 0;
}