#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

#define INF 200000000LL

struct Node
{
	int line, station;
};

typedef pair<Node, int> pairQueue;

void OPEN(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

class Compare
{
public:
	bool operator() (pairQueue first, pairQueue second)
	{
		return first.second < second.second;
	}
};

vector< pairQueue > adj[102][1002];
int waitingTime[102];
//bool visited[102][1002];
int cost[102][1002];
int t,n,m,dist,a,b,i,j,w,z,q;
int line1, line2, station1, station2, travelTime;
int sourceLine, sourceStation, destLine, destStation;

int dijkstra()
{
	int i,j;
	priority_queue<pairQueue, vector<pairQueue>, Compare> pq;

	//initialize queue
	Node init;
	init.line = sourceLine;
	init.station = sourceStation;
	pq.push(make_pair(init, waitingTime[sourceLine]));

	while (!pq.empty())
	{
		pairQueue cur = pq.top();
		pq.pop();
		int station = cur.first.station;
		int line = cur.first.line;
		if (cost[line][station] != -1)
		{
			printf("Line %d station %d cost %d\n", cur.first.line, cur.first.station, cur.second);
			//visited[line][station] = true;
			cost[line][station] = -1;
			
			if ((line == destLine) && (station == destStation)) return cur.second;
			
			for (i=0; i<adj[line][station].size(); i++)
			{
				Node destNode = adj[line][station][i].first;
				int goingCost = cur.second + adj[line][station][i].second;

				printf("Should be going to line %d station %d cost %d cur cost %d\n", destNode.line, destNode.station, goingCost, cost[destNode.line][destNode.station]);

				if (goingCost < cost[destNode.line][destNode.station])
				{
					if ((destNode.line == destLine) && (destNode.station == destStation))
					{
						if (line != destNode.line) goingCost-= waitingTime[destNode.line];
						return goingCost;
					}
					cost[destNode.line][destNode.station] = goingCost;
					pq.push(make_pair(destNode, goingCost));
				}
			}
		}
	}

	return -1;
}

void reset()
{
	int i,j;
	
	//memset(waitingTime, 0, sizeof(waitingTime));
	//memset(cost, INF, sizeof(cost));
	for (i=0; i<102; i++)
	{
		waitingTime[i] = 0;
		for (j=0; j<1002; j++)
		{
			adj[i][j].clear();
			cost[i][j] = INF;
		}
	}
}

void resetAfterQuery()
{
	int i,j;
	for (i=0; i<102; i++)
	{
		for (j=0; j<1002; j++) cost[i][j] = INF;
	}
}

void printAdjList()
{
	int i,j,k;
	for (i=0; i<102; i++)
	{
		for (j=0; j<1002; j++)
		{
			if (adj[i][j].size() >0)
			{
				printf("Adj for line %d station %d\n", i,j);

				for (k=0; k<adj[i][j].size(); k++)
				{
					printf("Line %d station %d cost %d\n", adj[i][j][k].first.line,adj[i][j][k].first.station, adj[i][j][k].second);
				}
			}
		}
	}
}

int main()
{
	//OPEN("B-large-practice");

	scanf("%d", &t);

	for (z=1; z<=t; z++)
	{
		reset();
		//read the stations
		scanf("%d", &n);
		for (i=0; i<n; i++)
		{
			scanf("%d%d", &a, &b);
			waitingTime[i] = b;

			for (j=0; j<a-1; j++)
			{
				scanf("%d", &w);

				Node first;
				first.line = i;
				first.station = j;

				Node second;
				second.line = i;
				second.station = j+1;

				adj[i][j].push_back(make_pair(second, w));
				adj[i][j+1].push_back(make_pair(first, w));
			}
		}

		scanf("%d", &m);

		for (i=0; i<m; i++)
		{
			scanf("%d%d%d%d%d", &line1, &station1, &line2, &station2, &travelTime);
			line1-=1;
			line2-=1;
			station1-=1;
			station2-=1;

			Node first;
			first.line = line1;
			first.station = station1;

			Node second;
			second.line = line2;
			second.station = station2;

			adj[line1][station1].push_back(make_pair(second, travelTime+waitingTime[line2]));
			adj[line2][station2].push_back(make_pair(first, travelTime+waitingTime[line1]));
		}

		printAdjList();

		printf("Case #%d:\n", z);

		scanf("%d", &q);
		for (i=0; i<q; i++)
		{
			scanf("%d%d%d%d", &sourceLine, &sourceStation, &destLine, &destStation);

			resetAfterQuery();
			sourceLine-=1;
			sourceStation-=1;
			destLine-=1;
			destStation-=1;
			printf("%d\n", dijkstra());
		}


	}
	return 0;	
}