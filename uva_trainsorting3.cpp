#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

int dp[2000]


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