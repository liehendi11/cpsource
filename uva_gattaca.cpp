#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int suffix[1002];
int ranking[1002];
string str;
int n,k;

int getRank(int x)
{
	if (x < n) return ranking[x];
	else
		return 0;
}

bool compSuffixRank(int x, int y)
{
	if (getRank(x) < getRank(y)) return true;
	if ((getRank(x) == getRank(y)) && (getRank(x+k) < getRank(y+k))) return true;
	if ((getRank(x) == getRank(y)) && (getRank(x+k) == getRank(y+k)) && (x>y)) return true;
	return false;
}

void constructSuffixArray()
{
	k=0;
	n=str.length();
	int tempRank[1002];

	for (int i=0; i<n; i++)
	{
		suffix[i] = i;
		ranking[i] = str[i];
		tempRank[i] = 0;
	}

	for (k=1; k<n; k*=2)
	{
		sort(suffix, suffix+n, compSuffixRank);

		int x=0;
		tempRank[0] = 0;

		for (int i=1; i<n; i++)
		{
			if ((getRank(suffix[i]) != getRank(suffix[i-1])) || (getRank(suffix[i]+k) != getRank(suffix[i-1]+k))) x+=1;
			tempRank[i] = x;
		}

		for (int i=0; i<n; i++)
		{
			ranking[suffix[i]] = tempRank[i];
		}

		if (ranking[n-1] == n-1) break;
	}
}

int commonPrefix(int x, int y)
{
	int ctr=0;
	for (int i=0; i<max(n-suffix[x], n-suffix[y]); i++)
	{
		if (str[suffix[x] + i] == str[suffix[y]+i]) ctr+=1;
		else
			break;
	}

	return ctr;
}

string getSuffixRanged(int x, int range)
{
	string s = "";
	for (int i=x; i<x+range; i++)
	{
		s+= str[i];
	}

	return s;
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

int countOccurences(int x, int length)
{
	int ctr = 0;
	for (int i=0; i<=(n-length); i++)
	{
		bool yes=true;

		for (int j=0; j<length; j++)
		{
			if (str[x+j] != str[i+j])
			{
				yes=false;
				break;
			}
		}

		if (yes) ctr+=1;
	}

	return ctr;
}

void findLRS()
{
	int mx=0;
	// int ctr=0;
	int pos=-1;
	// string tempMax;

	for (int i=0; i<n-1; i++)
	{
		int curPrefixLength = commonPrefix(i, i+1);

		// printf("%d %d : %s %s %d %s\n", suffix[i], suffix[i+1], getSuffix(suffix[i]).c_str(), getSuffix(suffix[i+1]).c_str(), curPrefixLength, getSuffixRanged(suffix[i], curPrefixLength).c_str());

		if (curPrefixLength> mx)
		{
			mx = curPrefixLength;
			pos = suffix[i];
		}
	}

	if (mx>0)
	{
		for (int i=0; i<mx; i++) printf("%c", str[pos+i]);

		printf(" %d\n", countOccurences(pos, mx));
	}
	else
		printf("No repetitions found!\n");
	
}

int main()
{
	int tc;
	scanf("%d", &tc);
	getchar();
	for (int z=1; z<=tc; z++)
	{
		getline(cin, str);
		str+="$";
		constructSuffixArray();

		findLRS();
	}
	return 0;
}