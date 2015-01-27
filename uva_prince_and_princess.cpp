#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> prince, princess;
vector<int> lis;
int n,p,q;

void reset()
{
	prince.clear();
	princess.clear();
	lis.clear();
}

int binarySearch(int q)
{
	int mn = 0;
	int mx = lis.size()-1;
	int res = -1;

	while (mn <= mx)
	{
		int mid = (mn+mx)/2;
		
		if (lis[mid] < q)
		{
			res = mid;
			mn = mid+1;
		}
		else
			mx = mid-1;
	}

	return res;
}

int process()
{
	unordered_map<int, int> orderMap;

	for (int i=0; i<prince.size(); i++)
	{
		orderMap.insert(pair<int, int> (prince[i], i));
	}

	int dp[62502];
	memset(dp, 0, sizeof(dp));

	int res=0;

	for (int j=0; j<princess.size(); j++)
	{
		int element = princess[j];

		if (orderMap.count(element) != 0)
		{
			int cur = orderMap[element];
			if (lis.size() ==0)
			{
				lis.push_back(cur);
				dp[j] = 1;
			}
			else
				if (lis[lis.size()-1] < cur)
				{
					lis.push_back(cur);
					dp[j] = lis.size();
				}
				else
					if (lis[0] > cur)
					{
						lis[0] = cur;
						dp[j] = 1;
					}
					else
					{
						int pos = binarySearch(cur);
						lis[pos+1] = cur;
						dp[j] = pos+2;
					}
		}

		res = max(res, dp[j]);
	}

	return res;
}

int main()
{
	int tc=1;
	scanf("%d", &tc);
	for (int z=1; z<=tc; z++)
	{
		scanf("%d%d%d", &n, &p, &q);
		reset();

		int x=0;
		for (int i=0; i<p+1; i++)
		{
			scanf("%d", &x);
			prince.push_back(x);
		}

		for (int i=0; i<q+1; i++)
		{
			scanf("%d", &x);
			princess.push_back(x);
		}

		printf("Case %d: %d\n", z, process());
	}
	
	return 0;
}