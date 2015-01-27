#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<int> value1,value2;
vector<string> os1,os2;
pair<long long, int> dp[1002][1002];
int n,m;

void reset()
{
	pair<long long, int> res;
	res.first = -1;
	res.second = 0;
	for (int i=0; i<1002; i++)
	{
		for (int j=0; j<1002; j++)
		{
			dp[i][j] = res;
		}
	}

	os1.clear();
	value1.clear();
	os2.clear();
	value2.clear();
}

pair<long long, int> findMax(pair<long long, int> a, pair<long long, int> b)
{
	if (a.first > b.first) return a;
	if ((a.first == b.first) && (a.second < b.second)) return a;
	return b;
}

pair<long long, int> find(int xa,int xb)
{
	if (xa == value1.size()) return pair<long long, int> (0,0);
	if (xb == value2.size()) return pair<long long, int> (0,0);

	if (dp[xa][xb].first ==-1)
	{
		pair<long long, int> res;
		res.first = 0;
		res.second = 0;

		if (os1[xa] == os2[xb])
		{
			pair<long long, int> temp = find(xa+1, xb+1);
			temp.first += (value1[xa]+value2[xb]);
			temp.second += 1;

			res = findMax(res, temp);
		}

		res = findMax(res, find(xa+1, xb));
		res = findMax(res, find(xa, xb+1));
		dp[xa][xb] = res;
	}

	//printf("%d %s %d %s: %lld %d\n", xa, os1[xa].c_str(), xb, os2[xb].c_str(),dp[xa][xb].first, dp[xa][xb].second);
	return dp[xa][xb];
}

int main()
{
	int tc;
	scanf("%d", &tc);
	for (int z=1; z<=tc; z++)
	{
		reset();

		string name, os;
		int val;
		scanf("%d", &n);
		for (int i=0; i<n; i++)
		{
			cin >> name >> os >> val;
			os1.push_back(os);
			value1.push_back(val);
		}


		scanf("%d", &m);
		for (int i=0; i<m; i++)
		{
			cin >> name >> os >> val;
			os2.push_back(os);
			value2.push_back(val);
		}

		pair<long long, int> res = find(0,0);
		printf("%lld %d\n", res.first, res.second);
	}
	return 0;
}