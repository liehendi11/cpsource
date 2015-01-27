#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int suffix[20];
int rank1[100];
int tempRank[20];
string str;
int n, k;

bool sortRankedArray(int x, int y)
{
	if (rank1[x] < rank1[y]) return true;
	if ((rank1[x] == rank1[y]) && (rank1[x+k] < rank1[y+k])) return true;
	return false;
}

string getSuffix(int x)
{
	string s = "";
	for (int i=x; i<n; i++)
	{
		s+= str[i];
	}

	return s;
}

void printSuffix()
{
	for (int i=0; i<n; i++)
	{
		printf("%d %s %d %d %d\n", suffix[i], getSuffix(suffix[i]).c_str(), rank1[suffix[i]], rank1[suffix[i]+k], tempRank[i]);
	}
	printf("************************\n");
}

void constructSuffixArray()
{
	memset(rank1, 0, sizeof(rank1));

	n=str.length();
	k=0;

	//init rank
	for (int i=0; i<n; i++)
	{
		suffix[i] = i;
		tempRank[i] = 0;
		rank1[i] = str[i];
		// rank1[i+k] = str[i];
	}

	// printSuffix();

	for (k=1; k<n; k = k*2)
	{
		printSuffix();
		sort(suffix, suffix+n, sortRankedArray);

		//ranking process
		int x=0;
		tempRank[0] = 0;
		for (int i=1; i<n; i++)
		{
			if ((rank1[suffix[i]] != rank1[suffix[i-1]]) || (rank1[suffix[i]+k] != rank1[suffix[i-1] +k])) x+=1;
			tempRank[i] = x;
		}

		for (int i=0; i<n; i++)
		{
			rank1[suffix[i]] = tempRank[i];
		}

		if (rank1[n-1] == n-1) break;
	}
	printSuffix();

	for (int i=0; i<n; i++)
	{
		printf("%d %s\n", suffix[i], getSuffix(suffix[i]).c_str());
	}
}

int main()
{
	getline(cin, str);
	// getline(cin, str2);
	constructSuffixArray();
	return 0;
}