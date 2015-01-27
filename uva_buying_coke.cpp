#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

#define INF 1000000009LL

int dp[152][202][102];
int n, sum;

void reset()
{
	memset(dp, -1, sizeof(dp));
	sum=0;
}

int compute(int coke, int five, int ten)
{
	if (coke == n) return 0;

	if (dp[coke][five][ten] == -1)
	{
		int res = INF;

		int one = sum - (coke*8) - (five*5) - (10*ten);

		//one ten
		if (ten > 0) res = min(res, compute(coke+1, five, ten-1) + 1);
		//two five
		if (five >=2) res = min(res, compute(coke+1, five-2, ten) + 2);
		//five and three
		if ((five >=1) && (one >= 3)) res = min(res, compute(coke+1, five-1, ten) + 4);
		//eight ones
		if (one >= 8) res = min(res, compute(coke+1, five, ten) + 8);
		//thirteen
		if ((ten >=1) && (one >= 3)) res = min(res, compute(coke+1, five+1, ten-1) + 4);

		dp[coke][five][ten] = res;
	}

	return dp[coke][five][ten];
}

int main()
{
	int tc;
	scanf("%d", &tc);
	for (int z=1; z<=tc; z++)
	{
		scanf("%d", &n);
		reset();

		int a,b,c;
		scanf("%d%d%d", &a, &b, &c);
		sum = (c*10) + (b*5) + a;

		int res = compute(0, b,c);		
		printf("%d\n", res);
	}
	return 0;
}