#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>

using namespace std;

typedef vector<pair<int, int> > vc;

struct Data
{
	bool col[16];
	bool diag[34];
	string path="";
};

int grid[16][16];
int n;

void reset()
{
	for (int i=0; i<16; i++)
	{
		for (int j=0; j<16; j++)
		{
			grid[i][j] = 0;
		}
	}
}

bool isColliding(pair<int, int> pos, int x, int y)
{
	if (x == pos.first) return true;
	if (y == pos.second) return true;
	if (abs(pos.first - x) == abs(pos.second-y)) return true;

	return false;
}

bool isValidPosition(vc previous, int x, int y)
{
	if (grid[x][y] == -1) return false;
	for (int i=0; i<previous.size(); i++)
	{
		if (isColliding(previous[i], x, y)) return false;
	}

	return true;
}

int find(int row, vc previous)
{
	if (row == n) return 1;

	int res = 0;

	for (int i=0; i<n; i++)
	{
		if (isValidPosition(previous, row, i))
		{
			vc next = previous;
			next.push_back(pair<int, int> (row,i));
			res+= find(row+1, next);
		}
	}

	return res;
}

int find2(int row, Data cur)
{
	printf("%d %s\n", row, cur.path.c_str());
	if (row == n)
	{
		printf("%s\n", cur.path.c_str());
		return 1;
		
	}

	int res = 0;
	for (int j=0; j<n; j++)
	{
		string temp=cur.path;
		int left = j-row+14;
		int right = j+row+14;
		if ((!cur.col[j]) && (!cur.diag[left]) && (!cur.diag[right]) && (grid[row][j] != -1))
		{
			
			cur.col[j] = true;
			cur.diag[left] = true;
			cur.diag[right] = true;

			cur.path+= ((char) row+48);
			cur.path+= ".";
			cur.path+= ((char) j+48);
			cur.path+= "/";

			res += find2(row+1, cur);
			
			cur.col[j] = false;
			cur.diag[left] = false;
			cur.diag[right] = false;
			
			cur.path = temp;
			//cur.diag[i+row+14] = false;
		}
	}

	return res;
}

int main()
{
	n=-1;
	int z=1;
	while (n!=0)
	{
		scanf("%d", &n);
		if (n==0) break;
		reset();
		getchar();

		char c;

		for (int i=0; i<n; i++)
		{
			for (int j=0; j<n; j++)
			{
				scanf("%c", &c);
				if (c=='*') grid[i][j] = -1;
			}
			getchar();
		}

		Data newData;
		for (int i=0; i<16; i++) newData.col[i] = false;
		for (int i=0; i<34; i++) newData.diag[i] = false;
		newData.path = "";
		printf("Case %d: %d\n", z, find2(0, newData));
		z+=1;
	}
	return 0;
}