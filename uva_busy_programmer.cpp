#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

long long dp[70][3][35][3];
int n, range;

void reset()
{
	memset(dp, -1, sizeof(dp));
}

void OPEN(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

long long compute(int day, int prev, int first, int firstStart)
{
	if (day == (2*n)) return 1;

	int second = day-first;
	if (first == n)
	{
		if (firstStart == 0) return 1;
		else
			return 0;
	}
	if (second == n)
	{
		if (firstStart == 1) return 1;
		else
			return 0;
	}

	if (dp[day][prev][first][firstStart] == -1)
	{
		if (prev == 2) //first start
		{
			long long res = 0;
		
			int minRange = min(range, n);
			// printf("0 %d => %d\n", first, minRange);
			for (int i=1; i<=minRange; i++)
			{
				res += compute(day+i, 0, first+i, 0);
			}
			
			for (int i=1; i<=minRange; i++)
			{
				res += compute(day+i, 1, first, 1);
			}
			
			dp[day][prev][first][firstStart] = res;	
		}
		else
		{
			long long res = 0;

			if (prev != 0)
			{
				int minRange = min(range, n-first);
				for (int i=1; i<=minRange; i++)
				{
					res += compute(day+i, 0, first+i, firstStart);
				}
			}

			if (prev != 1)
			{
				int minRange = min(range, n-second);
				for (int i=1; i<=minRange; i++)
				{
					res += compute(day+i, 1, first, firstStart);
				}
			}

			dp[day][prev][first][firstStart] = res;	
		}

		// printf("%d %d %d %d = %d\n", day, prev, first, second, res);
	}
	return dp[day][prev][first][firstStart];
}

int main()
{
	// OPEN("busy_programmer");
	n=-1;
	range=0;

	int z=1;
	while (true)
	{
		scanf("%d%d", &n, &range);
		if ((n==-1) && (range == -1)) break;

		reset();

		long long res = compute(0, 2, 0, 2);

		printf("Case %d: %lld\n", z, res);
		z+=1;
	}
	return 0;
}