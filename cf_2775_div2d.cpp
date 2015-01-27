#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
#include <string.h>

using namespace std;

vector<int> adj[3002];
int goingAdj[3002][3002];
int n,m;

void move(int source, int dest, int step)
{
	if (step == 1)
	{
		goingAdj[source][dest]+=1;
	}
	else
	{
		for (int i=0; i<adj[dest].size(); i++)
		{
			if (adj[dest][i] != source) move(source, adj[dest][i], 1);
		}
	}
}

int combination(int x)
{
	if (x<2) return 0;
	else
		return (x*(x-1)/2);
}

void generate()
{
	for (int i=1; i<=n; i++)
	{
		for (int j=0; j<adj[i].size(); j++)
		{
			move(i, adj[i][j], 0);
		}
	}

	long long total=0;
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			if ((i!=j) && (goingAdj[i][j] >=2))
			{
				total+=combination(goingAdj[i][j]);
			}
		}
	}
	cout << total << endl;
}

int main()
{
	scanf("%d%d", &n, &m);

	int a,b;
	for (int i=0; i<m; i++)
	{
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
	}

	memset(goingAdj, 0, sizeof(goingAdj));
	generate();
	return 0;
}