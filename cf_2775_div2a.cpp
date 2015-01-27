#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
#include <string.h>

using namespace std;

int numbers[3002];
int n;
vector<pair<int,int> > operations;

int main()
{
	memset(numbers, 0, sizeof(numbers));
	operations.clear();

	scanf("%d", &n);
	for (int i=0; i<n; i++)
	{
		scanf("%d", &numbers[i]);
	}

	int k;
	for (int i=0; i<n; i++)
	{
		int mn = numbers[i];
		int x = i;
		for (int j=i+1; j<n; j++)
		{
			if (numbers[j] < mn)
			{
				mn=min(numbers[j], mn);
				x = j;
			}
		}

		if (x != i)
		{
			int temp = numbers[i];
			numbers[i] = numbers[x];
			numbers[x] = temp;

			operations.push_back(pair<int, int> (i,x));
		}
	}

	printf("%d\n", (int) operations.size());
	for (int i=0; i<operations.size(); i++)
	{
		printf("%d %d\n", operations[i].first, operations[i].second);
	}

	return 0;
}