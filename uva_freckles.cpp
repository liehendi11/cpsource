#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

struct Node
{
	float x,y;
};

struct Edge
{
	int node1, node2;
	float weight;
};

int parents[102];
vector<Edge> edges;
vector<Node> nodes;

int find(int x)
{
	if (x==parents[x]) return x;
	else
	{
		parents[x] = find(parents[x]);
		return parents[x];
	}
}

bool f(Edge e1, Edge e2)
{
	return e1.weight < e2.weight;
}

bool uniteSet(int x, int y)
{
	int parentX = find(x);
	int parentY = find(y);

	if (parentX != parentY)
	{
		parents[parentX] = parentY;
		return true;
	}
	else
		return false;
}

float kruskal()
{
	sort(edges.begin(), edges.end(), f);

	float cost = 0;
	for (int i=0; i<edges.size(); i++)
	{
		if (uniteSet(edges[i].node1, edges[i].node2))
			cost+=edges[i].weight;
	}

	return cost;
}



void initialize()
{
	for (int i=0; i<nodes.size(); i++)
	{
		for (int j=i+1; j<nodes.size(); j++)
		{
			Edge newEdge;
			newEdge.node1 = i;
			newEdge.node2 = j;
			newEdge.weight = sqrt( pow(abs(nodes[i].x - nodes[j].x), 2) + pow(abs(nodes[i].y - nodes[j].y), 2));
			edges.push_back(newEdge);
		}
	}
}

void reset()
{
	for (int i=0; i<102; i++)
	{
		parents[i] = i;
	}

	nodes.clear();
	edges.clear();
}

int main()
{
	int tc;
	scanf("%d", &tc);

	for (int z=1; z<=tc; z++)
	{
		int n;
		scanf("%d", &n);
		reset();

		float coorX, coorY;
		for (int i=0; i<n; i++)
		{
			cin >> coorX >> coorY;
			Node newNode;
			newNode.x = coorX;
			newNode.y = coorY;
			nodes.push_back(newNode);
		}

		initialize();

		printf("%.2lf\n", kruskal());
		if (z<tc) printf("\n");
		//cout <<setprecision(2) << kruskal() << endl;
	}
	return 0;
}