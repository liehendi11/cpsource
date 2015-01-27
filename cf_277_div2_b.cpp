#include <stdio.h>
#include <stdlib.h>
#include <cstring>

using namespace std;

bool a[102][102];
bool b[102][102];
bool row[102], col[102];
int n,m;

int main()
{
	scanf("%d%d", &n, &m);

	int inp;
	memset(a, false, sizeof(a));
	memset(b, false, sizeof(b));
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			scanf("%d", &inp);
			if (inp == 1) b[i][j] = true;
			else
				b[i][j] = false;
		}
	}


	memset(row, true, sizeof(row));
	memset(col, true, sizeof(col));
	//find all
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			row[i] = row[i] & b[i][j];
			col[j] = col[j] & b[i][j];
		}
	}

	bool isTrue = true;
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			if (b[i][j])
			{
				if ((row[i]) || (col[j]))
				{
					if (row[i] && col[j])
					{
						a[i][j]=true;
					}
				}
				else
					isTrue=false;
			}
		}
	}

	if (isTrue)
	{
		printf("YES\n");
		for (int i=0; i<n; i++)
		{
			for (int j=0; j<m; j++)
			{
				if (a[i][j]) printf("1");
				else
					printf("0");
				if (j<(m-1)) printf(" ");
			}

			printf("\n");
		}
	}
	else
		printf("NO\n");

	return 0;
}