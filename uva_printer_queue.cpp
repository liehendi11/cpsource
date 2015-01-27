#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <cstring>

using namespace std;

struct tdata
{
	int priority;
	bool isUser;
};

queue<tdata> q;
int priorityCounts[10];
int priorityIdx=9;

void findPriority()
{
	while ((priorityIdx >0) && (priorityCounts[priorityIdx] == 0))
		priorityIdx-=1;
}

void reset()
{
	memset(priorityCounts, 0, sizeof(priorityCounts));
	priorityIdx=9;

	while (!q.empty()) q.pop();
}

int main()
{
	int tc;
	scanf("%d", &tc);

	for (int z=1; z<=tc; z++)
	{
		int n,m,x;
		scanf("%d%d", &n, &m);
		reset();

		for (int i=0; i<n; i++)
		{
			scanf("%d", &x);

			tdata newTask;
			newTask.priority = x;
			priorityCounts[x] +=1;
			newTask.isUser = (i==m);
			q.push(newTask);
		}

		findPriority();

		int sumTime = 0;
		while (!q.empty())
		{
			tdata top = q.front();
			q.pop();
			if (top.priority == priorityIdx)
			{
				priorityCounts[priorityIdx]-=1;
				sumTime+=1;
				if (top.isUser) break;

				if (priorityCounts[priorityIdx] ==0) findPriority();
			}
			else
				q.push(top);
		}

		printf("%d\n", sumTime);
	}
	return 0;
}