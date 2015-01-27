#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> coins;
long long dp[23][10002];



void init()
{
	coins.clear();
	for (int i=1; i<=21; i++)
	{
		int num = pow(i, 3);
		coins.push_back(num);
	}

	memset(dp, 0, sizeof(dp));
}


void constructDP()
{
	for (int i=0; i<coins.size(); i++)
	{
		for (int j=0; j<=10000; j++)
		{
			if (j==0) dp[i][j] = 0;
			else
			if (i==0) dp[i][j] = 1;
			else
			{
				long long res = dp[i-1][j];
				if (coins[i] <= j) res += dp[i][j-coins[i]];

				dp[i][j] = res;
				// int k=0;
				// while (k * coins[i] <= j)
				// {
				// 	res += dp[i-1][j-(k*coins[i])];
				// 	k+=1;
				// }

				// dp[i][j] = res;
			}
		}
	}
}


int main()
{
	init();
	constructDP();
	printf("%lld\n", dp[coins.size()-1][9999]);
	return 0;
}