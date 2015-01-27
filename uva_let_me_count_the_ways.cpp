#include <stdio.h>
#include <stdlib.h>

using namespace std;

long long dp[7][30002];
int coins[] = {50, 25, 10, 5, 1};

long long findResult(int idx, int sum)
{
	if (idx==4) return 1;

	if (dp[idx][sum] == -1)
	{
		long long res=0;
		int ix=0;

		while (ix*coins[idx] <= sum)
		{
			res += findResult(idx+1, sum-(ix*coins[idx]));
			ix+=1;
		}

		dp[idx][sum] = res;
	}

	return dp[idx][sum];
}

void reset()
{
	for (int i=0; i<30002; i++)
	{
		for (int j=0; j<7; j++)
		{
			dp[j][i] = -1;
		}
	}
}

int main()
{
	reset();
	int n;
	while (scanf("%d", &n) != EOF)
	{
		//fprintf(stderr, "%lld\n", dp[0][17]);
		long long res = findResult(0,n);

		if (res !=1) printf("There are %lld ways to produce %d cents change.\n", res, n);
		else
			printf("There is only 1 way to produce %d cents change.\n", n);
	}	
	return 0;
}