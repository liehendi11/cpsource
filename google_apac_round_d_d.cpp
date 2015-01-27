#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>

using namespace std;

int t,n;
int i,j,z,k;
int sum[10][10];
int map[10][10];
int col, row, type;
long long totalMove = 0;

bool insideMap(int x, int y)
{
	return ((x>=0) && (y>=0) && (x<8) && (y<8));
}

void king(int x, int y)
{
	if (insideMap(x+1, y)) sum[x+1][y]+=1;
	if (insideMap(x-1, y)) sum[x-1][y]+=1;
	if (insideMap(x, y+1)) sum[x][y+1]+=1;
	if (insideMap(x, y-1)) sum[x][y-1]+=1;
	if (insideMap(x+1, y+1)) sum[x+1][y+1]+=1;
	if (insideMap(x+1, y-1)) sum[x+1][y-1]+=1;
	if (insideMap(x-1, y+1)) sum[x-1][y+1]+=1;
	if (insideMap(x-1, y-1)) sum[x-1][y-1]+=1;
}

void printMap()
{
	int i,j;

	printf("\n");
	for (i=0; i<8; i++)
	{
		for (j=0; j<8; j++)
		{
			// if (map[i][j] >0)
				printf("%d",sum[i][j]);
			// else
				// printf("0");
		}
		printf("\n");
	}
	printf("\n");
	for (i=0; i<8; i++)
	{
		for (j=0; j<8; j++)
		{
			printf("%d",map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void pawn(int x, int y)
{
	if (insideMap(x-1,y-1))
	{
		//printf("Got this 1\n");
		sum[x-1][y-1] +=1;
	}
	if (insideMap(x+1,y-1))
	{
		//printf("Got this 2\n");
		sum[x+1][y-1] +=1;
	}
}

void knight(int x, int y)
{
	if (insideMap(x+1, y+2)) sum[x+1][y+2] +=1;
	if (insideMap(x+1, y-2)) sum[x+1][y-2] +=1;
	if (insideMap(x-1, y+2)) sum[x-1][y+2] +=1;
	if (insideMap(x-1, y-2)) sum[x-1][y-2] +=1;
	if (insideMap(x+2, y+1)) sum[x+2][y+1] +=1;
	if (insideMap(x+2, y-1)) sum[x+2][y-1] +=1;
	if (insideMap(x-2, y+1)) sum[x-2][y+1] +=1;
	if (insideMap(x-2, y-1)) sum[x-2][y-1] +=1;
}

void rook(int x, int y)
{
	int diffx, diffy, tempx, tempy;
	
	//top
	diffx =1;
	diffy =0;
	tempx = x;
	tempy = y;
	while (true)
	{
		tempx+=diffx;
		tempy+=diffy;
		if (!insideMap(tempx, tempy)) break;
		else
			if (map[tempx][tempy] != 0)
			{
				sum[tempx][tempy] +=1;
				break;
			}
	}

	//down
	diffx =-1;
	diffy =0;
	tempx = x;
	tempy = y;
	while (true)
	{
		tempx+=diffx;
		tempy+=diffy;
		if (!insideMap(tempx, tempy)) break;
		else
			if (map[tempx][tempy] != 0)
			{
				sum[tempx][tempy] +=1;
				break;
			}
	}

	//left
	diffx =0;
	diffy =-1;
	tempx = x;
	tempy = y;
	while (true)
	{
		tempx+=diffx;
		tempy+=diffy;
		if (!insideMap(tempx, tempy)) break;
		else
			if (map[tempx][tempy] != 0)
			{
				sum[tempx][tempy] +=1;
				break;
			}
	}

	//right
	diffx =0;
	diffy =1;
	tempx = x;
	tempy = y;
	while (true)
	{
		tempx+=diffx;
		tempy+=diffy;
		if (!insideMap(tempx, tempy)) break;
		else
			if (map[tempx][tempy] != 0)
			{
				sum[tempx][tempy] +=1;
				break;
			}
	}
}

void bishop(int x, int y)
{
	int diffx, diffy, tempx, tempy;
	
	//top
	diffx =1;
	diffy =1;
	tempx = x;
	tempy = y;
	while (true)
	{
		tempx+=diffx;
		tempy+=diffy;
		if (!insideMap(tempx, tempy)) break;
		else
			if (map[tempx][tempy] != 0)
			{
				sum[tempx][tempy] +=1;
				break;
			}
	}

	//down
	diffx =-1;
	diffy =1;
	tempx = x;
	tempy = y;
	while (true)
	{
		tempx+=diffx;
		tempy+=diffy;
		if (!insideMap(tempx, tempy)) break;
		else
			if (map[tempx][tempy] != 0)
			{
				sum[tempx][tempy] +=1;
				break;
			}
	}

	//left
	diffx =-1;
	diffy =-1;
	tempx = x;
	tempy = y;
	while (true)
	{
		tempx+=diffx;
		tempy+=diffy;
		if (!insideMap(tempx, tempy)) break;
		else
			if (map[tempx][tempy] != 0)
			{
				sum[tempx][tempy] +=1;
				break;
			}
	}

	//right
	diffx =1;
	diffy =-1;
	tempx = x;
	tempy = y;
	while (true)
	{
		tempx+=diffx;
		tempy+=diffy;
		if (!insideMap(tempx, tempy)) break;
		else
			if (map[tempx][tempy] != 0)
			{
				sum[tempx][tempy] +=1;
				break;
			}
	}
}

void queen(int x, int y)
{
	rook(x,y);
	bishop(x,y);
}

void OPEN(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main()
{
	OPEN("D-large");
	scanf("%d", &t);
	for (z=1; z<=t; z++)
	{
		memset(sum, 0, sizeof(sum));
		memset(map, 0, sizeof(map));
		totalMove=0;

		string piece;
		scanf("%d", &n);
		getchar();
		for (i=0; i<n; i++)
		{
			getline(cin, piece);

			col = 7-(piece[0]-65);
			row = piece[1]-49;

			switch(piece[3])
			{
				case 'K': type = 1; break;
				case 'Q': type = 2; break;
				case 'R': type = 3; break;
				case 'B': type = 4; break;
				case 'N': type = 5; break;
				default: case 'P': type = 6; break;
			}

			map[row][col] = type;
		}

		for (i=0; i<8; i++)
		{
			for (j=0; j<8; j++)
			{
				if (map[i][j] != 0)
				{
					if (map[i][j] == 1) king(i,j);
					if (map[i][j] == 2) queen(i,j);
					if (map[i][j] == 3) rook(i,j);
					if (map[i][j] == 4) bishop(i,j);
					if (map[i][j] == 5) knight(i,j);
					if (map[i][j] == 6) pawn(i,j);

					//printMap();
				}
			}
		}

		printf("Case #%d: ", z);
		for (i=0; i<8; i++)
		{
			for (j=0; j<8; j++)
			{
				if (map[i][j] != 0) totalMove+=sum[i][j];
			}
		}

		cout << totalMove << endl;
	}
	return 0;
}