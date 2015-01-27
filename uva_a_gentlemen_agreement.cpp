#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<pair<int, string>, int> dp;
vector<int> adj[3602];

int find(int x, string state)
{
	if (dp.count(pair<int, string> (x,state)) >0) return dp[pair<int, string> (x,state)];

	if (state[x] == 'U')
	{
		int res = 0;
		//if intersection x is true
		string newState1 = state;
		newState1[x] = 'Y';
		for (int i=0; i<adj[x].size(); i++) newState1[adj[x][i]] = 'N';

		for (int i=0; i<adj[x].size(); i++) res = max(res, find(adj[x][i], newState1)+1);

		//if intersection x is false
		string newState2 = state;
		newState2[x] = 'N';
		for (int i=0; i<adj[x].size(); i++)
		{
			res = max(res, find(adj[x][i], newState2));
		}

		dp.insert(pair< pair<int, string>, int > (pair<int, string> (x, state) , res));
		return res;
	}
	else
	{
		int res=0;
		for (int i=0; i<adj[x].size(); i++)
		{
			if (state[adj[x][i]] == 'U')
			{
				res = max(res, find(adj[x][i], state));
			}
		}

		dp.insert(pair< pair<int, string>, int > (pair<int, string> (x, state) , res));
		return res;
	}

}

void reset()
{
	dp.clear();
	for (int i=0; i<3602; i++) adj[i].clear();	
}

int main()
{
	int tc;
	scanf("%d", &tc);

	for (int z=1; z<=tc; z++)
	{
		int n,m;
		scanf("%d%d", &n, &m);

		reset();

		int a,b;
		for (int i=0; i<m; i++)
		{
			scanf("%d%d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		string initState="";
		for (int i=0; i<n; i++) initState+='U';

		printf("%d\n", find(0, initState));
	}
	return 0;
}