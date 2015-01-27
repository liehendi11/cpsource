#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct BFSData
{
	int v, cost;
};

vector<pair<int, int> > adj[10002];
int cost[10002];
int farVertex, farCost;

void reset()
{
	for (int i=0; i<10002; i++) adj[i].clear();
}

void bfs(int startVertex)
{
	BFSData firstData;
	firstData.v = startVertex;
	firstData.cost = 0;

	queue<BFSData> q;
	q.push(firstData);

	while (!q.empty())
	{
		BFSData cur = q.top();

		
	}
}

int main()
{
	return 0;
}