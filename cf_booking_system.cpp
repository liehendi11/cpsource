#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int dp[1002][1002];
int path[1002][1002];
pair<int, int> used[1002][1002];
vector<pair<int, int> > requests;
vector<int> tables;
int n,k;

void reset()
{
	memset(dp, -1, sizeof(dp));
	requests.clear();
	tables.clear();
}

int compute(int curRequest, int curTable)
{
	if (curRequest == requests.size()) return 0;
	if (curTable == tables.size()) return 0;

	if (dp[curRequest][curTable] == -1)
	{
		int res = 0;
		if (requests[curRequest].first <= tables[curTable])
		{
			res = max(compute(curRequest+1, curTable+1) + requests[curRequest].second, max(compute(curRequest+1, curTable), compute(curRequest, curTable+1)));
		}
		else
			res = max(compute(curRequest+1, curTable), compute(curRequest, curTable+1));

		dp[curRequest][curTable] = res;
	}

	return dp[curRequest][curTable];
}

bool f(pair<int, int> a, pair<int, int> b)
{
	if (a.first < b.first) return true;
	if ((a.first == b.first) && (a.second > b.second)) return true;
	return false;
}

int main()
{
	reset();

	scanf("%d", &n);
	int a,b;
	for (int i=0; i<n; i++)
	{
		scanf("%d%d", &a, &b);
		requests.push_back(pair<int, int> (a,b));
	}

	sort(requests.begin(), requests.end(), f);

	scanf("%d", &k);
	for (int j=0; j<k; j++)
	{
		scanf("%d", &a);
		tables.push_back(a);
	}

	sort(tables.begin(), tables.end());

	printf("%d\n", compute(0, 0));
	return 0;
}