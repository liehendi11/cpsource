#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

vector<int> list;
vector<int> numbers;
vector<int> prevIndexes;

int binarySearch(int x)
{
	int mn = 0;
	int mx = list.size()-1;

	int res = 0;

	while (mn <= mx)
	{
		int mid = (mn+mx)/2;

		int midIdx = list[mid];
		if (numbers[midIdx] < x)
		{
			res = mid;
			mn = mid+1;
		}
		else
			mx = mid-1;
	}

	return res;
}

pair<int, int> findPlace(int x, int idx)
{
	if (list.empty())
	{
		list.push_back(idx);
		return pair<int, int> (1,-1);
	}

	int lastIdx = list[list.size()-1];
	int firstIdx = list[0];

	if (x > numbers[lastIdx])
	{
		list.push_back(idx);
		return pair<int, int> (list.size(), lastIdx);
	}

	if (x < numbers[0])
	{
		list[0] = idx;
		return pair<int, int> (1,-1);
	}

	int bound = binarySearch(x);
	list[bound+1] = idx;
	return pair<int, int> (bound+2, list[bound]);
}

void constructLis()
{
	int mx = 0;
	int mxIdx = 0;
	for (int i=0; i<numbers.size(); i++)
	{
		pair<int, int> data = findPlace(numbers[i], i);
		prevIndexes.push_back(data.second);
		
		if (data.first > mx)
		{
			mx=data.first;
			mxIdx = data.second;
		}
	}

	printf("%d\n", mx);
}

int main()
{
	int tc,n,temp;
	scanf("%d", &tc);

	for (int z=1; z<=tc; z++)
	{
		scanf("%d", &n);

		numbers.clear();
		list.clear();
		prevIndexes.clear();

		for (int i=0; i<n; i++)
		{
			scanf("%d", &temp);
			numbers.push_back(temp);
		}

		constructLis();
	
	}
	return 0;
}