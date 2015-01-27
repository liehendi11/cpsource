#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <set>
#include <iostream>
#include <queue>

using namespace std;

struct Data
{
	int combination;
	int steps;
};

string source, dest;
vector<int> keys;
int keysCount;

int convertToInt(string a)
{
	int x = 0;
	for (int i=0; i<a.length(); i++)
	{
		x=(x*10)+(a[i]-48);
	}

	return x;
}

int addCombination(int cur, int add)
{
	int temp = (cur+add) % 10000;
	return temp;
}

void bfs()
{
	Data first;
	first.combination = convertToInt(source);
	first.steps = 0;

	set<int> visited;
	visited.insert(first.combination);

	queue<Data> q;
	q.push(first);

	bool found=false;
	int res;

	int destInt = convertToInt(dest);
	while (!q.empty())
	{
		Data cur = q.front();
		q.pop();

		if (cur.combination == destInt)
		{
			found=true;
			res = cur.steps;
			break;
		}

		for (int i=0; i<keys.size(); i++)
		{
			int newCombination = addCombination(cur.combination, keys[i]);
			if (visited.count(newCombination) ==0)
			{
				visited.insert(newCombination);
				Data newData;
				newData.combination = newCombination;
				newData.steps = cur.steps+1;
				q.push(newData);
			}
		}
	}

	if (!found) printf("Permanently Locked\n");
	else
		printf("%d\n", res);
	
}

int main()
{
	source = ""; dest = ""; keysCount=0;

	int z=1;
	while (true)
	{
		keys.clear();
		cin >> source >> dest >> keysCount;
		getchar();

		if ((source == "0") && (dest == "0") && (keysCount == 0)) break;

		string in;
		for (int i=0; i<keysCount; i++)
		{
			cin >> in;
			keys.push_back(convertToInt(in));
			getchar();
		}

		printf("Case %d: ", z);
		z++;
		bfs();
	}
	return 0;
}