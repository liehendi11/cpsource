#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>

using namespace std;

void OPEN(string inputFile, string outputFile) {
	freopen(inputFile.c_str(), "r", stdin);
	freopen(outputFile.c_str(), "w", stdout);
}

int main()
{
	OPEN("cowroute.in", "cowroute.out");
	int a,b,n;
	scanf("%d%d%d", &a, &b, &n);
	int minCost = 1002;

	for (int i=0; i<n; i++)
	{
		int cost, city;
		scanf("%d%d", &cost, &city);

		bool getFirst = false, getSecond = false;
		int x;

		for (int i=0; i<city; i++)
		{
			scanf("%d", &x);
			if (!getFirst)
			{
				if (x == a) getFirst=true;
			}
			else
			{
				if (x == b) getSecond=true;
			}
		}

		if (getFirst && getSecond) minCost = min(minCost, cost);
	}

	if (minCost == 1002) printf("-1\n");
	else
	printf("%d\n", minCost);

	return 0;
}