#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

vector<int> squares;
int dp[10002];

void init()
{
	memset(dp, -1, sizeof(dp));
	squares.clear();
	for (int i=1; i<=100; i++)
	{
		squares.push_back((int) pow(i,2));
	}
}

int compute(int x)
{
	if (x==0) return 0;

	if (dp[x] == -1)
	{
		int res = 10002;

		for (int i=0; i<squares.size(); i++)
		{
			if (squares[i] <= x)
			{
				res = min(res, compute(x-squares[i])+1);
			}
			else
				break;
		}

		dp[x] = res;
	}

	return dp[x];
}

int main()
{
	init();
	int n=0;
	scanf("%d", &n);
	for (int z=1; z<=n; z++)
	{
		int q;
		scanf("%d", &q);

		printf("%d\n", compute(q));
	}
	return 0;
}