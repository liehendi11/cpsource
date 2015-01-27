#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define INF 1000

int dp[102][102];

void reset()
{
	//memset(dp, INF, sizeof(dp));
	for (int i=0; i<102; i++)
	{
		for (int j=0; j<102; j++)
		{
			if (i!=j) dp[i][j] = INF;
			else
				dp[i][j]=0;
		}
	}
}

void printMatrix()
{
	for (int i=1; i<=10; i++)
	{
		for (int j=1; j<=10; j++)
		{
			if (dp[i][j] < INF) printf("%d ", dp[i][j]);
			else
				printf("X ");
		}
		printf("\n");
	}
}

void floyd_warshall()
{
	// printMatrix();
	for (int k=1; k<=100; k++)
		for (int i=1; i<=100; i++)
			for (int j=1; j<=100; j++)
				dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);

	long long tempTotal=0;
	int ctr = 0;
	for (int i=1; i<=100; i++)
	{
		for (int j=1; j<=100; j++)
		{
			if ((dp[i][j] < INF) && (i!=j))
			{
				tempTotal += dp[i][j];
				ctr+=1;
			}
		}
	}

	float avg = ((float) tempTotal) / ((float) ctr);

	printf("%.3f clicks\n", avg);

	// printMatrix();
}

int main()
{
	int a,b;
	a=-1;
	b=-1;
	int z;

	while (!((a==0) && (b==0)))
	{
		scanf("%d%d", &a, &b);
		if ((a==0) && (b==0)) break;
		z+=1;
		reset();

		dp[a][b] = 1;

		while (true)
		{
			scanf("%d%d", &a, &b);
			if ((a==0) && (b==0)) break;
			dp[a][b] = 1;
		}

		printf("Case %d: average length between pages = ", z);
		floyd_warshall();
		a=-1;
		b=-1;
	}
	return 0;
}