#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

vector<int> numbers;
vector<int> lis, lds, sizeLis, sizeLds;
bool debug=false;

int binarySearchLis(int x)
{
	int mn = 0;
	int mx = lis.size()-1;
	int temp=0;

	while (mn <= mx)
	{
		int mid = (mn+mx)/2;
		
		if (lis[mid] < x)
		{
			temp = mid;
			mn  = mid+1;
		}
		else
			mx = mid-1;
	}

	return temp;
}

int binarySearchLds(int x)
{
	int mn = 0;
	int mx = lds.size()-1;
	int temp=0;

	while (mn <= mx)
	{
		int mid = (mn+mx)/2;
		
		if (lds[mid] > x)
		{
			temp = mid;
			mn  = mid+1;
		}
		else
			mx = mid-1;
	}

	return temp;
}

int findLisPosition(int x)
{
	if (lis.empty())
	{
		lis.push_back(x);
		return 1;
	}

	int last = lis[lis.size()-1];
	int first = lis[0];

	if (x > last)
	{
		lis.push_back(x);
		return ((int)lis.size());
	}

	if (x<first)
	{
		lis[0] = x;
		return 1;
	}

	int bound = binarySearchLis(x);
	lis[bound+1] = x;
	return bound+2;
}

int findLdsPosition(int x)
{
	if (lds.empty())
	{
		lds.push_back(x);
		return 1;
	}

	int last = lds[lds.size()-1];
	int first = lds[0];

	if (x < last)
	{
		lds.push_back(x);
		return ((int)lds.size());
	}

	if (x>first)
	{
		lds[0] = x;
		return 1;
	}

	int bound = binarySearchLds(x);
	lds[bound+1] = x;
	return bound+2;
}

void generateLIS()
{
	for (int i=numbers.size()-1; i>=0; i--)
	{
		sizeLis.push_back(findLisPosition(numbers[i]));

		if (debug)
		{
			printf("LIS on %d: ", numbers[i]);
			for (int j=0; j<lis.size(); j++)
			{
				printf("%d ", lis[j]);
			}
			printf("\n");	
		}
		
	}
}

void generateLDS()
{
	for (int i=numbers.size()-1; i>=0; i--)
	{
		sizeLds.push_back(findLdsPosition(numbers[i]));

		if (debug)
		{
			printf("LDS on %d: ", numbers[i]);
			for (int j=0; j<lds.size(); j++)
			{
				printf("%d ", lds[j]);
			}
			printf("\n");
		}
	}
}

void findResult()
{
	int mx=0;
	for (int i=0; i<numbers.size(); i++)
	{
		mx = max(mx, sizeLis[i]+sizeLds[i]-1);
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
		lis.clear(); lds.clear();
		sizeLis.clear(); sizeLds.clear();

		for (int i=0; i<n; i++)
		{
			scanf("%d", &temp);
			numbers.push_back(temp);
		}

		generateLIS();
		generateLDS();
	
		findResult();	
	}
	return 0;
}