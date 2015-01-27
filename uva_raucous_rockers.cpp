#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[802][102][102];
int n,m,t;
vector<int> songs;

void reset()
{
	memset(dp, -1, sizeof(dp));
	songs.clear();
}

int compute(int curSong, int curCD, int minutes)
{
	if (curSong == n) return 0;
	if (curCD == m) return 0;

	if (dp[curSong][curCD][minutes] == -1)
	{
		int res = 0;

		//skip
		res = max(res, compute(curSong+1, curCD, minutes));

		//use in current CD
		if (minutes >= songs[curSong])
			res = max(res, (compute(curSong+1, curCD, minutes - songs[curSong]) +1));

		//use in new CD
		if (curCD < m-1)
			res = max(res, (compute(curSong+1, curCD+1, t-songs[curSong]) +1));

		dp[curSong][curCD][minutes] = res;
		// printf("%d %d %d -> %d\n", curSong, curCD, minutes, dp[curSong][curCD][minutes]);
	}

	
	return dp[curSong][curCD][minutes];
}



int main()
{
	int tc;
	scanf("%d", &tc);
	for (int z=1; z<=tc; z++)
	{
		scanf("%d%d%d", &n, &t, &m);
		reset();

		int x;
		for (int i=0; i<n; i++)
		{
			scanf("%d", &x);
			getchar();
			songs.push_back(x);
		}

		int res = compute(0,0,t);

		if (z>1) printf("\n");
		printf("%d\n", res);
	}
	return 0;
}