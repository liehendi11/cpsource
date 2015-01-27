#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int suffix[5002];
int ranking[5002];
int n,k;
string str;

int getRank(int x)
{
	if (x<n) return ranking[x];
	return 0;
}

bool compSuffix(int x, int y)
{
	if (getRank(x) < getRank(y)) return true;
	if ((getRank(x) == getRank(y)) && (getRank(x+k) < getRank(y+k))) return true;
	if ((getRank(x) == getRank(y)) && (getRank(x+k) == getRank(y+k)) && (x<y)) return true;
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

void constructSuffixArray()
{
	int tempRank[5002];
	n = str.length();

	for (int i=0; i<n; i++)
	{
		suffix[i] = i;
		ranking[i] = str[i];
		tempRank[i] = 0;
	}

	for (k=1; k<n; k*=2)
	{
		sort(suffix, suffix+n, compSuffix);

		int x = 0;
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

	// for (int i=0; i<n; i++)
	// {
	// 	printf("%d %d %s\n", i, suffix[i], getSuffix(suffix[i]).c_str());
	// }
}

void computeLCP()
{
	int mx=0;

	for (int i=0; i<n-1; i++)
	{
		int ctr=0;
		for (int j=0; j<max(n-suffix[i], n-suffix[i+1]); j++)
		{
			if (str[suffix[i]+j] == str[suffix[i+1]+j]) ctr+=1;
			else
				break;
		}

		if (ctr > mx) mx = ctr;
	}

	printf("%d\n", mx);
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
		computeLCP();

	}
	return 0;
}