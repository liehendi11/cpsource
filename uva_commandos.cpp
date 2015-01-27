#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 1000002

int dp[102][102];
int source, dest, cost;

void reset()
{
	for (int i=0; i<102; i++)
	{
		for (int j=0; j<102; j++)
		{
			if (i!=j) dp[i][j]= INF;
			else
				dp[i][j]=0;
		}
	}
}

void floyd_warshall()
{
	for (int k=0; k<100; k++)
	{
		for (int i=0; i<100; i++)
		{
			for (int j=0; j<100; j++)
			{
				dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
			}
		}
	}

	cost = dp[source][dest];
	for (int i=0; i<100; i++)
	{
		if ((dp[source][i] < INF) && (dp[i][dest] < INF) && (i!=source) && (i!= dest))
		{
			cost = max(cost, dp[source][i]+dp[i][dest]);
		}
	}
}

int main()
{
	int tc,n,m;
	scanf("%d", &tc);

	for (int z=1; z<=tc; z++)
	{
		scanf("%d", &n);
		scanf("%d", &m);

		reset();

		int a,b;
		for (int i=0; i<m; i++)
		{
			scanf("%d%d", &a, &b);
			dp[a][b] = 1;
			dp[b][a] = 1;
		}
		scanf("%d%d", &source, &dest);

		floyd_warshall();

		printf("Case %d: %d\n", z, cost);
	}
	return 0;
}