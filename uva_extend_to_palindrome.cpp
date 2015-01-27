#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void computePartialMatchTable(const string &s, vector<int> &partialMatch)
{
	//vector<int> partialMatch(1,0);
	partialMatch.push_back(0);
	int i=1;
	int len=0;

	while (i<s.length())
	{
		if (s[i] == s[len])
		{
			len+=1;
			partialMatch.push_back(len);
			i+=1;
		}
		else
		{
			if (len!=0) len = partialMatch[len-1];
			else
			{
				len = 0;
				partialMatch.push_back(len);
				i+=1;
			}
		}
	}
}

void kmp(const string &s, const string &pat)
{
	vector<int> partialMatch;
	computePartialMatchTable(pat, partialMatch);

	int posSearch = 0;
	int posPattern = 0;
	int maxLength = 0;

	while (posSearch < s.length())
	{
		if (posPattern == pat.length())
		{
			// maxLength = max(posPattern, maxLength);
			posPattern = partialMatch[posPattern-1];
		}
		else
			if (s[posSearch] != pat[posPattern])
			{
				// maxLength = max(posPattern, maxLength);
				if (posPattern == 0) posSearch+=1;
				else
					posPattern = partialMatch[posPattern-1];
			}
			else
			{
				posSearch+=1;
				posPattern+=1;
			}
	}

	maxLength = max(posPattern, maxLength);

	// printf("%d\n", maxLength);

	string res = s+pat.substr(maxLength);
	printf("%s\n", res.c_str());
}

void OPEN(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main()
{
	// OPEN("extend_to_palindrome");
	while (!cin.eof())
	{
		string inp;
		getline(cin, inp);

		string rev = "";
		for (int i=inp.length()-1; i>=0; i--)
		{
			rev += inp[i];
		}

		kmp(inp, rev);
	}
	return 0;
}