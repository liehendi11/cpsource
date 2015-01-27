#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

#define INF 2000000009LL

struct Edge
{
	int node, weight;
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

vector<Edge> edges[102];
vector<int> floors[6];
int elevatorCost[6];
int cost[102];
int dest,n;

void reset()
{
	for (int i=0; i<102; i++) edges[i].clear();
	for (int i=0; i<6; i++)
	{
		floors[i].clear();
		elevatorCost[i] = 0;
	}

	memset(cost, INF, sizeof(cost));
}

void dijkstra()
{
	priority_queue<Node, vector<Node>, comparison> pq;
	
	Node first;
	first.index = 0;
	first.cost = -60;
	pq.push(first);
	// for (int i=0; i<edges[0].size(); i++)
	// {
			
	// }
	
	bool arrived=false;

	while ((!arrived) && (!pq.empty()))
	{
		Node cur = pq.top();
		pq.pop();

		//printf("%d %d\n", cur.index, cur.cost);

		cost[cur.index] = -1;

		if (cur.index ==dest)
		{
			arrived=true;
			if (cur.index ==0) cur.cost+=60;
			printf("%d\n", cur.cost);
		}
		else
		{
			cur.cost+=60;
			for (int i=0; i<edges[cur.index].size(); i++)
			{
				Edge curEdge = edges[cur.index][i];
				if (cost[curEdge.node] > cur.cost + curEdge.weight)
				{
					Node newNode = cur;
					newNode.index = curEdge.node;
					newNode.cost += curEdge.weight;
					pq.push(newNode);

					cost[newNode.index] = newNode.cost;
				}
			}
		}
	}

	if (!arrived)
	{
		printf("IMPOSSIBLE\n");
	}
}

void OPEN(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "wb", stdout);
}

int main()
{
	//OPEN("lift_hopping");7
	while (scanf("%d%d", &n, &dest) != EOF)
	{
		reset();
		for (int i=0; i<n; i++) scanf("%d", &elevatorCost[i]);

		string s;
		for (int i=0; i<n; i++)
		{
			char dum=0;
			int temp;

			while (!((dum=='\n') || (dum==EOF)))
			{
				scanf("%d", &temp);
				floors[i].push_back(temp);

				if (scanf("%c", &dum) == EOF) break;
				//dum = getchar();
			}
		}

		for (int i=0; i<n; i++)
		{
			int z=floors[i].size();

			//printf("%d\n", z);
			for (int j=0; j<z; j++)
			{
				for (int k=j+1; k<z; k++)
				{
					Edge newEdge1,newEdge2;

					newEdge1.node = floors[i][j];
					newEdge1.weight = elevatorCost[i] * abs(floors[i][j]-floors[i][k]);
					edges[floors[i][k]].push_back(newEdge1);

					//printf("%d %d %d\n", floors[i][k], floors[i][j], newEdge1.weight);

					newEdge2.node = floors[i][k];
					newEdge2.weight = newEdge1.weight;
					edges[floors[i][j]].push_back(newEdge2);
					//printf("%d %d %d\n", floors[i][j], floors[i][k], newEdge2.weight);

					//printf("lalal %d %d %d", i,j,k);
				}
			}
		}

		//cout << "lala" << endl;
		dijkstra();
	}
	return 0;
}