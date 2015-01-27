#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

//suffix array construction

int suffix[120002];
int ranking[120002];
int lengthSum[20002];
int n,k;
string str;
vector<string> dict;
string qStr;

int getRank(int x)
{
	if (x<n) return ranking[x];
	else
		return 0;
}

bool compSuffix(int x, int y)
{
	if (getRank(x) < getRank(y)) return true;
	if ((getRank(x) == getRank(y)) && (getRank(x+k) < getRank(y+k))) return true;
	if ((getRank(x) == getRank(y)) && (getRank(x+k) == getRank(y+k)) && (x>y)) return true;
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
	str="";
	for (int i=0; i<dict.size(); i++) str+=dict[i];
	
	int tempRank[120002];
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

int comparePrefix(int pos)
{
	for (int i=0; i<qStr.length(); i++)
	{
		if (qStr[i] != str[suffix[pos] +i])
		{
			if (qStr[i] > str[suffix[pos]+i]) return 1;
			else
				return -1;
		}
	}

	return 0;
}

void computeLengthSum()
{
	int x=0;
	for (int i=0; i<dict.size(); i++)
	{
		lengthSum[i] = x;
		x+= dict[i].length();
	}
}

int findLowerBound(int x)
{
	int mn=0;
	int mx = dict.size()-1;
	int res=0;
	while (mn<=mx)
	{
		int mid = (mn+mx)/2;
		if (lengthSum[mid] <= x)
		{
			res = mid;
			mn = mid+1;
		}
		else
			mx = mid-1;
	}

	return res;
}

bool compResult(int x, int y)
{
	if (dict[x].length() < dict[y].length()) return true;
	if ((dict[x].length() == dict[y].length()) && (ranking[lengthSum[x]] < ranking[lengthSum[y]])) return true;
	if ((dict[x].length() == dict[y].length()) && (ranking[lengthSum[x]] == ranking[lengthSum[y]]) && (x<y)) return true;
	return false;
}

void processQuery()
{
	int mn=0, mx=n-1;
	int lowerBound = -1;
	while (mn <= mx)
	{

		int mid = (mn+mx)/2;
		int temp = comparePrefix(mid);

		// printf("%d %d %d == %d\n", mn, mid, mx, temp);

		if (temp == 0)
		{
			lowerBound = mid;
			mx = mid-1;
		}
		else
			if (temp==-1) mx=mid-1;
			else
				mn = mid+1;
	}

	if (lowerBound == -1)
	{
		printf("-1\n");
		return;
	}

	mn=0;
	mx=n-1;
	int upperBound = -1;
	while (mn <= mx)
	{
		int mid = (mn+mx)/2;
		int temp = comparePrefix(mid);

		// printf("%d %d %d == %d\n", mn, mid, mx, temp);

		if (temp == 0)
		{
			upperBound = mid;
			mn = mid+1;
		}
		else
			if (temp==-1) mx=mid-1;
			else
				mn = mid+1;
	}

	//done finding upper lower bound, do processing
	int z=0;
	unordered_set<int> wordFlag;
	vector<int> res;
	for (int i=lowerBound; i<=upperBound; i++)
	{
		int word = findLowerBound(suffix[i]);
		if (wordFlag.count(word) ==0)
		{
			wordFlag.insert(word);
			res.push_back(word);
			// printf("%d %s\n", word, dict[word].c_str());
		}
	}

	sort(res.begin(), res.end(), compResult);

	for (int i=0; i<min((int) res.size(), 10); i++)
	{
		if (i>0) printf(" ");
		printf("%d", res[i]+1);
	}

	printf("\n");
}

void OPEN(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main()
{
	OPEN("top_10");
	int tc, q;
	scanf("%d", &tc);
	string inp;
	dict.clear();

	for (int i=0; i<tc; i++)
	{
		cin >> inp;
		inp += "$";

		dict.push_back(inp);
	}

	constructSuffixArray();
	computeLengthSum();

	scanf("%d", &q);
	for (int i=0; i<q; i++)
	{
		cin >> qStr;
		// printf("%d\n", comparePrefix(34));
		// printf("%d\n", comparePrefix(35));
		processQuery();
	}

	return 0;
}