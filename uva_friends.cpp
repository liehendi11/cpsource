#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int parents[30002];
int counts[30002];

void reset(int n)
{
	for (int i=1; i<=n; i++)
	{
		parents[i] = i;
		counts[i] = 0;
	}
}

int find(int x)
{
	if (parents[x] == x) return x;
	else
	{
		parents[x] = find(parents[x]);
		return parents[x];
	}
}

void uniteSet(int x, int y)
{
	parents[find(x)] = find(y);
}

int main()
{
	int tc;
	scanf("%d", &tc);
	for (int z=0; z<tc; z++)
	{
		int n,m,a,b;
		scanf("%d%d", &n, &m);
		reset(n);

		for (int i=0; i<m; i++)
		{
			scanf("%d%d", &a, &b);

			uniteSet(a,b);
		}

		//do the path compression
		int mx=0;
		for (int i=1; i<=n; i++)
		{
			find(i);
			counts[parents[i]] += 1;
			mx = max(counts[parents[i]], mx);
		}

		printf("%d\n", mx);
	}
	return 0;
}