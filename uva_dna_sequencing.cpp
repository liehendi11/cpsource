#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int suffix[602];
int ranking[602];
string str1, str2, combStr;
int n,k;

int getRank(int x)
{
	if (x < n) return ranking[x];
	else
		return 0;
}

bool compSortedArr(int x, int y)
{
	if (getRank(x) < getRank(y)) return true;
	if ((getRank(x) == getRank(y)) && (getRank(x+k) < getRank(y+k))) return true;
	if ((getRank(x) == getRank(y)) && (getRank(x+k) == getRank(y+k)) && (x > y)) return true;
	return false;
}

string getSuffix(int x)
{
	string s = "";
	for (int i=x; i<n; i++)
	{
		s+= combStr[i];
	}

	return s;
}

void constructSuffixArray()
{
	int tempRank[602];
	combStr = str1+str2;
	n = combStr.length();

	memset(ranking, 0, sizeof(ranking));

	//initialize rank
	for (int i=0; i<n; i++)
	{
		ranking[i] = combStr[i];
		tempRank[i] = 0;
		suffix[i] = i;
	}

	for (k=1; k<n; k=k*2)
	{
		sort(suffix, suffix+n, compSortedArr);

		int x=0;
		tempRank[0] = 0;
		for (int i=1; i<n; i++)
		{
			if ((getRank(suffix[i]) != getRank(suffix[i-1])) || (getRank(suffix[i]+k) != getRank(suffix[i-1]+k))) x+=1;
			tempRank[i] = x;
		}

		for (int i=0; i<n; i++)
			ranking[suffix[i]] = tempRank[i];

		if (ranking[n-1] == n-1) break;
	}
}

int getColor(int x)
{
	if (x < str1.length()) return 1;
	else
		return 2;
}

string getSuffixRanged(int x, int range)
{
	string s = "";
	for (int i=x; i<x+range; i++)
	{
		s+= combStr[i];
	}

	return s;
}

void findLCS()
{
	vector<pair<int, int> > res;
	int mx=0;
	unordered_set<string> resSet;
	resSet.clear();

	for (int i=0; i<n; i++)
	{
		for (int l=i+1; l<n; l++)
		{
			int ctr=0;
			for (int j=0; j<max(n-suffix[i], n-suffix[l]); j++)
			{
				if ((combStr[suffix[i]+j] == combStr[suffix[l]+j]) && (getColor(suffix[i]+j) != getColor(suffix[l]+j))) ctr+=1;
				else
					break;
			}
	
			// printf("%d %d %s %d %s\n", ctr, suffix[i], getSuffix(suffix[i]).c_str(), suffix[l], getSuffix(suffix[l]).c_str());
	
			if (ctr > mx)
			{
				mx = ctr;
				res.clear();
				resSet.clear();
				res.push_back(pair<int, int> (suffix[i], ctr));
				resSet.insert(getSuffixRanged(suffix[i], ctr));
			}
			else
				if ((ctr==mx) && (mx!=0))
				{
					string temp = getSuffixRanged(suffix[i], ctr);
					if (resSet.count(temp) ==0)
					{
						res.push_back(pair<int, int> (suffix[i], ctr));
						resSet.insert(getSuffixRanged(suffix[i], ctr));
					}
				}
		}
	}

	if (res.size() > 0)
	{
		for (int i=0; i<res.size(); i++)
		{
			printf("%s\n", getSuffixRanged(res[i].first, res[i].second).c_str());
		}
	}
	else
		printf("No common sequence.\n");
}

void OPEN(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main()
{
	// OPEN("dna_sequencing");
	int z=0;
	while (!cin.eof())
	{
		if (z>0) getchar();

		getline(cin, str1);
		getline(cin, str2);
		

		z++;
		constructSuffixArray();

		// for (int i=0; i<n; i++)
		// {
		// 	printf("%d %s\n", suffix[i], getSuffix(suffix[i]).c_str());
		// }

		if (z>1) printf("\n");
		findLCS();


	}
	return 0;
}