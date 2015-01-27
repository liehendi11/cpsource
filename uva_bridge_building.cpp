#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

#define INF 100000000LL

char map[1002][1002];
int top[1002], bottom[1002];
int row, col;
int b,s;
//int mode;
int dp[102][1002];

void dfs(int x, int y, int mode)
{
	map[x][y] = '*';
	if (mode == 0) //top
		top[y] = max(top[y], x);
	else
	{
		bottom[y] = min(bottom[y], x);
		// printf("bottom %d %d ==> %d\n", x, y, bottom[y]);
	}
		

	if (x>0)
		if (map[x-1][y] == '#') dfs(x-1, y, mode);
	if (y>0)
		if (map[x][y-1] == '#') dfs(x, y-1, mode);
	if (x< row-1)
		if (map[x+1][y] == '#') dfs(x+1, y, mode);
	if (y< col-1)
		if (map[x][y+1] == '#') dfs(x, y+1, mode);
}

void preprocess()
{
	memset(top, 0, sizeof(top));
	
	for (int j=0; j<col; j++) bottom[j] = 3000;

	memset(dp, -1, sizeof(dp));

	for (int j=0; j<col; j++)
	{
		if (map[0][j] == '#') dfs(0,j,0);
		if (map[row-1][j] == '#') dfs(row-1, j, 1);
	}
}

int compute(int curBridge, int curCol)
{
	if (curBridge == b) return 0;
	if (curCol >= col) return INF;

	if (dp[curBridge][curCol] == -1)
		dp[curBridge][curCol] = min(bottom[curCol] - top[curCol]-1 + compute(curBridge+1, curCol+s+1), compute(curBridge, curCol+1));

	return dp[curBridge][curCol];
}

int main()
{
	while (scanf("%d%d", &row, &col) != EOF)
	{
		scanf("%d%d", &b, &s);
		getchar();

		memset(map, '.', sizeof(map));

		for (int i=0; i<row; i++)
		{
			for (int j=0; j<col; j++)
			{
				scanf("%c", &map[i][j]);
			}
			getchar();
		}

		preprocess();

		// for (int i=0; i<row; i++)
		// {
		// 	for (int j=0; j<col; j++)
		// 	{
		// 		printf("%c", map[i][j]);
		// 	}
		// 	printf("\n");
		// }

		// for (int i=0; i<col; i++) printf("%d ", top[i]);
		// printf("\n");

		// for (int i=0; i<col; i++) printf("%d ", bottom[i]);
		// printf("\n");

		printf("%d\n", compute(0,0));
	}
	return 0;
}