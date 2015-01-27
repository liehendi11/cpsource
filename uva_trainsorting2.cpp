#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

struct Data
{
	int minWeight, maxWeight;
	int length;
};

vector<Data> lists;
vector<int> numbers;

void generateLIS()
{
	int mxLength = 0;
	for (int i=0; i<numbers.size(); i++)
	{
		int mx=0;
		Data temp;
		for (int j=0; j<i; j++)
		{
			if ((numbers[i] < lists[j].minWeight) && (lists[j].length > mx))
			{
				mx = lists[j].length;
				temp = lists[j];
			}

			if ((numbers[i] > lists[j].maxWeight) && (lists[j].length > mx))
			{
				mx = lists[j].length;
				temp = lists[j];
			}
		}

		if (mx==0)
		{
			Data newData;
			newData.minWeight = numbers[i];
			newData.maxWeight = numbers[i];
			newData.length = 1;

			mxLength = max(mxLength, newData.length);
			lists.push_back(newData);
		}
		else
		{
			if (numbers[i] < temp.minWeight)
			{
				temp.minWeight = numbers[i];
			}
			else
				temp.maxWeight = numbers[i];
			temp.length+=1;

			mxLength = max(mxLength, temp.length);

			lists.push_back(temp);
		}
	}

	printf("%d\n", mxLength);
}

void reset()
{
	numbers.clear();
	lists.clear();
}

int main()
{
	int tc,n,temp;
	scanf("%d", &tc);

	for (int z=1; z<=tc; z++)
	{
		scanf("%d", &n);

		numbers.clear();
		lists.clear();
		//prevIndexes.clear();

		for (int i=0; i<n; i++)
		{
			scanf("%d", &temp);
			numbers.push_back(temp);
		}

		generateLIS();
	
	}
	return 0;
}