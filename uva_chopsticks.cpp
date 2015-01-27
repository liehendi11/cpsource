#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

#define INF 1024000002LL

int userCtr, chopCtr;
vector<int> chopsticks;
long long dp[1010][5002];

void OPEN(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void reset()
{
	for (int i=0; i<1010; i++)
	{
		for (int j=0; j<5002; j++)
		{
			dp[i][j] = -1;
		}
	}
	chopsticks.clear();
}

long long compute(int user, int chop)
{
	if (user == userCtr) return 0;
	if (chop >= chopCtr) return INF;

	if (dp[user][chop] == -1)
	{
		long long res = INF;

		int deficit = max((user*3) - chop, 0);

		long long badness;
		bool isBad=false;

		//deficit*=-1;

		int maxRange = chopCtr - deficit - ((userCtr-user-1) *3);

		if (chop+2 < maxRange)
		{
			long long temp = (compute(user+1, chop+2) + pow(chopsticks[chop+1] - chopsticks[chop], 2));
			if (temp < res)
			{
				res = temp;
				// isBad = true;
				// badness = pow(chopsticks[chop+1] - chopsticks[chop], 2);
			}
		}

		long long temp = compute(user, chop+1);
		if (temp < res)
		{
			res = temp;
			// isBad = false;
		}

		// if (isBad) printf("%d %d %d %d %lld\n", user, chop, deficit, maxRange, badness);

		dp[user][chop] = res;
	}

	return dp[user][chop];
}

int main()
{
	// OPEN("chopsticks");
	int tc;
	scanf("%d", &tc);
	for (int z=1; z<=tc; z++)
	{
		scanf("%d%d", &userCtr, &chopCtr);
		reset();

		int x;
		for (int i=0; i<chopCtr; i++)
		{
			scanf("%d", &x);
			chopsticks.push_back(x);
		}

		sort(chopsticks.begin(), chopsticks.end());
		userCtr+=8;

		long long res = compute(0,0);

		printf("%lld\n", res);
	}
	return 0;
}