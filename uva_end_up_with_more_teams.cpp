#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

pair<int, int> dp[33000][17];
int npow, n;
vector<int> members;

void reset()
{
	npow = pow(2,n);

	pair<int, int> resPair = pair<int, int> (-1, -1);

	for (int i=0; i<npow; i++)
	{
		for (int j=0; j<n+1; j++)
		{
			dp[i][j] = resPair;
		}
	}
	members.clear();
}

pair<int, int> compute(int state, int idx)
{
	//printf("%d %d\n", state, idx);
	if (idx==n) return pair<int, int> (0,0);

	if (dp[state][idx].first == -1)
	{
		pair<int, int> res = pair<int, int> (0,0);
		for (int i=0; i<n; i++)
		{
			int mask = (npow-1) - (1<<i);
			int masked = state & mask;
			if (masked != state)
			{
				pair<int, int> temp = compute(masked, idx+1);
				temp.first += members[i];
				if ((idx%3==0) && (temp.first >=20))
				{
					temp.first = 0;
					temp.second +=1;
				}
				
				if (temp.second > res.second) res = temp;
				else
					if ((temp.second == res.second) && (temp.first > res.first)) res = temp;
			}
		}

		dp[state][idx] = res;
	}

	return dp[state][idx];
}

int main()
{
	n=-1;
	while (n!=0)
	{
		scanf("%d", &n);
		if (n==0) break;

		if (n<3) printf("0\n");
		else
		{
			reset();
			int x;
			for (int i=0; i<n; i++)
			{
				scanf("%d", &x);
				members.push_back(x);
			}

			pair<int, int> res = compute(npow-1, 0);

			printf("%d\n", res.second);	
		}
		
	}

	return 0;
}