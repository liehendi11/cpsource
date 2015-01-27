#include <stdio.h>
#include <stdlib.h>

using namespace std;

int moneySum[10002];
int parents[10002];

int find(int x)
{
	if (parents[x]==x) return x;
	else
	{
		parents[x] = find(parents[x]);
		return parents[x];
	}
}

void uniteSet(int x, int y)
{
	int parentX = find(x);
	int parentY = find(y);

	if (parentX!=parentY)
	{
		parents[parentX] = parentY;
		moneySum[parentY] += moneySum[parentX];
	}
}

void reset()
{
	for (int i=0; i<10002; i++)
	{
		moneySum[i] = 0;
		parents[i] = i;
	}
}

int main()
{
	int tc;
	scanf("%d", &tc);
	for (int z=1; z<=tc; z++)
	{
		int n,m;
		scanf("%d%d", &n, &m);
		reset();

		for (int i=0; i<n; i++) scanf("%d", &moneySum[i]);

		int a,b;
		for (int i=0; i<m; i++)
		{
			scanf("%d%d", &a, &b);
			uniteSet(a,b);
		}

		bool possible=true;
		for (int i=0; i<n; i++)
		{
			if (parents[i] == i)
			{
				if (moneySum[i] != 0) possible=false;
			}
		}

		if (possible)
			printf("POSSIBLE\n");
		else
			printf("IMPOSSIBLE\n");
	}
	return 0;
}