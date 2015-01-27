#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Edge
{
	int x,y;
	int weight;
};

int parents[200002];
vector<Edge> edges;
int n,m;

bool f(Edge e1, Edge e2)
{
	return (e1.weight < e2.weight);
}

int find(int x)
{
	if (x==parents[x]) return x;
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

void reset()
{
	for (int i=0; i<=n; i++)
	{
		parents[i]=i;
	}
	edges.clear();
}

long long kruskal()
{
	int x=0;
	sort(edges.begin(), edges.end(), f);

	long long totalCost=0;
	while (x < edges.size())
	{
		int a = edges[x].x;
		int b = edges[x].y;

		if (uniteSet(a,b)) totalCost+=edges[x].weight;

		x+=1;
	}

	return totalCost;
}

int main()
{
	n=-1;
	m=-1;

	while (!((n==0) && (m==0)))
	{
		scanf("%d%d", &n, &m);
		if ((n==0) && (m==0)) break;
		reset();

		int a,b,c;
		long long sum=0;
		for (int i=0; i<m; i++)
		{
			scanf("%d%d%d", &a, &b, &c);
			Edge newEdge;
			newEdge.x = a;
			newEdge.y = b;
			newEdge.weight = c;
			edges.push_back(newEdge);

			sum+=c;
		}

		cout << sum-kruskal() << endl;
	}

	return 0;
}