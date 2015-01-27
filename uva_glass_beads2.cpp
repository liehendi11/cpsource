#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int ranking[10002];
int suffix[10002];
int n,k;
string str;

int getRank(int x)
{
	return ranking[x%n];
}

bool compSuffix(int x, int y)
{
	if (getRank(x) < getRank(y)) return true;
	if ((getRank(x) == getRank(y)) && (getRank(x+k) < getRank(y+k))) return true;
	if ((getRank(x) == getRank(y)) && (getRank(x+k) == getRank(y+k)) && (x<y)) return true;
	return false;
}

int findRankBond(int x, int mx)
{
	int mn = 0;
	int res = 0;
	
	while (mn <= mx)
	{
		int mid = (mn+mx)/2;
		if (ranking[suffix[mid]] == x)
		{
			res = mid;
			mn = mid+1;
		}
		else
			if (ranking[suffix[mid]] < x) mn = mid+1;
		else
			mx = mid-1;
	}

	return res;
}

string getSuffix(int x)
{
	string res = "";
	for (int i=0; i<n; i++)
	{
		res += str[(x+i)%n];
	}

	return res;
}

void constructSuffixArray()
{
	int tempRank[10002];
	n=str.length();
	int limit=n-1;

	for (int i=0; i<n; i++)
	{
		ranking[i] = str[i];
		suffix[i] = i;
		tempRank[i] = 0;
	}



	for (k=1; k<n; k*=2)
	{
		sort(suffix, suffix+limit+1, compSuffix);

		int x=0;
		tempRank[0] = 0;
		for (int i=1; i<=limit; i++)
		{
			if ((getRank(suffix[i]) != getRank(suffix[i-1])) || (getRank(suffix[i]+k) != getRank(suffix[i-1]+k))) x+=1;
			tempRank[i] = x;
		}

		printf("************ %d\n", limit);

		for (int i=0; i<=limit; i++)
		{
			ranking[suffix[i]] = tempRank[i];
			printf("%d %d %s\n", suffix[i], ranking[suffix[i]], getSuffix(suffix[i]).c_str());
		}

		limit = findRankBond(ranking[suffix[0]], limit);

		if (limit == 0) break;
	}

	printf("%d\n", suffix[0]+1);
}

int main()
{
	int tc;
	scanf("%d", &tc);
	getchar();
	for (int z=1; z<=tc; z++)
	{
		getline(cin, str);

		constructSuffixArray();
	}
	return 0;
}