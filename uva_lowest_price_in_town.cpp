#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

#define INF 1000000

vector<pair<int, double> > prices;
double dp[23][202];
int n,q;
double base;

void reset()
{
	for (int i=0; i<23; i++)
	{
		for (int j=0; j<102; j++)
		{
			dp[i][j] = -1;
		}
	}

	prices.clear();
}

double compute(int idx, int sum)
{
	if (sum <= 0) return 0;
	if (idx == n) return INF;

	if (dp[idx][sum] == -1)
	{
		double res = INF;
		int k=0;

		while (prices[idx].first * k <= sum)
		{
			res = min(res, compute(idx+1, sum-(prices[idx].first * k)) + (prices[idx].second*k));
			k+=1;
		}
		res = min(res, compute(idx+1, sum-(prices[idx].first * k)) + (prices[idx].second*k));

		dp[idx][sum] = res;

	}

	return dp[idx][sum];
}

int main()
{
	int z=1;
	while (scanf("%lf%d", &base, &n) != EOF)
	{
		reset();
		prices.push_back(pair<int, double> (1, base));

		double inPrice;
		int inQty;
		for (int i=0; i<n; i++)
		{
			scanf("%d%lf",&inQty, &inPrice);
			prices.push_back(pair<int, double> (inQty, inPrice));
		}
		n+=1;

		printf("Case %d:\n", z);

		getchar();
		char dum=0;

		while (dum != '\n')
		{
			scanf("%d", &q);
			scanf("%c", &dum);

			printf("Buy %d for $%.2f\n", q, compute(0, q));
		}

		z++;
	}
	return 0;
}