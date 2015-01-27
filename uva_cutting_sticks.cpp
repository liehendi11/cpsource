#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

#define INF 100000

vector<int> cuts;
int dp[55][55];
int l,n;

int lowerBound(int x)
{
	int mn = 0;
	int mx = cuts.size()-1;
	int temp=-1;

	while (mn <= mx)
	{
		int mid = (mn+mx)/2;

		if (cuts[mid] > x)
		{
			temp = mid;
			mx = mid-1;
		}
		else
			mn  = mid+1;
	}

	return temp;
}

int upperBound(int x)
{
	int mn = 0;
	int mx = cuts.size()-1;
	int temp=-1;

	while (mn <= mx)
	{
		int mid = (mn+mx)/2;

		if (cuts[mid] < x)
		{
			temp = mid;
			mn = mid+1;
		}
		else
			mx  = mid-1;
	}

	return temp;
}

void reset()
{
	memset(dp, -1, sizeof(dp));
	cuts.clear();
}

int compute(int start, int end)
{
	// printf("%d %d\n", start, end);
	if (end-start <= 1) return 0;

	if (dp[start][end] == -1)
	{
		int res = INF;

		for (int i=start+1; i<end; i++)
		{
			res = min(res, compute(start, i) + compute(i, end) + (cuts[end]-cuts[start]));
		}

		dp[start][end] = res;
	}

	return dp[start][end];
}

int main()
{
	l=-1;
	while (l!=0)
	{
		scanf("%d", &l);
		if (l==0) break;

		reset();

		cuts.push_back(0);
		scanf("%d", &n);
		int x;
		for (int i=0; i<n; i++)
		{
			scanf("%d", &x);
			cuts.push_back(x);
		}
		cuts.push_back(l);

		sort(cuts.begin(), cuts.end());

		printf("The minimum cutting is %d.\n", compute(0, cuts.size()-1));
	}
	return 0;
}