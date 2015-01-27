#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

void constructPartialMatchTable(const string &pat, vector<int> &matchTable)
{
	//initiate
	matchTable.push_back(0);
	int len = 0;
	int i=1;

	while (i< pat.length())
	{
		if (pat[i] == pat[len])
		{
			len +=1;
			matchTable.push_back(len);
			i+=1;
		}
		else
		{
			if (len != 0) len = matchTable[len-1]; //learn this again later
			else
			{
				len = 0;
				matchTable.push_back(0);
				i+=1;
			}
		}
	}
}

void OPEN(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void kmp(const string &search, const string &pat)
{
	//construct partial match table
	vector<int> matchTable;
	constructPartialMatchTable(pat, matchTable);

	int posSearch = 0;
	int posPattern = 0;
	int maxLength = 0;

	while (posSearch < search.length()) //traverse to the end of search string
	{
		if (posPattern == pat.length()) //reached the end of pattern
		{
			maxLength = max(maxLength, posPattern);
			posPattern = matchTable[posPattern-1]; //revert to next comparison, uses partial match table
		}
		else
			if (search[posSearch] != pat[posPattern])
			{
				//comparison broke down
				maxLength = max(maxLength, posPattern);

				if (posPattern == 0) //fail in the beginning
					posSearch+=1;
				else
					posPattern = matchTable[posPattern-1]; //revert to next comparison
			}
			else
			{
				posPattern+=1;
				posSearch+=1;
				//if matches, continue
			}
	}

	maxLength = max(maxLength, posPattern);

	for (int i=maxLength-1; i>=0; i--)
	{
		printf("%c", pat[i]);
	}
	printf("\n");
}

int main()
{
	// OPEN("secret_word");
	int tc;
	scanf("%d", &tc);
	for (int z=1; z<=tc; z++)
	{
		string inp;
		cin >> inp;

		string reverse = "";
		for (int i=inp.length()-1; i>=0; i--)
			reverse += inp[i];

		kmp(reverse, inp);
	}
	return 0;
}