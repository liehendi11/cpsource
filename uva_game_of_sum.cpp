#include <stdio.h>
#include <stdlib.h>
#include <cstring>

using namespace std;

pair<int, int> dp[3][1002][1002];
bool visited[3][1002][1002];

void init()
{
	memset(visited, false, sizeof(visited));
}

pair<int, int> compute(int turn, int x, int y)
{
	if (x > y) return pair<int, int> (0,0);

	if (!visited[turn][x][y])
	{
		visited[turn][x][y] = true;

		
	}
}

int main()
{
	return 0;
}