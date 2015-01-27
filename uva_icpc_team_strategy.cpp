#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int dp[4098][5][282];
int n;
int problems[4][15];

void reset()
{
	memset(dp, -1, sizeof(dp));
	memset(problems, 0, sizeof(problems));
}

int findResult(int state, int prev, int totalTime)
{
	if (dp[state][prev][totalTime] ==-1)
	{
		int res=0;

		// for (int i=1; i<=3; i++)
		// {
		// 	if ((i!=prev) && (totalTime+problems[i][idx] <= 280))
		// 	{
		// 		res = max(res, findResult(idx+1, i, totalTime+problems[i][idx]) +1);
		// 	}
		// }

		for (int i=0; i<n; i++)
		{
			if (!(state & (1<<i)))
			{
				for (int j=1; j<=3; j++)
				{
					if ((j != prev) && (totalTime+problems[j][i] <= 280))
					{
						int newState = state;
						newState = newState | (1<<i);
						res = max(res, findResult(newState, j, totalTime+problems[j][i])+1);
					}
				}
			}
		}

		//res = max(res, findResult(newState, prev, totalTime));

		dp[state][prev][totalTime] = res;
		//printf("%d %d %d %d\n", idx, prev, totalTime, res);
	}

	return dp[state][prev][totalTime];
}

int main()
{
	int tc;
	scanf("%d", &tc);

	for (int z=1; z<=tc; z++)
	{
		scanf("%d", &n);
		reset();
		for (int i=1; i<=3; i++)
		{
			for (int j=0; j<n; j++)
			{
				scanf("%d", &problems[i][j]);
			}
		}

		printf("%d\n", findResult(0,0,0));
	}
	return 0;
}