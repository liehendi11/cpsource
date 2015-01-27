#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

class Edge
{
public:
	int dest, route;
	Edge(int adest, int aroute)
	{
		dest = adest;
		route = aroute;
	}
};

#define INF 100000002LL

vector<Edge> adj[10002];
int cost[502];
int a,b,n;
int minCost = INF;

void traverse(int x, int firstRoute, int secondRoute)
{
	if (x == b)
	{
		minCost = min(minCost, cost[firstRoute]+cost[secondRoute]);
	}
	else
	{
		for (int i=0; i<adj[x].size(); i++)
		{
			if (firstRoute == 0) traverse(adj[x][i].dest, adj[x][i].route, secondRoute);
			else
			if (secondRoute == 0)
			{
				if (adj[x][i].route != firstRoute) traverse(adj[x][i].dest, firstRoute, adj[x][i].route);
				else
					traverse(adj[x][i].dest, firstRoute, secondRoute);
			}
			else
			{
				if (adj[x][i].route == secondRoute) traverse(adj[x][i].dest, firstRoute, secondRoute);
			}
		}
	}
}

void OPEN(string inputFile, string outputFile) {
	freopen(inputFile.c_str(), "r", stdin);
	freopen(outputFile.c_str(), "w", stdout);
}

int main()
{
	OPEN("cowroute.in", "cowroute.out");
	scanf("%d%d%d", &a, &b, &n);
	cost[0] = 0;

	int routeCost, city;
	for (int i=1; i<=n; i++)
	{
		scanf("%d%d", &routeCost, &city);
		cost[i] = routeCost;

		int prev;
		int dest;
		scanf("%d", &prev);
		for (int j=1; j<city; j++)
		{
			scanf("%d", &dest);
			adj[prev].push_back(Edge(dest, i));
			prev = dest;
		}
	}

	traverse(a, 0, 0);

	if (minCost == INF) printf("-1\n");
	else
		printf("%d\n", minCost);
	return 0;
}