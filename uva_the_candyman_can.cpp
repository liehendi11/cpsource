#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int dp[34][642][642];
vector<int> weights;
int n, sum;

void reset()
{
	memset(dp, -1, sizeof(dp));
	weights.clear();
	sum=0;
}

int compute(int idx, int first, int second)
{
	if (dp[idx][first][second] == -1)
	{
		if (idx==weights.size())
		{
			int remaining = sum-first-second;
			int mx = max(first, max(second, remaining));
			int mn  = min(first, min(second, remaining));

			dp[idx][first][second] = mx-mn;
		}	
		else
		{
			int res = min(compute(idx+1, first+weights[idx], second), min(compute(idx+1, first, second+weights[idx]), compute(idx+1, first, second)));
			dp[idx][first][second] = res;
		}
	}
	
	return dp[idx][first][second];

}

int main()
{
	int tc;
	scanf("%d", &tc);
	for (int z=1; z<=tc; z++)
	{
		scanf("%d", &n);
		reset();

		int x;

		for (int i=0; i<n; i++)
		{
			scanf("%d", &x);
			weights.push_back(x);
			sum+=x;
		}

		int res = compute(0, 0, 0);

		printf("Case %d: %d\n", z, res);
	}
	return 0;
}