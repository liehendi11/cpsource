#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <string>
#include <iostream>

using namespace std;

int parents[200002];
int counts[200002];
map<string, int> nameMap;

int findParent(int x)
{
	if (parents[x] == x) return x;
	else
	{
		//int prevParent = parents[x];
		parents[x] = findParent(parents[x]);
		int curParent = parents[x];

		//counts[prevParent]-=counts[x];
		//counts[curParent] +=counts[x];
		return curParent;
	}
}

bool isSameSet(int x, int y)
{
	return (findParent(x) == findParent(y));
}

void unionSet(int x, int y)
{
	int parentX = findParent(x);
	int parentY = findParent(y);
	if (parentX != parentY)
	{
		// printf("%d %d %d %d\n", counts[x], counts[y], parents[x], parents[y]);


		parents[parentX] = parentY;
		counts[parentY] += counts[parentX];
		// printf("%d %d %d %d\n", counts[x], counts[y], parents[x], parents[y]);
	}
}



int main()
{
	int tc;
	scanf("%d", &tc);

	for (int z=1; z<=tc; z++)
	{
		int n;
		scanf("%d", &n);
		getchar();
		int numPeople=-1;
		nameMap.clear();

		string a, b;
		for (int i=0; i<n; i++)
		{
			cin >> a >> b;
			int xa, xb;
			getchar();

			if (nameMap.count(a) ==0)
			{
				numPeople+=1;
				parents[numPeople] = numPeople;
				counts[numPeople] = 1;
				nameMap.insert(pair<string, int> (a, numPeople));
				xa = numPeople;
			}
			else
				xa = nameMap[a];

			if (nameMap.count(b) ==0)
			{
				numPeople+=1;
				parents[numPeople] = numPeople;
				counts[numPeople] = 1;
				nameMap.insert(pair<string, int> (b, numPeople));
				xb = numPeople;
			}
			else
				xb = nameMap[b];

			unionSet(xa,xb);

			int pxa = findParent(xa);
			// printf("%d\n", pxa);
			printf("%d\n",counts[findParent(xa)]);
		}
	}
	return 0;
}