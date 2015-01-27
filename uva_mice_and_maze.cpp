#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

#define INF 200000009LL

struct Edge
{
	int node;
	int weight;
};

struct Node
{
	int index, cost;
};

class comparison
{
public:
	bool operator() (const Node& left, const Node& right)
	{
		return left.cost > right.cost;
	}
};

vector<Edge> adj[102];
int cost[102][102];
int source, dest, starter;

void dijkstra()
{
	int total=0;
	for (int x=1; x<=source; x++)
	{
		priority_queue <Node, vector<Node>, comparison> pq;

		//memset(cost, INF, sizeof(cost));
		Node first;
		first.index = x;
		first.cost = 0;
		cost[x][x] = 0;
		pq.push(first);
		bool destReached = false;

		while (!destReached)
		{
			Node cur = pq.top();
			pq.pop();

			cost[x][cur.index] = -1;
			if (cur.index == dest)
			{
				destReached = true;
				if (cur.cost <= starter) total+=1;
			}
			else
			{
				for (int i=0; i<adj[cur.index].size(); i++)
				{
					Edge curEdge = adj[cur.index][i];

					if (cost[x][curEdge.node] > cur.cost + curEdge.weight)
					{
						Node newNode = cur;
						newNode.index = curEdge.node;
						newNode.cost += curEdge.weight;
						pq.push(newNode);

						cost[x][curEdge.node] = newNode.cost;
					}
				}
			}
		}
	}

	printf("%d\n", total);
}

void reset()
{
	memset(cost, INF, sizeof(cost));
	for (int i=0; i<102; i++) adj[i].clear();
}

int main()
{
	int tc;
	scanf("%d", &tc);
	for (int z=1; z<=tc; z++)
	{
		scanf("%d%d%d", &source, &dest, &starter);
		reset();

		int m,a,b,c;
		scanf("%d", &m);
		for (int i=0; i<m; i++)
		{
			scanf("%d%d%d", &a, &b, &c);
			Edge newEdge;
			newEdge.node = b;
			newEdge.weight = c;
			adj[a].push_back(newEdge);
		}

		dijkstra();
		if (z<tc) printf("\n");
	}

	return 0;
}