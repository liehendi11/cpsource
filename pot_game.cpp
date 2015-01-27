#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <cstring>

using namespace std;

vector<int> dpSum;
vector<int> num;
int dp[100][100];
int n;

void createDpSum()
{
	int sum = 0;
	for (int i=0; i<num.size(); i++)
	{
		sum += num[i];
		dpSum.push_back(sum);
	}
}

int findSum(int a, int b)
{
	int left = 0;
	if (a > 0) left = dpSum[a-1];

	return dpSum[b]-left;
}

int compute(int x, int y)
{
	if (x==y) return num[x];

	if (dp[x][y] == -1)
	{
		dp[x][y] = max(num[x] + findSum(x+1, y) - compute(x+1,y), num[y] + findSum(x, y-1) - compute(x, y-1));
	}

	return dp[x][y];
}

int main()
{
	scanf("%d", &n);

	int x;
	for (int i=0; i<n; i++)
	{
		scanf("%d", &x);
		num.push_back(x);
	}

	createDpSum();
	memset(dp, -1, sizeof(dp));

	printf("%d\n", compute(0, n-1));
	return 0;
}