#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;

#define INF 1000000009LL

int dp[102][52][22502];
vector<int> weights;
int n,sum;

void reset()
{
	memset(dp, -1, sizeof(dp));
	weights.clear();
	sum=0;
}

int compute(int idx, int tempCount, int tempSum)
{
	// printf("%d %d %d\n", idx, tempCount, tempSum);
	if (tempCount == (n/2))
	{
		return tempSum;
		// int other = sum-tempSum;
		// return abs(other-tempSum);
	}
	if (idx == n) return INF;

	if (dp[idx][tempCount][tempSum] == -1)
	{
		int res = INF;
		int diff = abs(res - (sum-res));

		if (tempCount < (n/2))
		{
			int temp = compute(idx+1, tempCount+1, tempSum+weights[idx]);
			int tempDiff = abs(temp-(sum-temp));

			if (tempDiff < diff)
			{
				diff = tempDiff;
				res = temp;
			}
		}

		int temp = compute(idx+1, tempCount, tempSum);
		int tempDiff = abs(temp-(sum-temp));

		if (tempDiff < diff)
		{
			diff = tempDiff;
			res = temp;
		}

		dp[idx][tempCount][tempSum] = res;
	}
	return dp[idx][tempCount][tempSum];
}

int main()
{
	int tc;
	scanf("%d", &tc);
	for (int z=1; z<=tc; z++)
	{
		scanf("%d", &n);
		reset();

		int x;
		for (int i=0; i<n; i++)
		{
			scanf("%d", &x);
			weights.push_back(x);
			sum+=x;
		}

		int first = compute(0,0,0);
		int second = abs(sum-first);

		if (z>1) printf("\n");

		if (first > second) printf("%d %d\n", second, first);
		else
			printf("%d %d\n", first, second);

	}
	return 0;
}