#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int years[28];
vector<int> adj[28];
int n,m;
string input;

int findConnections(int x, int limit)
{
	vector<int> connected;
	for (int i=0; i<adj[x].size(); i++)
	{
		if ((years[adj[x][i]] > -1) && (years[adj[x][i]] <limit)) connected.push_back(years[adj[x][i]]);
	}

	// printf("%d %d: ", x, limit);

	// for (int i=0; i<connected.size(); i++)
	// {
	// 	printf("%d ", connected[i]);
	// }
	// printf("\n");

	if (connected.size() >= 3)
	{
		sort(connected.begin(), connected.end());
		years[x] = connected[2]+1;
		return connected[2];
	}
	else
		return -1;
}

int main()
{
	while (scanf("%d%d", &n, &m) != EOF)
	{
		for (int i=0; i<28; i++)
		{
			years[i] = -2;
			adj[i].clear();
		}

		getchar();

		getline(cin, input);
		int a,b,c;
		a=input[0]-65;
		b=input[1]-65;
		c=input[2]-65;
		years[a] = 0;
		years[b] = 0;
		years[c] = 0;

		for (int i=0; i<m; i++)
		{
			getline(cin, input);

			a = input[0]-65;
			b = input[1]-65;

			//printf("%d %d\n",a,b);
			adj[a].push_back(b);
			adj[b].push_back(a);
			if (years[a]!=0) years[a] = -1;
			if (years[b]!=0) years[b] = -1;
			
		}

		for (int i=1; i<=28; i++)
		{
			for (int j=0; j<28; j++)
			{
				if (years[j] == -1) findConnections(j,i);
			}
		}


		int resMax = 0;
		bool allConnected=true;
		for (int i=0; i<28; i++)
		{
			//printf("%d ", years[i]);
			if (years[i]!=-2)
			{
				if (years[i]==-1) allConnected=false;
				else
				{
					resMax = max(resMax, years[i]);
					n-=1;
				}
			}
		}

		//printf("\n");

		if ((allConnected) && (n==0))
		{
			printf("WAKE UP IN, %d, YEARS\n", resMax);
		}
		else
			printf("THIS BRAIN NEVER WAKES UP\n");
	}
	
	return 0;
}