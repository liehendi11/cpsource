#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
#include <string.h>

using namespace std;

int s,m;
string smallest, largest;

void findSmallest()
{
	int residue = s;
	int res[102];
	memset(res,-1, sizeof(res));
	bool canBeConverted = true;

	for (int i=m-1; i>=0; i--)
	{
		if (i==0) //first digit
		{
			if ((residue == 0) && (m>1)) canBeConverted=false;
			else
				if (residue>9) canBeConverted=false;
			else
				res[i]=residue;
		}
		else
		{
			if (residue>9)
			{
				residue-=9;
				res[i] = 9;
			}
			else
				if (residue>1)
				{
					res[i] = (residue-1);
					residue = 1;
				}
				else
					res[i] = 0;
		}
	}

	if (canBeConverted)
	{
		for (int i=0; i<m; i++) printf("%d", res[i]);
	}
	else
		printf("-1");
}

void findLargest()
{
	int residue = s;
	int res[102];

	memset(res,-1, sizeof(res));
	bool canBeConverted = true;

	for (int i=0; i<m; i++)
	{
		if (i==m-1)
		{
			if (residue < 0) canBeConverted=false;
			else
				if (residue>9) canBeConverted=false;
			else
				res[i]=residue;
		}
		else
		{
			if (residue>9)
			{
				residue-=9;
				res[i] = 9;
			}
			else
			{
				res[i] = residue;
				residue=0;
			}
		}
	}

	if ((canBeConverted) && !((m>1) && (s==0)))
	{
		for (int i=0; i<m; i++)
		{
			printf("%d", res[i]);
		}
	}
	else
		printf("-1");
}

int main()
{
	scanf("%d%d", &m, &s);
	smallest = "-1";
	largest = "-1";

	findSmallest();
	printf(" ");
	findLargest();
	printf("\n");
	return 0;
}