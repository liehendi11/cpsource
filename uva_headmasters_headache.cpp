#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>

using namespace std;

#define INF 10000002

vector<int> appSkills[102];
int appCost[102];
int dp[66000][102];
int npow;
int s,m,n;
int tempTotal = 0;
int finish;

void reset()
{
	memset(dp, -1, sizeof(dp));

	for (int i=0; i<102; i++)
	{
		appSkills[i].clear();
		appCost[i] = 0;
	}

	npow = pow(2,16);

	finish = npow-1;
	for (int i=0; i<s; i++)
	{
		finish = finish - (1<<i) - (1<< (i+8));
	}
	tempTotal = 0;
}

int compute(int state, int idx)
{
	if (state == finish) return 0;
	if (idx>=n) return INF;

	if (dp[state][idx] == -1)
	{
		int res = INF;

		res = min(res, compute(state, idx+1));
		int newState = state;

		for (int i=0; i<appSkills[idx].size(); i++)
		{
			if (newState & (1<<appSkills[idx][i])) newState = newState & ((npow-1) - (1<<appSkills[idx][i]));
			else
				newState = newState & ((npow-1) - (1<<(appSkills[idx][i]+8)));
		}

		res = min(res, compute(newState, idx+1) + appCost[idx]);

		dp[state][idx] = res;
	}

	return dp[state][idx];
}

void OPEN(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main()
{
	// OPEN("headmaster");
	while (true)
	{
		scanf("%d%d%d", &s, &m, &n);

		if ((s==0) && (m==0) && (n==0)) break;

		reset();

		int initState = npow-1;
		int x,y;
		string in;

		for (int i=0; i<m; i++)
		{
			scanf("%d", &x);
			tempTotal += x;
			getchar();

			getline(cin, in);

			y=0;
			for (int j=0; j<in.length(); j++)
			{
				if (in[j] == ' ')
				{
					y-=1;
					// printf("%d %d\n",i, y);
					if (initState & (1<<y)) initState = initState & ((npow-1) - (1<<y));
					else
						initState = initState & ((npow-1) - (1<<(y+8)));

					y=0;
				}
				else
					y = (y*10) + (in[j]-48);
			}

			y-=1;
			if (initState & (1<<y)) initState = initState & ((npow-1) - (1<<y));
			else
				initState = initState & ((npow-1) - (1<<(y+8)));
		}

		// printf("%d %d\n", initState, tempTotal);

		for (int i=0; i<n; i++)
		{
			scanf("%d", &x);
			appCost[i] = x;
			getchar();

			getline(cin, in);

			y=0;
			for (int j=0; j<in.length(); j++)
			{
				if (in[j] == ' ')
				{
					appSkills[i].push_back(y-1);
					y=0;
				}
				else
					y = (y*10) + (in[j]-48);
			}

			appSkills[i].push_back(y-1);
		}

		printf("%d\n", compute(initState, 0)+tempTotal);

	}
	return 0;
}