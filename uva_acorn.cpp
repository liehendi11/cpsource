#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int dp[2002];
//[2002];
int acorns[2002][2002];
int t,h,f;

void reset()
{
	for (int i=0; i<t+2; i++)
	{
		dp[i]= 0;
		for (int j=0; j<h+2; j++)
		{
			acorns[i][j] = 0;
		}
	}
}

// int find(int tree, int height)
// {
// 	if (height == 0) return acorns[tree][0];

// 	if (dp[tree][height] == -1)
// 	{
// 		int mx = 0;
// 		for (int i=0; i<t; i++)
// 		{
// 			if ((i!=tree) && (height-f>=0))
// 			{
// 				if (acorns[i][height-f] >0)
// 					mx = max(mx,find(i, height-f));
// 			}
// 			else
// 				mx = max(find(i, height-1), mx);
// 		}

// 		mx+= acorns[tree][height];
// 		dp[tree][height] = mx;
// 	}

// 	return dp[tree][height];
// }

int main()
{
	int tc;
	scanf("%d", &tc);
	for (int z=1; z<=tc; z++)
	{
		scanf("%d%d%d", &t, &h, &f);
		reset();

		int x,y;
		for (int i=0; i<t; i++)
		{
			scanf("%d", &x);
			for (int j=0; j<x; j++)
			{
				scanf("%d", &y);
				acorns[i][y] +=1;
			}
		}

		for (int i=0; i<t; i++)
		{
			for (int j=0; j<=h; j++)
			{
				dp[j] = max(dp[j], acorns[i][j]);
			}
		}

		for (int j=h; j>=0; j--)
		{
			for (int i=0; i<t; i++)
			{
				acorns[i][j] += max(acorns[i][j+1], (j+f <= h)? dp[j+f]: 0);
				dp[j] = max(dp[j], acorns[i][j]);
			}
		}

		printf("%d\n", dp[0]);
		// int res=0;
		// for (int i=0; i<t; i++)
		// {
		// 	res = max(res,find(i, h));
		// }
		// printf("%d\n", res);
	}	

	return 0;
}