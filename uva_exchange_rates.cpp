#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <algorithm>

using namespace std;

#define INF 1000000009LL

typedef pair<int, pair<long long, bool> > ii;

struct Data
{
	int idx;
	long long sum;
	bool canada;
};

map<ii, long long> dp;
int n;
vector<double> exchanges;

void reset()
{
	dp.clear();
	exchanges.clear();
}

long long compute(ii state)
{
	if (state.first == n)
	{
		if (state.second.second) return state.second.first;
		else
			return 100000;
	}

	if (dp.count(state) ==0)
	{
		long long res = 100000;

		ii newState1= state;
		newState1.first += 1;
		res = max(res, compute(newState1));

		if (state.second.second)
		{
			ii newState2 = state;
			newState2.first += 1;
			newState2.second.first = (newState2.second.first / (exchanges[state.first])) * 0.97;
			newState2.second.second = false;
			res = max(res, compute(newState2));
		}

		if (!state.second.second)
		{
			ii newState2= state;
			newState2.first += 1;
			newState2.second.first = (newState2.second.first * (exchanges[state.first])) * 0.97;
			newState2.second.second = true;
			res = max(res, compute(newState2));
		}

		dp.insert(pair<ii, long long> (state, res));
	}

	return dp[state];
}

int main()
{
	n=-1;
	while (n!=0)
	{
		scanf("%d", &n);
		if (n==0) break;

		reset();

		double x;
		for (int i=0; i<n; i++)
		{
			scanf("%lf", &x);
			exchanges.push_back(x);
		}

		ii init;
		init.first = 0;
		init.second.first = 100000;
		init.second.second = true;

		long long res = compute(init);

		printf("%.2f\n",  (((double)res)/100));

	}

	return 0;
}