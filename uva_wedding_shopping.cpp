#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[22][202];
int money, n;
vector<int> cost[22];

int findResult(int idx, int usedBudget)
{
	if (idx==n) return usedBudget;

	if (dp[idx][usedBudget] == -1)
	{
		int res = -10000;
		for (int i=0; i<cost[idx].size(); i++)
		{
			if (usedBudget + cost[idx][i] <= money)
			{
				res = max(res, findResult(idx+1, usedBudget+cost[idx][i]));
			}
		}

		dp[idx][usedBudget] = res;
	}

	return dp[idx][usedBudget];
}

void reset()
{
	for (int i=0; i<22; i++)
	{
		cost[i].clear();
		for (int j=0; j<202; j++)
		{
			dp[i][j] = -1;
		}
	}
}

int main()
{
	int tc;
	scanf("%d", &tc);

	for (int z=1; z<=tc; z++)
	{
		scanf("%d%d", &money, &n);
		reset();

		for (int i=0; i<n; i++)
		{
			int x,y;
			scanf("%d", &x);
			for (int j=0; j<x; j++)
			{
				scanf("%d", &y);
				cost[i].push_back(y);
			}
		}

		int res = findResult(0,0);

		if (res < 0) printf("no solution\n");
		else
			printf("%d\n", res);
	}
	return 0;
}