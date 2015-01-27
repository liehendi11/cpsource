#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int coins[8];
int values[] = {5,10,20,50,100,200};
int change;

int dp[8][502];

void reset()
{
	memset(dp, -1, sizeof(dp));
	// memset(coins, 0, sizeof(coins));
}

int greedyCoinCount(int x)
{
	int ret = 0;
	int idx = 5;
	while (idx >=0)
	{
		while (x >= values[idx])
		{
			x-=values[idx];
			ret +=1;
		}

		idx-=1;
	}

	return ret;
}

int findResult(int idx, int sum)
{
	//printf("%d %d\n", idx, sum);
	if (sum== change) return 0;
	if (idx == 6) return 100000;

	if (dp[idx][sum] == -1)
	{
		int res = 10000;
		for (int i=0; i<=coins[idx]; i++)
		{
			if (sum + (i*values[idx]) <= change)
				res = min(res, findResult(idx+1, sum+(i*values[idx])) + i);
			else
			{
				int excess = abs((sum+(i*values[idx])) - change);

				res = min(res, findResult(idx+1, change) + i + greedyCoinCount(excess));
			}
		}

		dp[idx][sum] = res;

	}

	return dp[idx][sum];
}



int main()
{
	while (true)
	{
		scanf("%d%d%d%d%d%d", &coins[0], &coins[1], &coins[2], &coins[3], &coins[4], &coins[5]);
		if ((coins[0] == 0) && (coins[1] == 0) && (coins[2] == 0) && (coins[3] == 0) && (coins[4] == 0) && (coins[5] == 0)) break;
		float in;
		scanf("%f", &in);
		change =  floor(in*100);
		
		reset();

		int x = findResult(0,0);
		if (x < 10) printf("  ");
		else
		if (x < 100) printf(" ");
		printf("%d\n", x);
	}
	return 0;
}