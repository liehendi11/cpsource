#include <stdio.h>
#include <queue>
#include <stack>

using namespace std;

int tc;
int n,s,q;
int time=0;
int delivered =0;
queue<int> stations[102];
stack<int> vehicle;

void reset()
{
	for (int i=0; i<102; i++) while (!stations[i].empty()) stations[i].pop();
	while (!vehicle.empty()) vehicle.pop();
	time=0;
}

void process(int x)
{
	//unload all

	while (!vehicle.empty())
	{
		if (vehicle.top() == x)
		{
			vehicle.pop();
			delivered-=1;
			time+=1;
		}
		else
			if (stations[x].size() < q)
			{
				stations[x].push(vehicle.top());
				vehicle.pop();
				time+=1;
			}
			else
				break;
	}

	//load to vehicle
	while ((!stations[x].empty()) && (vehicle.size() < s))
	{
		vehicle.push(stations[x].front());
		stations[x].pop();
		time+=1;
	}

	if (delivered>0)
	{
		time+=2;
		process((x+1)%n);
	}
		
}

int main()
{
	scanf("%d", &tc);
	for (int z=1; z<=tc; z++)
	{
		reset();
		scanf("%d%d%d", &n, &s, &q);
		for (int i=0; i<n; i++)
		{
			int x,y;
			scanf("%d", &x);
			for (int j=0; j<x; j++)
			{
				scanf("%d", &y);
				y-=1;
				stations[i].push(y);
				delivered+=1;
			}
		}

		process(0);

		printf("%d\n", time);
	}

	return 0;
}