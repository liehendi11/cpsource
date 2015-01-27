#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

int parents[30002];
bool suspects[30002];
int counts[30002];
int mx;

void reset()
{
	for (int i=0; i<30002; i++)
	{
		parents[i] = i;
		suspects[i] = false;
		counts[i] = 1;
	}
	mx=1;
}

int find(int x)
{
	if (parents[x] == x) return parents[x];
	else
	{
		parents[x] = find(parents[x]);
		return parents[x];
	}
}

void unite(int x, int y)
{
	int parentX = find(x);
	int parentY = find(y);

	if (parentX != parentY)
	{
		parents[parentX] = parentY;
		counts[parentY] += counts[parentX];
		suspects[parentY] |= suspects[parentX];

		if (suspects[parentY]) mx = max(mx, counts[parentY]);
	}
}

int main()
{
	int n=-1, m=-1;

	while (!((n==0) && (m==0)))
	{
		scanf("%d%d", &n, &m);
		if ((n==0) && (m==0)) break;

		reset();
		suspects[0] = true;
		int a,b;
		for (int i=0; i<m; i++)
		{
			scanf("%d", &a);

			int first;
			if (a>0) scanf("%d", &first);

			for (int j=1; j<a; j++)
			{
				scanf("%d", &b);
				unite(first, b);
			}
		}

		printf("%d\n", mx);
	}
	return 0;
}