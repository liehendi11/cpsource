#include <stdio.h>
#include <stdlib.h>

using namespace std;

int dp[102][102];
int k,n;

int findResult(int idx, int tempSum)
{
	if ((idx== k) && (tempSum == n)) return 1;
	else
		if (idx==k) return 0;
	
	if (dp[idx][tempSum] == -1)
	{
		int res=0;
		for (int i=0; i<=(n-tempSum); i++)
		{
			res += (findResult(idx+1, tempSum+i));
			res = res % 1000000;
		}

		dp[idx][tempSum] = res;
	}

	return dp[idx][tempSum];
}

void reset()
{
	for (int i=0; i<102; i++)
	{
		for (int j=0; j<102; j++)
		{
			dp[i][j] = -1;
		}
	}
}

int main()
{
	n=-1; k=-1;
	while (true)
	{
		scanf("%d%d", &n, &k);
		if ((n==0) && (k==0)) break;

		reset();

		printf("%d\n", findResult(0,0));
	}
	return 0;
}