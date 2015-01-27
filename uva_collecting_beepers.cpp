#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

#define INF 10000

vector<pair<int, int> > coords;
int adj[13][13];
int dp[12][2050];
int n, npow;

void init()
{
	memset(adj, 0, sizeof(adj));
	memset(dp, -1, sizeof(dp));

	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			if (i!=j)
			{
				adj[i][j] = abs(coords[i].first - coords[j].first) + abs(coords[i].second - coords[j].second);
			}
		}
	}

}

int compute(int start, int state)
{
	if (state==0) return adj[start][0];
	if (dp[start][state] != -1) return dp[start][state];

	int res = INF;

	for (int i=0; i<n; i++)
	{
		int mask = (npow-1) - (1<<i);
		int masked = state & mask;
		if (masked != state)
		{
			int temp = adj[start][i] + compute(i, masked);
			if (temp < res)
			{
				res = temp;
			}
		}
	}

	return dp[start][state]=res;
}

void TSP()
{
	init();

	npow = pow(2,n);
	int res = compute(0, npow-2);
	printf("The shortest path has length %d\n", res);
}

int main()
{
	int tc;
	scanf("%d", &tc);
	while (tc>0)
	{
		int dumx,dumy;
		coords.clear();

		scanf("%d%d", &dumx, &dumy);
		scanf("%d%d", &dumx, &dumy);
		coords.push_back(pair<int, int> (dumx, dumy));

		scanf("%d", &n);
		for (int i=0; i<n; i++)
		{
			scanf("%d%d", &dumx, &dumy);
			coords.push_back(pair<int, int> (dumx, dumy));			
		}

		n+=1;

		TSP();
		tc--;
	}
	return 0;
}