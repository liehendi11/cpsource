#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

struct Request
{
public:
	int idx, size, money;
	Request(int, int, int);
};

Request::Request(int x, int s, int m)
{
	idx = x;
	size = s;
	money = m;
}

struct Table
{
public:
	int idx, size;
	Table(int, int);
};

Table::Table(int x, int s)
{
	idx = x;
	size = s;
}

int dp[1002][1002];
pair<int, int> path[1002][1002];
pair<int, int> used[1002][1002];
vector<Request> requests;
vector<Table> tables;
vector<pair<int, int> > results;
int n,k;

void reset()
{
	memset(dp, -1, sizeof(dp));
	
	for (int i=0; i<1002; i++)
	{
		for (int j=0; j<1002; j++)
		{
			path[i][j].first = -1; path[i][j].second = -1;
			used[i][j].first = -1; used[i][j].second = -1;
		}
	}

	requests.clear();
	tables.clear();
	results.clear();
}

int compute(int curRequest, int curTable)
{
	if (curRequest == requests.size()) return 0;
	if (curTable == tables.size()) return 0;

	if (dp[curRequest][curTable] == -1)
	{
		int res = -1;
		if (requests[curRequest].size <= tables[curTable].size)
		{
			int temp1 = compute(curRequest+1, curTable+1) + requests[curRequest].money;
			if (temp1 > res)
			{
				res = temp1;
				path[curRequest][curTable].first = curRequest+1; path[curRequest][curTable].second = curTable+1;
				used[curRequest][curTable].first = requests[curRequest].idx; used[curRequest][curTable].second = tables[curTable].idx;
			}
		}

		int temp2 = compute(curRequest+1, curTable);
		if (temp2 > res)
		{
			res = temp2;
			path[curRequest][curTable].first = curRequest+1;
			path[curRequest][curTable].second = curTable;
			used[curRequest][curTable].first = -1;
			used[curRequest][curTable].second = -1;
		}

		int temp3 = compute(curRequest, curTable+1);
		if (temp3 > res)
		{
			res = temp3;
			path[curRequest][curTable].first = curRequest;
			path[curRequest][curTable].second = curTable+1;
			used[curRequest][curTable].first = -1;
			used[curRequest][curTable].second = -1;
		}

		dp[curRequest][curTable] = res;
	}

	return dp[curRequest][curTable];
}

bool f(Request a, Request b)
{
	if (a.size < b.size) return true;
	if ((a.size == b.size) && (a.money > b.money)) return true;
	return false;
}

bool f2(Table a, Table b)
{
	if (a.size < b.size) return true;
	return false;
}

void traverse(int x, int y)
{
	if ((x == n) || (y==k)) return;
	if (!((used[x][y].first == -1) && (used[x][y].second == -1)))
	{
		results.push_back(pair<int, int> (used[x][y].first, used[x][y].second));
	}

	traverse(path[x][y].first, path[x][y].second);
}

int main()
{
	reset();

	scanf("%d", &n);
	int a,b;
	for (int i=0; i<n; i++)
	{
		scanf("%d%d", &a, &b);
		Request newReq(i+1,a,b);
		requests.push_back(newReq);
	}

	sort(requests.begin(), requests.end(), f);

	scanf("%d", &k);
	for (int j=0; j<k; j++)
	{
		scanf("%d", &a);
		Table newTab(j+1, a);
		tables.push_back(newTab);
	}

	sort(tables.begin(), tables.end(), f2);

	int res = compute(0,0);
	traverse(0,0);
	printf("%d %d\n", (int) results.size(), res);
	for (int i=0; i<results.size(); i++)
	{
		printf("%d %d\n", results[i].first, results[i].second);
	}
	return 0;
}