#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

char puzzle[102][102];
int n;
vector<string> queries;
vector<vector<int> > matchTables;

class MatrixSub
{
public:
	string s;
	int dx, dy;
	int sx, sy;
	MatrixSub()
	{
		s = "";
		dx = 0; dy=0;
		sx = 0; sy = 0;
	}

	MatrixSub(int ssx, int ssy, int adx, int ady)
	{
		s = "";
		dx = adx; dy = ady;
		sx = ssx; sy = ssy;
	}
};

void constructPartialMatchTable(const string &pat, vector<int> &matchTable)
{
	matchTable.push_back(0);
	int len=0;
	int i=0;

	while (i<pat.length())
	{
		if (pat[i] == pat[len])
		{
			len++;
			matchTable.push_back(len);
			i++;
		}
		else
		{
			if (len != 0) len = matchTable[len-1];
			else
			{
				len = 0;
				matchTable.push_back(len);
				i++;
			}
		}
	}
}

void preprocess(vector<string> &queries, vector<vector<int> > &matchTables)
{
	for (int i=0; i<queries.size(); i++)
	{
		matchTables.push_back(vector<int> ());
		constructPartialMatchTable(queries[i], matchTables[i]);
	}
}

void generateSubstrings(char (&puzzle) [102][102], int size, vector<MatrixSub> &puzzleSubs)
{
	//vertical
	for (int j=0; j<size; j++)
	{
		MatrixSub sub(0,j,1,0);
		for (int i=0; i<size; i++)
		{
			sub.s += puzzle[i][j];
		}
		puzzleSubs.push_back(sub);
	}

	//horizontal
	for (int i=0; i<size; i++)
	{
		MatrixSub sub(i,0,0,1);
		for (int j=0; j<size; j++)
		{
			sub.s += puzzle[i][j];
		}
		puzzleSubs.push_back(sub);
	}

	//horizontal reversed
	for (int i=0; i<size; i++)
	{
		MatrixSub sub(i,size-1,0,-1);
		for (int j=size-1; j>=0; j--)
		{
			sub.s += puzzle[i][j];
		}
		puzzleSubs.push_back(sub);
	}

	//diagonal left top to right bottom, + reverse
	for (int i=0; i<size; i++)
	{
		MatrixSub sub(i, 0, 1, 1);
		for (int k=0; k+i < size; k++)
		{
			sub.s += puzzle[i+k][k];
		}
		puzzleSubs.push_back(sub);
		
	}

	for (int j=0; j<size; j++)
	{
		MatrixSub sub(0, j, 1, 1);
		for (int k=0; k+j < size; k++)
		{
			sub.s += puzzle[k][k+j];
		}
		puzzleSubs.push_back(sub);
	}
}

int main()
{

	return 0;
}