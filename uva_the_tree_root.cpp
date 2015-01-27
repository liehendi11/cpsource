#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef bool tdata[5002];

vector<int> adj[5002];
int height[5002];

int traverse(int x, int prev)
{
	int temp=0;

	for (int i=0; i<adj[x].size(); i++)
	{
		if (adj[x][i] != prev)
		{
			temp = max(temp, traverse(adj[x][i], x));
		}
	}

	return temp+1;
}

void reset()
{
	memset(height, 0, sizeof(height));
	for (int i=0; i<5002; i++) adj[i].clear();
}

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		reset();

		for (int i=1; i<=n; i++)
		{
			int adjCount,temp;
			scanf("%d", &adjCount);

			for (int j=0; j<adjCount; j++)
			{
				scanf("%d", &temp);
				adj[i].push_back(temp);
			}
		}

		int mn,mx;
		mn = 7000;
		mx=0;
		for (int i=1; i<=n; i++)
		{
			height[i] = traverse(i, 0);

			mn = min(mn, height[i]);
			mx = max(mx, height[i]);
		}

		vector<int> minimumNodes,maximumNodes;
		for (int i=1; i<=n; i++)
		{
			if (height[i] == mn) minimumNodes.push_back(i);
			if (height[i] == mx) maximumNodes.push_back(i);
		}

		printf("Best Roots  :");
		for (int i=0; i<minimumNodes.size(); i++) printf(" %d", minimumNodes[i]);
		printf("\n");

		printf("Worst Roots :");
		for (int i=0; i<maximumNodes.size(); i++) printf(" %d", maximumNodes[i]);
		printf("\n");
	}
	return 0;
}