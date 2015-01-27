#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class Data
{
public:
	int height, width;
	Data (int x, int y)
	{
		height = x;
		width = y;
	}
};

vector<Data> buildings;
int n;

void compute(int tc)
{
	vector<Data> increasing;
	increasing.push_back(Data (buildings[0].height, buildings[0].width));
	int mxWidth = buildings[0].width;

	// printf("Increasing\n");
	for (int i=1; i<buildings.size(); i++)
	{
		int prevWidth = 0;
		for (int j=0; j<i; j++)
		{
			if ((increasing[j].width > prevWidth) && (increasing[j].height < buildings[i].height)) prevWidth = increasing[j].width;
		}

		prevWidth += buildings[i].width;
		increasing.push_back(Data (buildings[i].height, prevWidth));
		// printf("%d %d\n", buildings[i].height, prevWidth);
		mxWidth = max(prevWidth, mxWidth);
	}

	vector<Data> decreasing;
	decreasing.push_back(Data (buildings[0].height, buildings[0].width));
	int mnWidth = buildings[0].width;

	// printf("Decreasing\n");
	for (int i=1; i<buildings.size(); i++)
	{
		int prevWidth = 0;
		for (int j=0; j<i; j++)
		{
			if ((decreasing[j].width > prevWidth) && (decreasing[j].height > buildings[i].height)) prevWidth = decreasing[j].width;
		}

		prevWidth += buildings[i].width;
		decreasing.push_back(Data (buildings[i].height, prevWidth));
		// printf("%d %d\n", buildings[i].height, prevWidth);

		mnWidth = max(prevWidth, mnWidth);
	}

	if (mxWidth >= mnWidth) printf("Case %d. Increasing (%d). Decreasing (%d).\n", tc, mxWidth, mnWidth);
	else
		printf("Case %d. Decreasing (%d). Increasing (%d).\n", tc, mnWidth, mxWidth);
}

int main()
{
	int tc;
	scanf("%d", &tc);

	for (int z=1; z<=tc; z++)
	{
		buildings.clear();
		int x;

		scanf("%d", &n);
		for (int i=0; i<n; i++)
		{
			scanf("%d", &x);
			buildings.push_back(Data (x, 0));	
		}
		
		for (int i=0; i<n; i++)
		{
			scanf("%d", &x);
			buildings[i].width = x;
		}

		compute(z);
	}
	return 0;
}