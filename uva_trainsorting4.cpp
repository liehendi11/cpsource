#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

vector<int> list;
vector<int> list2;
vector<int> numbers;
vector<int> sizes, sizes2;

//vector<int> prevIndexes;
vector<int> prevIndexes2;

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

int binarySearch2(int x)
{
	int mn = 0;
	int mx = list2.size()-1;

	int res = 0;

	while (mn <= mx)
	{
		int mid = (mn+mx)/2;

		int midIdx = list2[mid];
		if (numbers[midIdx] > x)
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

pair<int, int> findPlace2(int x, int idx)
{
	if (list2.empty())
	{
		list2.push_back(idx);
		return pair<int, int> (1,-1);
	}

	int lastIdx = list2[list2.size()-1];
	int firstIdx = list2[0];

	if (x < numbers[lastIdx])
	{
		list2.push_back(idx);
		return pair<int, int> (list2.size(), lastIdx);
	}

	if (x > numbers[0])
	{
		list2[0] = idx;
		return pair<int, int> (1,-1);
	}

	int bound = binarySearch2(x);
	list2[bound+1] = idx;
	return pair<int, int> (bound+2, list2[bound]);
}

void constructLis()
{
	// int mx = 0;
	// int mxIdx = 0;
	for (int i=numbers.size()-1; i>=0; i--)
	{
		pair<int, int> data = findPlace(numbers[i], i);
		sizes.push_back(data.first);
		// prevIndexes.push_back(data.second);
		
		// if (data.first > mx)
		// {
		// 	mx=data.first;
		// 	mxIdx = data.second;
		// }
	}

	// printf("%d\n", mx);
}

void constructLds()
{
	// int mx = 0;
	// int mxIdx = 0;
	for (int i=numbers.size()-1; i>=0; i--)
	{
		pair<int, int> data = findPlace2(numbers[i], i);
		sizes2.push_back(data.first);
		// prevIndexes2.push_back(data.second);
		
		// if (data.first > mx)
		// {
		// 	mx=data.first;
		// 	mxIdx = data.second;
		// }
	}

	// printf("%d\n", mx);
}

void findResult()
{
	int mx=0;
	for (int i=0; i<numbers.size(); i++)
	{
		mx = max(mx, sizes[i]+sizes2[i]-1);
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
		sizes.clear();
		list2.clear();
		sizes2.clear();

		for (int i=0; i<n; i++)
		{
			scanf("%d", &temp);
			numbers.push_back(temp);
		}

		constructLis();
		constructLds();
		findResult();
	
	}
	return 0;
}