#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <algorithm>

using namespace std;

#define MOD 1000000007LL

pair<int, short> dp[896][200002];
int ir,ig,sum;

void reset()
{
	pair<int, short> init;
	init.first = -1;
	init.second = 0;
	
	for (int i=0; i<896; i++)
	{
		for (int j=0; j<200002; j++)
		{
			dp[i][j] = init;
		}
	}
}

int used(int idx)
{
	return (idx*(idx+1))/2;
}

pair<int, short> compute(int idx, int red)
{
	int green = ig - (((idx*(idx+1))/2)-(ir-red));

	// printf("%d %d %d\n", idx, red, green);
	if ((idx+1 > green) && (idx+1 > red)) return pair<int, short> (1, idx);

	if (dp[idx][red].first == -1)
	{
		int res = 0;
		short maxHeight = 0;

		if (red >= idx+1)
		{
			pair<int, short> temp = compute(idx+1, red-(idx+1));
			if (temp.second > maxHeight)
			{
				res = temp.first;
				maxHeight = temp.second;
			}
			else
			if (temp.second == maxHeight) res += temp.first;
		}

		res = res % MOD;

		if (green >= idx+1)
		{
			pair<int, short> temp = compute(idx+1, red);
			if (temp.second > maxHeight)
			{
				res = temp.first;
				maxHeight = temp.second;
			}
			else
			if (temp.second == maxHeight) res += temp.first;
		}
		// printf("%d %d %d = %d\n", idx, red, green, res);
		res = res % MOD;

		dp[idx][red] = pair<int, short> (res, maxHeight);
	}

	return dp[idx][red];
}

int main()
{
	reset();
	scanf("%d%d", &ir, &ig);

	sum = ir+ig;

	pair<int, short> res = compute(0,ir);
	printf("%d\n", res.first);
	// printf("%d\n", res.second);

	return 0;
}