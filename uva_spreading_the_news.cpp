#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Data
{
	int cur, steps;
};

vector<int> adj[2502];
int n,m;
int source;

void bfs()
{
	bool visited[n+2];
	for (int i=0; i<n+2; i++) visited[i]=false;

	Data first;
	first.cur = source;
	first.steps = 0;
	visited[source] = true;

	queue<Data> q;
	q.push(first);

	int mx=0;
	int mxDay = 0;

	int curDay=-1;
	int curDayCount=0;

	while (!q.empty())
	{
		Data cur = q.front();
		q.pop();

		if (cur.steps != curDay)
		{
			curDay=cur.steps;
			curDayCount=1;
		}
		else
			curDayCount+=1;

		if ((mx < curDayCount) && (curDay!=0))
		{
			mx = curDayCount;
			mxDay = curDay;
		}


		for (int i=0; i<adj[cur.cur].size(); i++)
		{
			if (!visited[adj[cur.cur][i]])
			{
				visited[adj[cur.cur][i]] = true;
				Data newData;
				newData.cur = adj[cur.cur][i];
				newData.steps = cur.steps+1;

				q.push(newData);
			}
		}
	}

	if (mxDay==0) printf("0\n");
	else
		printf("%d %d\n", mx, mxDay);
}

void OPEN(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main()
{
	//OPEN("spreading_the_news");
	while (scanf("%d", &n) != EOF)
	{
		//clear adj list
		for (int i=0; i<2502; i++) adj[i].clear();

		for (int i=0; i<n; i++)
		{
			int k,l;
			scanf("%d", &k);

			for (int j=0; j<k; j++)
			{
				scanf("%d", &l);
				adj[i].push_back(l);
				//adj[l].push_back(i);
			}
		}

		scanf("%d", &m);
		for (int i=0; i<m; i++)
		{
			scanf("%d", &source);
			bfs();
		}
	}
	return 0;
}