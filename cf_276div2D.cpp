#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
	int n, i,j;
	int temp;
	vector<int> bil;
	int retrievalArr[2000002];
	vector<int> unique;

	scanf("%d", &n);

	for (i=0; i<n; i++)
	{
		scanf("%d", &temp);
		bil.push_back(temp);
	}

	sort(bil.begin(), bil.end());

	memset(retrievalArr, -1, sizeof(retrievalArr));

	int prevMax = 2000001;
	for (i=n-1; i>=0; i--)
	{
		if (i!=n-1)
		{
			if (bil[i] == bil[i+1]) continue;
		}
		
		for (j=bil[i]+1; j<=prevMax; j++)
		{
			retrievalArr[j] = bil[i];
		}

		prevMax = bil[i];
		unique.push_back(bil[i]);
		
	}

	int res = 0;
	int n2 = unique.size();
	for (i=n2-1; i>=0; i--)
	{
		if (unique[i] == 1) continue;
		int x = unique[i] *2;

		while (x <= (unique[0] *2))
		{
			int temp = retrievalArr[x];
			if (temp != -1)
			{
				if (temp % unique[i] > res) res = temp%unique[i];
			}

			x+= unique[i];
		}
	}

	printf("%d\n", res);

	return 0;
}