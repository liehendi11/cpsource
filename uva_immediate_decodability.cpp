#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

vector<string> s;
bool dp[4100][12];

void reset()
{
	s.clear();
	memset(dp, false, sizeof(dp));
}

void process()
{
	bool yes = true;
	int binaryRep = 0;
	for (int i=0; i<s.size(); i++)
	{
		binaryRep = 0;
		for (int j=0; j<s[i].length(); j++)
		{
			binaryRep = (binaryRep*2)+(s[i][j]-48);
			if (dp[binaryRep][j+1])
			{
				yes=false;
				break;
			}
		}

		dp[binaryRep][s[i].length()] = true;
	}

	if (yes) printf("is immediately decodable\n");
	else
		printf("is not immediately decodable\n");
}

bool f(string a, string b)
{
	if (a.length() < b.length()) return true;
	else
		if (a.length() == b.length()) return (a<b);
	else
		return false;
}

int main()
{
	reset();
	string x;
	int z=1;
	while (!cin.eof())
	{
		getline(cin, x);
		if (x == "9")
		{
			printf("Set %d ", z);
			sort(s.begin(), s.end(), f);
			process();
			z+=1;
			reset();
		}
		else
			s.push_back(x);
	}
	return 0;
}