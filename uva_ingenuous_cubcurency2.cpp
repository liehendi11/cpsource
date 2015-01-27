#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

long long dp[23][10002];
vector<int> coins;

void init()
{
	coins.clear();
	for (int i=1; i<=21; i++)
	{
		int num = pow(i, 3);
		coins.push_back(num);
	}

	memset(dp, -1, sizeof(dp));
}

long long findResult(int idx, int sum)
{
	if (sum<=0) return 0;
	if (idx==0) return 1;

	if (dp[idx][sum] == -1)
	{
		long long res = 0;
		res += findResult(idx-1, sum);
		res += findResult(idx, sum-coins[idx]);

		dp[idx][sum] = res;
	}

	return dp[idx][sum];
}

int main()
{
	init();
	//findResult(20, 10000);
	printf("%lld\n", findResult(20,21));
	return 0;
}