#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

map<string, int> creatureMaps;
int parents[5002];
int counts[5002];

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
	int parentX = find(x);
	int parentY = find(y);

	if (parentX != parentY)
	{
		parents[parentX] = parentY;
		counts[parentY] += counts[parentX];
	}
}

void reset()
{
	for (int i=0; i<5002; i++)
	{
		parents[i] = i;
		counts[i]=1;
	}
	creatureMaps.clear();
}

int main()
{
	int n,m;
	n=-1;
	m=-1;
	while (!((n==0) && (m==0)))
	{
		scanf("%d%d", &n, &m);
		if ((n==0) && (m==0)) break;

		reset();
		getchar();

		string s;
		for (int i=0; i<n; i++)
		{
			getline(cin,s);
			creatureMaps.insert(pair<string, int> (s, i));
		}

		string s1,s2;
		for (int i=0; i<m; i++)
		{
			cin >> s1;
			cin >> s2;
			getchar();

			uniteSet(creatureMaps[s1], creatureMaps[s2]);
		}

		int res=0;
		for (int i=0; i<n; i++)
		{
			if (parents[i]==i) res = max(res, counts[i]);
		}

		printf("%d\n", res);
	}
	return 0;
}