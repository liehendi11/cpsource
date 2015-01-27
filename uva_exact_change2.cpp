#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> dp[102][20002];
vector<int> coins;
int sum, n;

void reset()
{
	pair<int, int> rs = pair<int, int> (-1,-1);

	for (int i=0; i<102; i++)
	{
		for (int j=0; j<20002; j++)
		{
			dp[i][j] = rs;
		}
	}
	coins.clear();
}

pair<int, int> findResult(int idx, int tempSum)
{
	if (idx==coins.size()) return pair<int, int> (0,0);

	if (dp[idx][tempSum].first == -1)
	{
		pair<int, int> rs = pair<int, int> (100000, 100000);
		int ix=0;
		while ((ix*coins[idx])+tempSum <= (sum*2))
		{
			pair<int, int> tempRes = findResult(idx+1, tempSum+(ix*coins[idx]));
			tempRes.first += ix*coins[idx];
			tempRes.second += ix;

			if (abs(tempRes.first - tem) < abs(rs.first - sum)) rs = tempRes;
			else
				if ((abs(tempRes.first - sum) == abs(rs.first - sum)) && (tempRes.second < rs.second)) rs = tempRes;
			ix+=1;
		}

		dp[idx][tempSum] = rs;
	}

	return dp[idx][tempSum];
}

int main()
{
	int tc;
	scanf("%d", &tc);

	for (int z=1; z<=tc; z++)
	{
		scanf("%d", &sum);
		scanf("%d", &n);

		reset();
		int x;
		for (int i=0; i<n; i++)
		{
			scanf("%d", &x);
			coins.push_back(x);
		}

		pair<int, int> res = findResult(0,0);
		printf("%d %d\n", res.first, res.second);
	}
	return 0;
}