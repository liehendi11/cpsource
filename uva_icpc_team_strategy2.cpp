#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int dp[14][282][5][5][5];
int n;
int problems[4][15];

void reset()
{
	memset(dp, -1, sizeof(dp));
	memset(problems, 0, sizeof(problems));
}

int findResult(int idx, int totalTime, int a, int b, int c)
{
	if (idx==n)
	{
		int dv=(a+b+c+1)/2;
		if ((a <= dv) && (b<=dv) && (c<=dv)) return 0;
		else
			return -1000;
	}

	if (dp[idx][totalTime][a][b][c] ==-1)
	{
		int res=0;

		if ((a+1 <= ((n+1)/2)) && (totalTime+problems[1][idx] <= 280))
			res = max(res, findResult(idx+1, totalTime+problems[1][idx], a+1, b, c)+1);
		if ((b+1 <= ((n+1)/2)) && (totalTime+problems[2][idx] <= 280))
			res = max(res, findResult(idx+1, totalTime+problems[2][idx], a, b+1, c)+1);
		if ((c+1 <= ((n+1)/2)) && (totalTime+problems[3][idx] <= 280))
			res = max(res, findResult(idx+1, totalTime+problems[3][idx], a, b, c+1)+1);

		res = max(res, findResult(idx+1, totalTime,a,b,c));

		dp[idx][totalTime][a][b][c] = res;
		//printf("%d %d %d %d %d: %d\n", idx, totalTime, a,b,c, res);
	}

	return dp[idx][totalTime][a][b][c];
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

		printf("%d\n", findResult(0,0,0,0,0));
	}
	return 0;
}