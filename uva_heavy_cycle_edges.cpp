#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

struct Edge
{
	int x,y,weight;
};

vector<Edge> edges;
vector<Edge> heavyEdges;
int parents[1002];

int find(int x)
{
	if (parents[x] == x) return x;
	else
	{
		parents[x] = find(parents[x]);
		return parents[x];
	}
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

bool f(Edge e1, Edge e2)
{
	return e1.weight < e2.weight;
}

void reset()
{
	edges.clear();
	heavyEdges.clear();
	for (int i=0; i<1002; i++) parents[i] = i;
}

void kruskal()
{
	sort(edges.begin(), edges.end(), f);

	for (int i=0; i<edges.size(); i++)
	{
		Edge curEdge = edges[i];
		if (!uniteSet(curEdge.x, curEdge.y)) heavyEdges.push_back(curEdge);
	}
}

int main()
{
	int n,m;
	n=-1; m=-1;

	while (!((n==0) && (m==0)))
	{
		scanf("%d%d", &n, &m);
		if ((n==0) && (m==0)) break;

		reset();

		int u,v,w;
		for (int i=0; i<m; i++)
		{
			scanf("%d%d%d", &u,&v,&w);
			Edge newEdge;
			newEdge.x = u;
			newEdge.y = v;
			newEdge.weight = w;
			edges.push_back(newEdge);
		}

		kruskal();

		if (heavyEdges.size() >0)
		{
			for (int i=0; i<heavyEdges.size(); i++)
			{
				printf("%d", heavyEdges[i].weight);
				if (i<heavyEdges.size()-1) printf(" ");
			}
			printf("\n");
		}
		else
			printf("forest\n");

	}
}