#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <cstring>

using namespace std;

bool adjColor[62][62];
int colorCount[62];
int color[62];
int n,m;
vector<int> adj[62];
int maxColor;
int maxColorSet;

int findSmallestColor(int ix)
{
	for (int i=0; i<n; i++)
	{
		if (!adjColor[ix][i]) return i;
	}
}

void goColor(int ix)
{
	int nodeColor = findSmallestColor(ix);
	colorCount[nodeColor]+=1;
	color[ix] = nodeColor;

	if (nodeColor+1 > maxColor) maxColor=nodeColor+1;
	if (colorCount[nodeColor] > maxColorSet) maxColorSet=colorCount[nodeColor];

	for (int i=0; i<adj[ix].size(); i++)
	{
		adjColor[adj[ix][i]][nodeColor] = true;
	}

	for (int i=0; i<adj[ix].size(); i++)
	{
		if (color[adj[ix][i]] ==-1) goColor(adj[ix][i]);
	}
}

void reset()
{
	memset(adjColor, false, sizeof(adjColor));
	memset(color, -1, sizeof(color));
	memset(colorCount, 0, sizeof(colorCount));
	for (int i=0; i<62; i++) adj[i].clear();

	maxColorSet=0;
	maxColor=0;
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int z=1; z<=t; z++)
	{
		reset();
		scanf("%d%d", &n,&m);

		int a,b;
		for (int i=0; i<m; i++)
		{
			scanf("%d%d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		for (int i=0; i<n; i++)
		{
			if (color[i] ==-1) goColor(i);
		}

		for (int i=0; i<n; i++)
		{
			printf("%d ", color[i]);
		}
		printf("\n");

		
		printf("%d\n", maxColor);
		printf("%d\n", maxColorSet);
	}
	return 0;
}