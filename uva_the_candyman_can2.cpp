#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

typedef pair<int, pair<int, int> > ii;

map<ii, int> dp;
// int dp[34][642][642];
vector<int> weights;
int n, sum;

void reset()
{
	// memset(dp, -1, sizeof(dp));
	dp.clear();
	weights.clear();
	sum=0;
}

int compute(int idx, int first, int second)
{
	ii state;
	state.first = idx;
	state.second.first = first;
	state.second.second = second;
	if (dp.count(state) == 0)
	{
		if (idx==weights.size())
		{
			int remaining = sum-first-second;
			int mx = max(first, max(second, remaining));
			int mn  = min(first, min(second, remaining));

			dp.insert(pair<ii, int> (state, mx-mn));
			// dp[idx][first][second] = mx-mn;
		}	
		else
		{
			int res = min(compute(idx+1, first+weights[idx], second), min(compute(idx+1, first, second+weights[idx]), compute(idx+1, first, second)));
			
			dp.insert(pair<ii, int> (state, res));
			// dp[idx][first][second] = res;
		}
	}
	
	return dp[state];

}

void OPEN(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main()
{
	OPEN("candyman");
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
		fprintf(stderr, "Case %d: %d\n", z, res);
	}
	return 0;
}