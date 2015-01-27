#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int parents[50002];


void reset(int n)
{
	for (int i=1; i<=n; i++)
		parents[i] = i;
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
	int n=1,m=1;
	int z=0;
	while (!((n==0) && (m==0)))
	{
		z+=1;
		scanf("%d%d", &n, &m);
		if (((n==0) && (m==0))) break;	

		reset(n);

		int a,b;
		for (int i=0; i<m; i++)
		{
			scanf("%d%d", &a, &b);
			uniteSet(a,b);
		}

		int res = 0;

		for (int i=1; i<=n; i++)
		{
			if (parents[i] == i) res+=1;
		}

		printf("Case %d: %d\n", z, res);
	}
	return 0;
}