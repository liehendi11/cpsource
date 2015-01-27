#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

struct Data
{
	int min, sec, ms;
	string name;
public:
	Data(string, int, int, int);
};

Data::Data(string name1, int min1, int sec1, int ms1)
{
	name = name1;
	min = min1;
	sec = sec1;
	ms = ms1;
}

vector<Data> racers;

bool f(Data a, Data b)
{
	if (a.min < b.min) return true;
	else
	if (a.min == b.min)
	{
		if (a.sec < b.sec) return true;
		else
		if (a.sec == b.sec)
		{
			if (a.ms < b.ms) return true;
			else
				if (a.ms == b.ms)
				{
					return (transform(a.name.begin(), a.name.end(), a.name.begin(), ::tolower) < transform(b.name.begin(), b.name.end(), b.name.begin(), ::tolower));
				}
		}
	}

	return false;
}

int main()
{
	int tc;
	int z=1;

	string inName;
	int inMin, inSec, inMs;
	string dum;

	while (scanf("%d", &tc) != EOF)
	{
		racers.clear();
		for (int i=0; i<tc; i++)
		{
			cin >> inName;
			scanf("%d%d%d", &inMin, &inSec, &inMs);
			getline(cin, dum);
			racers.push_back(Data (inName, inMin, inSec, inMs));
		}
		
		sort(racers.begin(), racers.end(), f);

		// printf("Row %d\n", z);
		int x = 2;
		for (int i=0; i<racers.size(); i++)
		{
			if (x%2==0)
			{
				printf("Row %d\n", x/2);
			}
			x+=1;
			printf("%s\n", racers[i].name.c_str());
		}
		printf("\n");

		z++;
	}
	return 0;
}