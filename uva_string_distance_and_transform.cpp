#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

#define INF 10000000

string a,b;
int dp[82][82];
pair<int, int> path[82][82];

void reset()
{
	memset(dp, -1, sizeof(dp));
	for (int i=0; i<82; i++)
	{
		for (int j=0; j<82; j++)
		{
			path[i][j].first = -1;
			path[i][j].second = -1;
		}
	}
}

int compute(int x, int y)
{
	if ((x==a.length()) && (y==b.length())) return 0;

	if (dp[x][y] == -1)
	{
		int res = INF;

		if ((x<a.length()) && (y<b.length()))
		{
			if (a[x] == b[y])
			{
				res = compute(x+1, y+1);
				path[x][y] = pair<int, int> (x+1, y+1);
			}
			else
			{
				int temp = compute(x+1, y+1) +1;
				if (temp < res)
				{
					res = temp;
					path[x][y] = pair<int, int> (x+1, y+1);
				}
			}
		}

		if (x < a.length())
		{
			int temp = compute(x+1, y)+1;
			if (temp < res)
			{
				res = temp;
				path[x][y] = pair<int, int> (x+1, y);
			}
		}

		if (y < b.length())
		{
			int temp = compute(x, y+1)+1;
			if (temp < res)
			{
				res = temp;
				path[x][y] = pair<int, int> (x, y+1);
			}
		}

		dp[x][y] = res;
	}

	return dp[x][y];
}

void traverse(int x, int y, int z, int mod)
{
	if (path[x][y].first == -1) return;

	if ((path[x][y].first == x+1) && (path[x][y].second == y+1))
	{
		if (a[x] != b[y])
		{
			printf("%d Replace %d,%c\n", z, x+1+mod, b[y]);
			traverse(x+1, y+1, z+1, mod);
		}
		else
			traverse(x+1, y+1, z, mod);
	}

	if ((path[x][y].first == x+1) && (path[x][y].second == y))
	{
		printf("%d Delete %d\n", z, x+1+mod);
		traverse(x+1, y, z+1, mod-1);
	}

	if ((path[x][y].first == x) && (path[x][y].second == y+1))
	{
		printf("%d Insert %d,%c\n", z, x+1+mod, b[y]);
		traverse(x, y+1, z+1, mod+1);
	}
}

int main()
{
	int z=1;
	while (!cin.eof())
	{
		getline(cin, a);
		if (cin.eof()) break;
		getline(cin, b);

		reset();

		if (z>1) printf("\n");
		int res = compute(0,0);
		printf("%d\n", res);
		traverse(0,0,1, 0);
		z+=1;
	}
	return 0;
}