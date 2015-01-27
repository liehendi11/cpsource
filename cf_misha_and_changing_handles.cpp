#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<pair<string, string> > handles;

int main()
{
	int q;
	scanf("%d", &q);

	string old, nw;

	for (int i=0; i<q; i++)
	{
		cin >> old >> nw;

		bool found=false;
		for (int i=0; i<handles.size(); i++)
		{
			if (handles[i].second == old)
			{
				handles[i].second = nw;
				found=true;
			}
		}

		if (!found) handles.push_back(pair<string, string> (old, nw));
	}


	printf("%d\n", (int) handles.size());
	for (int i=0; i<handles.size(); i++)
	{
		printf("%s %s\n", handles[i].first.c_str(), handles[i].second.c_str());
	}
	return 0;
}