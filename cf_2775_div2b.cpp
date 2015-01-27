#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
#include <string.h>

using namespace std;

int dp[102][102];
vector<int> boys, girls;
int n,m;

int search(int x, int y)
{
	if ((x==n) || (y==m)) return 0;
	if (dp[x][y] !=-1) return dp[x][y];
	else
	{
		int res=0;

		if (abs(boys[x]-girls[y]) <=1) res = max(res, 1+search(x+1,y+1));
		res = max(res, search(x+1,y));
		res = max(res, search(x,y+1));

		dp[x][y] = res;
		return res;
	}
}

int main()
{
	scanf("%d", &n);

	int temp;
	for (int i=0; i<n; i++)
	{
		scanf("%d", &temp);
		boys.push_back(temp);
	}

	scanf("%d", &m);
	for (int i=0; i<m; i++)
	{
		scanf("%d", &temp);
		girls.push_back(temp);
	}	

	sort(boys.begin(), boys.end());
	sort(girls.begin(), girls.end());
	memset(dp, -1, sizeof(dp));

	printf("%d\n", search(0,0));
	return 0;
}