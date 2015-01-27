#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

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

int cityParents[1002];
int cityStates[1002];
int stateParents[1002];
int n;
double r;
int stateCount;

vector<Edge> stateEdges[1002];
vector<Edge> countryEdges;
vector<Node> nodes;
bool kruskalMode;

int findState(int x)
{
	if (stateParents[x] == x) return x;
	else
	{
		stateParents[x] = findState(stateParents[x]);
		return stateParents[x];
	}
}

int findCity(int x)
{
	if (x==cityParents[x]) return x;
	else
	{
		cityParents[x] = findCity(cityParents[x]);
		cityStates[x] = cityStates[cityParents[x]];

		return cityParents[x];
	}
}

bool uniteCity(int x, int y)
{
	int parentX = findCity(x);
	int parentY = findCity(y);

	if (parentX != parentY)
	{
		cityParents[parentX] = parentY;
		if (kruskalMode) cityStates[parentX] = cityStates[parentY];
		return true;
	}
	return false;
}

bool uniteState(int x, int y)
{
	int parentX = findState(x);
	int parentY = findState(y);

	if (parentX != parentY)
	{
		stateParents[parentX] = parentY;
		return true;
	}
	return false;
}

bool f(Edge e1, Edge e2)
{
	return e1.weight < e2.weight;
}

float getDistance(float x1, float y1, float x2, float y2)
{
	return sqrt( pow(abs(x1-x2), 2) + pow(abs(y1-y2), 2));
}

void resetCityParents()
{
	for (int i=0; i<1002; i++) cityParents[i] = i;
}

double kruskalState(int stateIdx)
{
	sort(stateEdges[stateIdx].begin(), stateEdges[stateIdx].end(), f);

	double sum=0;
	for (int i=0; i<stateEdges[stateIdx].size(); i++)
	{
		Edge curEdge = stateEdges[stateIdx][i];
		if (uniteCity(curEdge.node1, curEdge.node2)) sum+=curEdge.weight;
	}
	return sum;
}

double kruskalCountry()
{
	sort(countryEdges.begin(), countryEdges.end(), f);

	double sum=0;
	for (int i=0; i<countryEdges.size(); i++)
	{
		Edge curEdge = countryEdges[i];
		if (uniteState(curEdge.node1, curEdge.node2)) sum+=curEdge.weight;
	}
	return sum;
}

void generateStates()
{
	kruskalMode=false;
	for (int i=0; i<n; i++)
	{
		for (int j=i+1; j<n; j++)
		{
			if (getDistance(nodes[i].x, nodes[i].y, nodes[j].x, nodes[j].y) <= r) uniteCity(i,j);
		}
	}

	for (int i=0; i<n; i++)
	{
		findCity(i); //path compression
		if (cityParents[i] == i) stateCount+=1;
	}

	//for (int i=0; i<n; i++) printf("City %d, parent %d, state %d\n", i,cityParents[i], cityStates[i]); //path compression	

	for (int i=0; i<n; i++)
	{
		for (int j=i+1; j<n; j++)
		{
			int state1 = cityStates[i];
			int state2 = cityStates[j];
			if (state1 == state2)
			{
				//create edges
				Edge newEdge;
				newEdge.node1 = i;
				newEdge.node2 = j;
				newEdge.weight = getDistance(nodes[i].x, nodes[i].y, nodes[j].x, nodes[j].y);
				//printf("State %d edge: from %d to %d weight %.0f\n", state1, newEdge.node1, newEdge.node2, newEdge.weight);
				stateEdges[state1].push_back(newEdge);
			}
			else
			{
				//create country edges
				Edge newEdge;
				newEdge.node1 = state1;
				newEdge.node2 = state2;
				newEdge.weight = getDistance(nodes[i].x, nodes[i].y, nodes[j].x, nodes[j].y);
				//printf("Country edge: from %d to %d weight %.0f\n", newEdge.node1, newEdge.node2, newEdge.weight);
				countryEdges.push_back(newEdge);
			}
		}
	}

	kruskalMode=true;
	resetCityParents();
}

void reset()
{
	for (int i=0; i<1002; i++)
	{
		cityParents[i] = i;
		cityStates[i] = i;
		stateParents[i] = i;	
		stateEdges[i].clear();
	}
	countryEdges.clear();
	nodes.clear();
}

int main()
{
	int tc;
	scanf("%d", &tc);

	for (int z=1; z<=tc; z++)
	{
		reset();

		scanf("%d%lf", &n, &r);

		float x1,y1;
		for (int i=0; i<n; i++)
		{
			Node newNode;
			scanf("%f%f", &x1, &y1);

			newNode.x = x1;
			newNode.y = y1;
			nodes.push_back(newNode);
		}

		stateCount = 0;
		generateStates();

		double res = 0;
		double resCountry = kruskalCountry();
		
		for (int i=0; i<n; i++)
		{
			if (stateEdges[i].size()>0)
			{
				double temp = kruskalState(i);
				res += temp;
			}
		}

		printf("Case #%d: %d %.0f %.0f\n", z, stateCount, round(res), round(resCountry));
	}

	return 0;
}