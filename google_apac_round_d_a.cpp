#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int t,n,z;
int maze[1003][1003];
bool visited[1003][1003];
int dp[1003][1003];
int res, mx, temp;

bool insideMaze(int x, int y)
{
	return ((x>=0) && (y>=0) && (x<n) && (y<n));
}

int move(int x, int y)
{
	int res = 1;
	if (!visited[x][y])
	{
		visited[x][y] = true;

		if (insideMaze(x+1, y))
			if (maze[x+1][y] == maze[x][y]+1) res = max(res, move(x+1, y)+1);
		if (insideMaze(x-1, y))
			if (maze[x-1][y] == maze[x][y]+1) res = max(res, move(x-1, y)+1);
		if (insideMaze(x, y+1))
			if (maze[x][y+1] == maze[x][y]+1) res = max(res, move(x, y+1)+1);
		if (insideMaze(x, y-1))
			if (maze[x][y-1] == maze[x][y]+1) res = max(res, move(x, y-1)+1);

		dp[x][y] = res;
		return res;
	}
	else
		return dp[x][y];
	
}

void printMaze()
{
	int i,j;
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			printf("%d ", maze[i][j]);
		}
		printf("\n");
	}


	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
}

void OPEN(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main()
{
	//OPEN("A-large");
	int i,j;
	scanf("%d", &t);
	for (z=1; z<=t; z++)
	{
		memset(dp, -1, sizeof(dp));
		memset(visited, false, sizeof(visited));
		scanf("%d", &n);
		for (i=0; i<n; i++)
		{
			for (j=0; j<n; j++)
			{
				scanf("%d", &maze[i][j]);
			}
		}

		mx = -1;
		res = 0;
		for (i=0; i<n; i++)
		{
			for (j=0; j<n; j++)
			{
				if (!visited[i][j])
				{
					temp = move(i,j);
					if ((temp > mx) || ((temp == mx) && (res > maze[i][j])))
					{
						mx = temp;
						res = maze[i][j];
					}
				}
			}
		}

		//printMaze();

		printf("Case #%d: %d %d\n", z, res, mx);
	}
	return 0;
}