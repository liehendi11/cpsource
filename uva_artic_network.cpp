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

struct Node
{
	float x, y;
};

int parents[502];
int rank[502];
//bool removed[502];
vector<Edge> edges;
vector<Node> nodes;
int s,p;
float res;


int find(int x)
{
	if (x==parents[x]) return x;
	else
	{
		parents[x] = find(parents[x]);
		return parents[x];
	}
}

bool unite(int x, int y)
{
	int parentX = find(x);
	int parentY = find(y);

	if (parentX == parentY) return false;

	if (rank[parentX] < rank[parentY]) parents[parentX] = parentY;
	else
		if (rank[parentX] > rank[parentY]) parents[parentY] = parentX;
		else
			{
				parents[parentX] = parentY;
				rank[parentY] +=1;
			}
	return true;
}

void reset()
{
	for (int i=0; i<502; i++)
	{
		parents[i] = i;
		rank[i]=0;
		//removed[i]=false;
	}
	edges.clear();
	nodes.clear();
}

void generateEdges()
{
	for (int i=0; i<p; i++)
	{
		for (int j=i+1; j<p; j++)
		{
			Edge newEdge;
			newEdge.node1 = i;
			newEdge.node2 = j;
			float dist1 = pow(abs(nodes[i].x-nodes[j].x), 2);
			float dist2 = pow(abs(nodes[i].y-nodes[j].y), 2);
			newEdge.weight = sqrt(dist1+dist2);

			edges.push_back(newEdge);
		}
	}
}

bool f(Edge e1, Edge e2)
{
	return (e1.weight < e2.weight);
}

void kruskal()
{
	sort(edges.begin(), edges.end(), f);

	int components = p;

	Edge lastEdge;
	for (int i=0; i<edges.size(); i++)
	{
		Edge curEdge = edges[i];
		if (unite(curEdge.node1, curEdge.node2))
		{
			components-=1;
			//printf("%d %d %.2f\n", curEdge.node1, curEdge.node2, curEdge.weight);
			if (components == s)
			{
				lastEdge = curEdge;
				break;
			}
		}
	}

	printf("%.2f\n", lastEdge.weight);
}

int main()
{
	int tc;
	scanf("%d", &tc);
	for (int z=1; z<=tc; z++)
	{
		scanf("%d%d", &s, &p);
		reset();
		float a,b;
		for (int i=0; i<p; i++)
		{
			scanf("%f%f", &a, &b);
			Node newNode;
			newNode.x = a;
			newNode.y = b;
			nodes.push_back(newNode);
		}

		generateEdges();
		kruskal();
	}
	return 0;
}