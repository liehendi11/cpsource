#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <algorithm>

using namespace std;

#define OFFSET 300

int gems[30002];
int dp[30002][602];
int n,d;


int compute(int x, int prev)
{
	if (x > 30000) return 0;

	if (dp[x][prev+OFFSET] == -1)
	{
		int res = 0;

		for (int i=-1; i<=1; i++)
		{
			int newOffset = prev + i;
			if (d + newOffset > 0) res = max(res, compute(x+d+newOffset, newOffset));
		}

		dp[x][prev+OFFSET] = res + gems[x];
	}

	return dp[x][prev+OFFSET];
}



int main()
{
	scanf("%d%d", &n, &d);
	memset(gems, 0, sizeof(gems));
	memset(dp, -1, sizeof(dp));

	int a;
	for (int i=0; i<n; i++)
	{
		scanf("%d", &a);
		gems[a] += 1;
	}

	printf("%d\n", compute(d, 0));
	return 0;
}