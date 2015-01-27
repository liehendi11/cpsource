#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

typedef pair<int, int> pp;
struct Data
{
	int x, y, time;
};

bool visited[502][502][4];
vector<pp> moves[502][502];
int n,m;


pp findMove(pp initMove, int time, int x, int y)
{
	int moveTime = time%4;
	pp ret;

	//top
	if ((initMove.first == -1) && (initMove.second ==0))
	{
		switch(moveTime)
		{
			case 0: default: ret.first = -1; ret.second = 0; break;
			case 1: ret.first = 0; ret.second = 1; break;
			case 2: ret.first = 1; ret.second = 0; break;
			case 3: ret.first = 0; ret.second = -1; break;
		}
	}

	if ((initMove.first == 0) && (initMove.second ==1))
	{
		switch(moveTime)
		{
			case 0: default: ret.first = 0; ret.second = 1; break;
			case 1: ret.first = 1; ret.second = 0; break;
			case 2: ret.first = 0; ret.second = -1; break;
			case 3: ret.first = -1; ret.second = 0; break;
		}
	}

	if ((initMove.first == 1) && (initMove.second ==0))
	{
		switch(moveTime)
		{
			case 0: default: ret.first = 1; ret.second = 0; break;
			case 1: ret.first = 0; ret.second =-1; break;
			case 2: ret.first =-1; ret.second = 0; break;
			case 3: ret.first = 0; ret.second = 1; break;
		}
	}

	if ((initMove.first == 0) && (initMove.second == -1))
	{
		switch(moveTime)
		{
			case 0: default: ret.first = 0; ret.second = -1; break;
			case 1: ret.first = -1; ret.second = 0; break;
			case 2: ret.first = 0; ret.second = 1; break;
			case 3: ret.first = 1; ret.second = 0; break;
		}
	}

	ret.first +=x;
	ret.second += y;
	return ret;
}

bool insideMaze(pp move)
{
	return (move.first >=0) && (move.first < n) && (move.second >=0) && (move.second < m);
}

void bfs()
{
	Data firstData;
	firstData.x = 0;
	firstData.y = 0;
	firstData.time = 0;
	visited[0][0][0] = true;

	queue<Data> q;
	q.push(firstData);
	bool found=false;

	while (!q.empty())
	{
		Data cur = q.front();
		q.pop();

		//printf("%d %d %d\n", cur.x, cur.y, cur.time);
		if ((cur.x == n-1) && (cur.y == m-1))
		{
			printf("%d\n", cur.time);
			found=true;
			break;
		}

		//cur.time+=1;

		for (int i=0; i<moves[cur.x][cur.y].size(); i++)
		{
			pp newMove = findMove(moves[cur.x][cur.y][i], cur.time, cur.x, cur.y);
			if (insideMaze(newMove))
			{
				if (!visited[newMove.first][newMove.second][(cur.time+1)%4])
				{
					Data newNode = cur;
					newNode.x = newMove.first;
					newNode.y = newMove.second;
					newNode.time+=1;
					visited[newNode.x][newNode.y][newNode.time%4] = true;
					q.push(newNode);
				}
			}
		}
	}

	if (!found)
	{
		printf("no path to exit\n");
	}
}

void reset()
{
	memset(visited, false, sizeof(visited));
	for (int i=0; i<502; i++)
	{
		for (int j=0; j<502; j++)
		{
			moves[i][j].clear();
		}
	}
}

int main()
{
	pp north,south,west,east;
	north.first = -1; north.second = 0;
	south.first = 1; south.second = 0;
	west.first = 0; west.second = -1;
	east.first = 0; east.second = 1;

	while (scanf("%d%d", &n, &m) != EOF)
	{
		getchar();
		reset();
		string input;

		for (int i=0; i<n; i++)
		{
			for (int j=0; j<m; j++)
			{
				if ((i==n-1) && (j==m-1)) break;
				getline(cin, input);

				for (int k=0; k<input.length(); k++)
				{
					if (input[k] == 'N') moves[i][j].push_back(north);
					if (input[k] == 'S') moves[i][j].push_back(south);
					if (input[k] == 'E') moves[i][j].push_back(east);
					if (input[k] == 'W') moves[i][j].push_back(west);
				}
			}
		}

		bfs();
	}

	return 0;
}