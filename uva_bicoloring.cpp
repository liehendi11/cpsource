#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

vector<int> adj[202];
int color[202];
int n,m;

void reset()
{
	for (int i=0; i<202; i++)
	{
		adj[i].clear();
		color[i]=-1;
	}
}

bool colorable(int x, int curColor)
{
	if (color[x] == -1)
	{
		color[x] = curColor;
		bool res = true;
		int newColor = (curColor+1)%2;
		for (int i=0; i<adj[x].size(); i++)
		{
			if (color[adj[x][i]] == -1) res = res & colorable(adj[x][i], (curColor+1)%2);
			else
				if (color[adj[x][i]] != newColor) res=false;
		}

		return res;
	}
	else
		if (color[x] != curColor) return false;
}

int main()
{
	n=-1;
	while (n!=0)
	{
		scanf("%d", &n);
		if (n==0) break;
		scanf("%d", &m);

		reset();

		int a,b;
		for (int i=0; i<m; i++)
		{
			scanf("%d%d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		if (colorable(0,0))
		{
			printf("BICOLORABLE.\n");
		}
		else
			printf("NOT BICOLORABLE.\n");
	}
	return 0;
}