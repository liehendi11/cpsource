#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

int dp[102][24][2202];
vector<pair<int, int> > dimsums;
int n,x,t,k;
int budget;

void reset()
{
	memset(dp, -1, sizeof(dp));
	dimsums.clear();
}

int getBudget()
{
	int maxmoney = floor(double(x * n) / 1.1 + 1e-6) - (n * t);
	return maxmoney;
	// int temp = floor((double)(x * n) * 0.9000000);
	// temp -= (n * t);
	// return temp;
}

int findResult(int idx, int curDishes, int curSum)
{
	if (idx==dimsums.size()) return 0;
	if (curDishes == 2*n) return 0;

	if (dp[idx][curDishes][curSum] == -1)
	{
		int res = 0;
		if ((curSum + dimsums[idx].first <= budget) && ((curDishes+1) <= (2*n)))
			res = max(res, findResult(idx+1, curDishes+1, curSum+dimsums[idx].first) + (dimsums[idx].second));
		if ((curSum + (dimsums[idx].first*2) <= budget) && ((curDishes+2) <= (2*n)))
			res = max(res, findResult(idx+1, curDishes+2, curSum+(dimsums[idx].first*2))  + (dimsums[idx].second *2));

		res = max(res, findResult(idx+1, curDishes, curSum));

		dp[idx][curDishes][curSum] = res;
	}

	return dp[idx][curDishes][curSum];
}

void OPEN(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main()
{
	//OPEN("lets_yum_cha");
	while (true)
	{
		scanf("%d%d%d%d", &n, &x, &t, &k);
		if ((n==0) && (x==0) && (t==0) && (k==0)) break;
		reset();

		for (int i=0; i<k; i++)
		{
			int price = 0, totalPoint=0;
			int temp;
			scanf("%d%d", &price, &totalPoint);

			for (int i=0; i<n; i++)
			{
				scanf("%d", &temp);
				totalPoint+=temp;
			}

			dimsums.push_back(pair<int, int> (price, totalPoint));
		}

		n+=1;

		budget = getBudget();

		//printf("%d\n", budget);

		double res = ((double) findResult(0,0,0)) / ((double) n);
		//res /= ((double)n);

		printf("%.2f\n", res);
	}	
	return 0;
}