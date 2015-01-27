#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <set>

using namespace std;

queue<int> emergency;
set<int> rushed;
int n,m;
int z=1;

int findNextPatient(int cur)
{
	while (rushed.count(cur) >0)
	{
		cur+=1;
		if (cur > n)
			cur=1;
	}

	return cur;
}

int main()
{
	n=-1;
	m=-1;
	while (!((n==0) && (m==0)))
	{
		scanf("%d%d", &n, &m);
		getchar();
		if ((n==0) && (m==0)) break;

		int cur=1;
		char com;

		printf("Case %d:\n",z);
		for (int i=0; i<n; i++)
		{
			scanf("%c", &com);
			if (com=='E')
			{
				int patientID;
				scanf("%d", &patientID);

				emergency.push(patientID);
				rushed.insert(patientID);
			}
			else
			{
				if (!emergency.empty())
				{
					printf("%d\n", emergency.front());
					rushed.erase(emergency.front());
					emergency.pop();
				}
				else
				{
					printf("%d\n", cur);
					cur = findNextPatient(cur);
				}
			}

			getchar();
		}
	}
}