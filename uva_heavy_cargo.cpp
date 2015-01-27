#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Edge
{
	int node1, node2, weight;
};

vector<Edge> edges;
vector<Edge> citiesEdges[202];
int parents[202];
int ranks[202];

void reset()
{
	for (int i=0; i<202; i++)
	{
		parents[i] = i;
		ranks[i] = 0;
		citiesEdges[i].clear();
	}
	edges.clear();
}

void 

int main()
{
	return 0;
}