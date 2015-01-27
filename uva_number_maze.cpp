#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <cstring>

using namespace std;

#define INF 2000000009LL

struct Node
{
	int x,y,cost;
};

int maze[1002][1002];
int n,m;
int cost[1002][1002];

bool insideMaze(int x, int y)
{
	return ((x>=0) && (x<n) && (y>=0) && (y<m));
}

class mycomparison
{
public:
  	bool operator() (const Node& lhs, const Node&rhs) const
  	{
    	return lhs.cost > rhs.cost;
  	}
};

void dijkstra()
{
	priority_queue<Node, vector<Node>, mycomparison> pq;

	bool arrived=false;
	Node first;
	first.x = 0;
	first.y = 0;
	first.cost = maze[0][0];
	cost[0][0] = maze[0][0];
	pq.push(first);


	while (!arrived)
	{
		Node cur = pq.top();
		pq.pop();

		//printf("%d %d %d\n", cur.x, cur.y, cur.cost);

		cost[cur.x][cur.y] = -1;

		if ((cur.x == n-1) && (cur.y == m-1))
		{
			arrived=true;
			printf("%d\n", cur.cost);
		}
		else
		{
			//bottom
			if (insideMaze(cur.x+1, cur.y))
			{
				if (cost[cur.x+1][cur.y] > cur.cost + maze[cur.x+1][cur.y])
				{
					Node newNode = cur;
					newNode.x = cur.x+1;
					newNode.y = cur.y;
					newNode.cost += maze[newNode.x][newNode.y];

					//printf("new node %d %d %d\n", newNode.x, newNode.y, newNode.cost);

					cost[cur.x+1][cur.y] = newNode.cost;
					pq.push(newNode);
				}
			}

			//top
			if (insideMaze(cur.x-1, cur.y))
			{
				if (cost[cur.x-1][cur.y] > cur.cost + maze[cur.x-1][cur.y])
				{
					Node newNode = cur;
					newNode.x = cur.x-1;
					newNode.y = cur.y;
					newNode.cost += maze[newNode.x][newNode.y];

					//printf("new node %d %d %d\n", newNode.x, newNode.y, newNode.cost);

					cost[newNode.x][newNode.y] = newNode.cost;
					pq.push(newNode);
				}
			}

			//right
			if (insideMaze(cur.x, cur.y+1))
			{
				if (cost[cur.x][cur.y+1] > cur.cost + maze[cur.x][cur.y+1])
				{
					Node newNode = cur;
					newNode.x = cur.x;
					newNode.y = cur.y+1;
					newNode.cost += maze[newNode.x][newNode.y];

					//printf("new node %d %d %d\n", newNode.x, newNode.y, newNode.cost);

					cost[newNode.x][newNode.y] = newNode.cost;
					pq.push(newNode);
				}
			}

			//left
			if (insideMaze(cur.x, cur.y-1))
			{
				if (cost[cur.x][cur.y-1] > cur.cost + maze[cur.x][cur.y-1])
				{
					Node newNode = cur;
					newNode.x = cur.x;
					newNode.y = cur.y-1;
					newNode.cost += maze[newNode.x][newNode.y];

					//printf("new node %d %d %d\n", newNode.x, newNode.y, newNode.cost);

					cost[newNode.x][newNode.y] = newNode.cost;
					pq.push(newNode);
				}
			}
		}
	}
}

int main()
{
	int tc;
	scanf("%d", &tc);
	for (int z=1; z<=tc; z++)
	{
		scanf("%d%d", &n, &m);
		memset(maze, 0, sizeof(maze));
		memset(cost, INF, sizeof(cost));

		for (int i=0; i<n; i++)
		{
			for (int j=0; j<m; j++)
			{
				scanf("%d", &maze[i][j]);
			}
		}

		dijkstra();
	}
	return 0;
}