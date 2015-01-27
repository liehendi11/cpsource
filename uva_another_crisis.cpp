#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

vector<int> adj[100002];
int childCount[100002];

int workerCount, n, t;

void reset()
{
	for (int i=0; i<100002; i++)
	{
		adj[i].clear();
		childCount[i] = 0;
	}
	workerCount=0;
}

int findTreeSize(int x)
{
	if (adj[x].size() ==0) return 1;

	for (int i=0; i<adj[x].size(); i++)
	{
		childCount[x]+= findTreeSize(adj[x][i]);
	}

	return childCount[x];
}

bool f(int a, int b)
{
	return (childCount[a] < childCount[b]);
}

void traverse(int x)
{
	if (adj[x].size() ==0)
	{
		workerCount+=1;
		return;
	}

	sort(adj[x].begin(), adj[x].end(), f);

	int minTreshold = (int) ceil( ((float) adj[x].size()) * ((float) t) / ((float) 100));

	for (int i=0; i<minTreshold; i++)
	{
		traverse(adj[x][i]);
	}
}

int main()
{
	n=-1;
	t=-1;
	while (!((n==0) && (t==0)))
	{
		scanf("%d%d", &n, &t);
		if ((n==0) && (t==0)) break;

		reset();
		
		int x;
		for (int i=1; i<=n; i++)
		{
			scanf("%d", &x);
			adj[x].push_back(i);
		}

		findTreeSize(0);
		for (int i=1; i<=n; i++) printf("%d ", childCount[i]);
		printf("\n");
	
		traverse(0);

		printf("%d\n", workerCount);
	}

	return 0;
}