#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

int dp[102][50002];
int coins[102];
int tc,n;
int sum;

void reset()
{
	for (int i=0; i<102; i++)
	{
		for (int j=0; j<50002; j++)
		{
			dp[i][j] = -1;
		}
	}
}

int find(int x, int tempSum)
{
	if (dp[x][tempSum] == -1)
	{
		if (x==n) dp[x][tempSum] = abs((tempSum*2) - sum);
		else
			dp[x][tempSum] = min(find(x+1, tempSum), find(x+1, tempSum+coins[x]));
	}
	return dp[x][tempSum];
}

int main()
{
	scanf("%d", &tc);

	for (int z=0; z<tc; z++)
	{
		scanf("%d", &n);
		sum=0;
		for (int i=0; i<n; i++)
		{
			scanf("%d", &coins[i]);
			sum+=coins[i];
		}

		reset();

		printf("%d\n", find(0, 0));
	}
	return 0;
}