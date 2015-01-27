#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>

using namespace std;

#define INF 1000000000LL

int dp[103][103];
int e,t,n,m;

void reset()
{
	for (int i=0; i<103; i++)
	{
		for (int j=0; j<103; j++)
		{
			if (i==j) dp[i][j] = 0;
			else
				dp[i][j] = INF;
		}
	}
}

void OPEN(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void floyd_warshall()
{
	for (int k=1; k<=n; k++)
	{
		for (int i=1; i<=n; i++)
		{
			for (int j=1; j<=n; j++)
			{
				dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
			}
		}
	}

	int ctr=0;
	for (int i=1; i<=n; i++)
	{
		if ((dp[i][e] <= t)) ctr+=1;
	}

	printf("%d\n", ctr);
}

void printMatrix()
{
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			if (!(dp[i][j] < INF)) printf("X ");
			else
				printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	//OPEN("mice_maze");
	int tc;
	scanf("%d", &tc);
	for (int z=1; z<=tc; z++)
	{
		scanf("%d%d%d%d", &n, &e, &t, &m);

		reset();
		int a,b,c;
		for (int i=0; i<m; i++)
		{
			scanf("%d%d%d", &a, &b, &c);
			dp[a][b] = c;
		}

		floyd_warshall();

		//printMatrix();

		if (z<tc) printf("\n");
	}
}