#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

vector<int> generatePartialMatchTable(const string &s)
{
	vector<int> partialMatch;

	vector<string> properSuffixes;
	vector<string> properPrefixes;

	for (int i=0; i<s.length(); i++)
	{
		int mxLength = 0;
		for (int j=0; j<properPrefixes.size(); j++)
		{
			if (properPrefixes[j] == properSuffixes[j])
			{
				mxLength = properPrefixes[j].length();
				break;
			}
		}

		partialMatch.push_back(mxLength);

		if (i<s.length()-1)
		{
			for (int j=0; j<properSuffixes.size(); j++)
				properSuffixes[j] += s[i+1];
			properSuffixes.push_back(s.substr(i+1, 1));

			properPrefixes.insert(properPrefixes.begin(), s.substr(0, i+1));	
		}
	}
	return partialMatch;
}

vector<int> computePartialTable(const string &x)
{
	vector<int> table (1,0);
	//table.push_back(0);
	int len = 0;
	int i = 1;

	while (i<x.length())
	{
		if (x[i] == x[len])
		{
			len+=1;
			table.push_back(len);
			i+=1;
		}
		else
		{
			if (len != 0) len = table[len-1];
			else
			{
				len=0;
				table.push_back(len);
				i+=1;
			}
		}
	}

	return table;
}

void kmp(const string &search, const string &pattern)
{
	vector<int> matchTable = computePartialTable(pattern);

	int posSearch = 0;
	int posPattern = 0;

	while (posSearch < search.length())
	{
		if (posPattern == pattern.length())
		{
			printf("Match found at position %d\n", posSearch-posPattern);
			posPattern = matchTable[posPattern-1];
		}
		else
		if (search[posSearch] != pattern[posPattern])
		{
			if (posPattern == 0) posSearch+=1;
			else
			posPattern = matchTable[posPattern-1];
		}
		else
		{
			posSearch+=1;
			posPattern+=1;
		}
	}

	if (posPattern == pattern.length())
	{
		printf("Match found at position %d\n", posSearch-posPattern);
	}
}

int main()
{
	kmp("aaa bbb", "bbb");
	// generatePartialMatchTable("abababca");
	return 0;
}