#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 10000
#define EPS 1e-9

int dp[42][302][302];
int target;
int n;
vector<pair<int, int> > coins;

void reset()
{
	memset(dp, -1, sizeof(dp));
	coins.clear();
}

double eModulus(int x, int y)
{
	return sqrt(pow(x,2) + pow(y,2));
}

int findResult(int idx, int conv, int eval)
{
	if (idx == coins.size())
	{
		if (abs(target-eModulus(conv, eval)) < EPS) return 0;
		else
			return INF;
	}

	if (dp[idx][conv][eval] ==-1)
	{
		int res = INF;
		int k=0;

		while (eModulus(conv+(k*coins[idx].first) , eval+(k*coins[idx].second)) <= target)
		{
			res = min(res, findResult(idx+1, conv+(k*coins[idx].first), eval+(k*coins[idx].second)) + k);
			k+=1;
		}

		dp[idx][conv][eval] = res;
	}

	return dp[idx][conv][eval];
}



int main()
{
	int tc;
	scanf("%d", &tc);

	for (int z=1; z<=tc; z++)
	{
		scanf("%d%d", &n, &target);

		reset();

		int a,b;
		for (int i=0; i<n; i++)
		{
			scanf("%d%d", &a, &b);
			coins.push_back(pair<int, int> (a,b));
		}

		int res = findResult(0,0,0);

		if (res < INF)
		{
			printf("%d\n", res);
		}
		else
			printf("not possible\n");
	}
	return 0;
}