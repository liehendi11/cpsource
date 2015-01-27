#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <queue>

using namespace std;

void OPEN(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main()
{
	//OPEN("test");
	int n=-1;
	int z=1;
	while (n!=0)
	{
		scanf("%d", &n);
		if (n==0) break;

		printf("Scenario #%d\n", z);

		map<int, int> teamMap;
		vector<queue<int> > teamQueues;
		vector<int> teams;
		
		for (int i=0; i<n; i++)
		{
			int x,bil;
			scanf("%d", &x);
			for (int j=0; j<x; j++)
			{
				scanf("%d", &bil);
				teamMap.insert(pair<int, int> (bil,i));
			}
		}

		getchar();
		string com = "";
		int input;
		int lowerTreshold=0;
		while (com != "STOP")
		{
			cin >> com;
			if (com=="STOP") break;

			if (com=="ENQUEUE")
			{
				scanf("%d", &input);

				int inputTeam = teamMap[input];
				bool foundTeam = false;
				for (int i=lowerTreshold; i<teams.size(); i++)
				{
					if (teams[i] == inputTeam)
					{
						teamQueues[i].push(input);
						foundTeam=true;
					}
				}

				if (!foundTeam)
				{
					queue<int> newQueue;
					newQueue.push(input);
					teamQueues.push_back(newQueue);
					teams.push_back(inputTeam);
				}
			}
			else
			{
				printf("%d\n",teamQueues[lowerTreshold].front());
				teamQueues[lowerTreshold].pop();
				if (teamQueues[lowerTreshold].size()==0)
				{
					lowerTreshold+=1;
				}
			}

			getchar();
		}

		z+=1;
		printf("\n");
	}
	

	return 0;
}
