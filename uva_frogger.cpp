#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Edge
{
	int node1, node2;
	float weight;
};

vector<pair<float, float> > nodes;
int parents[202];
vector<Edge> edges;

void reset()
{
	for (int i=0; i<202; i++) parents[i] = i;

	nodes.clear();
	edges.clear();
}

int find(int x)
{
	if (x!=parents[x]) parents[x] = find(parents[x]);
	return parents[x];
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
	return false;
}

bool f(Edge e1, Edge e2)
{
	return e1.weight < e2.weight;
}

void kruskal()
{
	float mx=0;
	sort(edges.begin(), edges.end(), f);

	for (int i=0; i<edges.size(); i++)
	{
		if (uniteSet(edges[i].node1, edges[i].node2)) mx = max(edges[i].weight, mx);
	}

	printf("Frog Distance = %.3f\n", mx);
}

int main()
{
	int n=-1;
	int z=0;

	while (n!=0)
	{
		scanf("%d", &n);
		if (n==0) break;
		z+=1;
		reset();

		float a,b;
		for (int i=0; i<n; i++)
		{
			scanf("%f%f", &a, &b);
			nodes.push_back(pair<float, float> (a,b));
		}

		for (int i=0; i<n; i++)
		{
			for (int j=i+1; j<n; j++)
			{
				float dist = sqrt(pow(abs(nodes[i].first-nodes[j].first), 2) + pow(abs(nodes[j].second-nodes[i].second),2));
				Edge newEdge;
				newEdge.node1 = i;
				newEdge.node2 = j;
				newEdge.weight = dist;
				edges.push_back(newEdge);
			}
		}

		printf("Scenario #%d\n", z);
		kruskal();
		printf("\n");
	}
	//while (n!=0)
	return 0;
}