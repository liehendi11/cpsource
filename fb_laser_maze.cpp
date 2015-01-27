#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

class Data
{
public:
	int x, y, steps;
	Data(int ax, int ay, int asteps)
	{
		x = ax;
		y = ay;
		steps = asteps;
	}
};

bool visited[102][102][5];
char grid[102][102];
int col, row;
int sx, sy;

int findDirection(int x, int y, int steps)
{
	int temp =0;
	switch (grid[x][y])
	{
		case '^': default:
			temp = 0;
			break;
		case '>':
			temp = 1;
			break;
		case 'v':
			temp = 2;
			break;
		case '<':
			temp = 3;
			break;
	}

	// printf("lala %d %d\n", temp, steps);

	return ((temp + steps) %4);
}

bool isLaser(int x, int y)
{
	return ((grid[x][y] == '^') || (grid[x][y] == 'v') || (grid[x][y] == '<') || (grid[x][y] == '>'));
}

bool checkSafety(Data curState)
{
	int x = curState.x;
	int y = curState.y;
	int steps = curState.steps;

	//to top
	int p = x-1;
	while (p>=0)
	{
		if (isLaser(p, y))
		{
			if (findDirection(p,y,steps) == 2) return false;
			break;
		}
		else
			if (grid[p][y] == '#') break;

		p-=1;
	}

	//left
	p=y-1;
	while (p>=0)
	{
		if (isLaser(x, p))
		{
			if (findDirection(x,p,steps) == 1) return false;
			break;
		}
		else
			if (grid[x][p] == '#') break;

		p-=1;
	}

	//bottom
	p = x+1;
	while (p<row)
	{
		if (isLaser(p, y))
		{
			if (findDirection(p,y,steps) == 0) return false;
			break;
		}
		else
			if (grid[p][y] == '#') break;

		p+=1;
	}

	//right
	p=y+1;
	while (p<col)
	{
		if (isLaser(x, p))
		{
			if (findDirection(x,p,steps) == 3) return false;
			break;
		}
		else
			if (grid[x][p] == '#') break;

		p+=1;
	}

	return true;
}

bool isValid(int x, int y)
{
	if ((x < 0) || (x >= row) || (y<0) || (y>=col)) return false;
	return ((grid[x][y] == '.') || (grid[x][y] == 'S') || (grid[x][y] == 'G'));
}

bool isVisited(Data curState)
{
	return (visited[curState.x][curState.y][curState.steps%4]);
}

bool flagVisited(Data curState)
{
	visited[curState.x][curState.y][curState.steps%4] = true;
}

void bfs(int z)
{
	int res = -1;
	Data newData (sx, sy, 0);
	queue<Data> q;

	// if (checkSafety(newData))
	// {
	q.push(newData);
	flagVisited(newData);
	// }

	while (!q.empty())
	{
		Data curState = q.front();

		if (grid[curState.x][curState.y] == 'G')
		{
			res = curState.steps;
			break;
		}
		q.pop();

		if (isValid(curState.x+1, curState.y))
		{
			Data newState (curState.x+1, curState.y, curState.steps+1);
			if (checkSafety(newState) && (!isVisited(newState)))
			{
				q.push(newState);
				flagVisited(newState);
			}
		}

		if (isValid(curState.x-1, curState.y))
		{
			Data newState (curState.x-1, curState.y, curState.steps+1);
			if (checkSafety(newState) && (!isVisited(newState)))
			{
				q.push(newState);
				flagVisited(newState);
			}
		}

		if (isValid(curState.x, curState.y+1))
		{
			Data newState (curState.x, curState.y+1, curState.steps+1);
			if (checkSafety(newState) && (!isVisited(newState)))
			{
				q.push(newState);
				flagVisited(newState);
			}
		}

		if (isValid(curState.x, curState.y-1))
		{
			Data newState (curState.x, curState.y-1, curState.steps+1);
			if (checkSafety(newState) && (!isVisited(newState)))
			{
				q.push(newState);
				flagVisited(newState);
			}
		}

	}

	if (res != -1) printf("Case #%d: %d\n", z, res);
	else
		printf("Case #%d: impossible\n", z);
}

void OPEN(string s) {
	freopen((s + ".txt").c_str(), "r", stdin);
	freopen((s + "_out.txt").c_str(), "w", stdout);
}

int main()
{
	// OPEN("laser_maze");
	int tc;
	scanf("%d", &tc);
	// getchar();

	for (int z=1; z<=tc; z++)
	{
		scanf("%d%d", &row, &col);
		memset(visited, false, sizeof(visited));
		getchar();
		for (int i=0; i<row; i++)
		{
			for (int j=0; j<col; j++)
			{
				scanf("%c", &grid[i][j]);
				if (grid[i][j] == 'S')
				{
					sx = i;
					sy = j;
				}
			}
			getchar();
		}

		bfs(z);
	}
	return 0;
}