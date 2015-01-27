#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

map<char, int> charMap;
vector<string> res;
bool available[12];
int f,m;
set<string> resSet;

void init()
{
	charMap.insert(pair<char, int> ('q', 1)); charMap.insert(pair<char, int> ('a', 1)); charMap.insert(pair<char, int> ('z', 1));
	charMap.insert(pair<char, int> ('w', 2)); charMap.insert(pair<char, int> ('s', 2)); charMap.insert(pair<char, int> ('x', 2));
	charMap.insert(pair<char, int> ('e', 3)); charMap.insert(pair<char, int> ('d', 3)); charMap.insert(pair<char, int> ('c', 3));
	charMap.insert(pair<char, int> ('r', 4)); charMap.insert(pair<char, int> ('f', 4)); charMap.insert(pair<char, int> ('v', 4));
	charMap.insert(pair<char, int> ('t', 4)); charMap.insert(pair<char, int> ('g', 4)); charMap.insert(pair<char, int> ('b', 4));
	charMap.insert(pair<char, int> ('y', 7)); charMap.insert(pair<char, int> ('n', 7)); charMap.insert(pair<char, int> ('j', 7));
	charMap.insert(pair<char, int> ('h', 7)); charMap.insert(pair<char, int> ('u', 7)); charMap.insert(pair<char, int> ('m', 7));
	charMap.insert(pair<char, int> ('i', 8)); charMap.insert(pair<char, int> ('k', 8));
	charMap.insert(pair<char, int> ('o', 9)); charMap.insert(pair<char, int> ('l', 9));
	charMap.insert(pair<char, int> ('p', 10));
}

void reset()
{
	memset(available, true, sizeof(available));
	res.clear();
	resSet.clear();
}

int main()
{
	init();
	while (scanf("%d%d", &f,&m) != EOF)
	{
		reset();
		int x;
		for (int i=0; i<f; i++)
		{
			scanf("%d", &x);
			available[x] = false;
		}

		getchar();
		int mx = 0;
		string inp;

		for (int i=0; i<m; i++)
		{
			bool doable=true;
			cin >> inp;

			for (int j=0; j<inp.length(); j++)
			{
				doable = (doable && available[charMap[inp[j]]]);
			}

			// cout << inp << " " << doable << endl;

			if ((doable) && (inp.length() >= mx))
			{
				if (inp.length() > mx)
				{
					mx = inp.length();
					res.clear();
					resSet.clear();
				}

				if (resSet.count(inp) == 0)
				{
					res.push_back(inp);
					resSet.insert(inp);	
				}
			}
		}

		sort(res.begin(), res.end());

		printf("%d\n", (int) res.size());
		for (int i=0; i<res.size(); i++)
		{
			printf("%s\n", res[i].c_str());
		}
	}
	return 0;
}