#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<pair<int, int>> items;
int dp[102][10202];
int n,m;

void reset()
{
	for (int i=0; i<102; i++)
	{
		for (int j=0; j<10202; j++)
		{
			dp[i][j] = -1;
		}
	}

	items.clear();
}

int findResult(int idx, int sum)
{
	if (idx==items.size())
	{
		int ret=0;
		
		if (sum <= n) ret = 0;
		else
			if ((sum <= n+200) && (sum > 2000)) ret=0;
			else
			ret = -2000;
		
		//printf("%d %d %d\n", idx, sum, ret);

		return ret;
	}

	if (dp[idx][sum] == -1)
	{
		int res = -2000;

		if ((sum + items[idx].first) <= (n+200))
		{
			int temp = findResult(idx+1, sum+items[idx].first) + items[idx].second;
			//printf("hasil sum %d %d %d\n", idx, sum, temp);
			res = max(res, temp);
		}

		res = max(res, findResult(idx+1, sum));

		//printf("%d %d %d\n", idx, sum, res);

		dp[idx][sum] = res;
	}

	return dp[idx][sum];
}

int main()
{
	while (scanf("%d%d", &n, &m) != EOF)
	{
		reset();
		// if (n>=2000) n+= 200;
		pair<int, int> in;
		for (int i=0; i<m; i++)
		{
			scanf("%d%d", &in.first, &in.second);
			items.push_back(in);
		}

		int res = findResult(0,0);

		printf("%d\n", res);
	}
	return 0;
}