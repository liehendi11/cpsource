#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <map>
#include <string>

using namespace std;

#define INF 2147483640LL

vector<pair<int, int> > turtles;
map<pair<int, int>, int> dp;

void OPEN(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int compute(int idx, int limit)
{
	if (idx == turtles.size()) return 0;

	pair<int, int> state = pair<int, int> (idx, limit);

	if (dp.count(state) ==0)
	{
		int res = 0;

		if ((limit >= turtles[idx].first) && (turtles[idx].second >= turtles[idx].first))
		{
			res = max(res, compute(idx+1, min(limit-turtles[idx].first, turtles[idx].second-turtles[idx].first)) +1);
		}

		res = max(res, compute(idx+1, limit));

		dp.insert(pair<pair<int, int>, int> (state, res));
	}

	return dp[state];
}

int main()
{
	// OPEN("turtles");
	turtles.clear();

	int a,b;
	while (scanf("%d%d", &a, &b) != EOF) turtles.push_back(pair<int, int> (a,b));

	dp.clear();
	printf("%d\n", compute(0, INF));
	return 0;
}