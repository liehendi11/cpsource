#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef pair<pair<int, int>, int> ii;

map<ii, int> dp;
vector<int> numbers;
int n,d,m,q;

void reset()
{
	//dp.clear();
	numbers.clear();
}

ii makepair(int a, int b, int c)
{
	ii res;
	res.first.first = a;
	res.first.second = b;
	res.second = c;

	return res;
}

int findResult(int idx, int usedNumbers, int tempSum)
{
	if ((usedNumbers == m) && (tempSum %d == 0)) return 1;
	if (idx==n) return 0;

	ii curState = makepair(idx, usedNumbers, tempSum);
	//bool tes = ((dp.count(ii)) ==0);
	if (dp.count(curState) ==0)
	{
		int res = 0;

		res += findResult(idx+1, usedNumbers,tempSum);
		res += findResult(idx+1, usedNumbers+1,tempSum+numbers[idx]);

		dp.insert(pair<ii, int> (curState, res));
	}

	return dp[curState];
}

int main()
{
	n=-1;
	q=-1;
	int z=1;
	while (true)
	{

		scanf("%d%d", &n, &q);
		reset();

		if ((n==0) && (q==0)) break;

		int x;
		for (int i=0; i<n; i++)
		{
			scanf("%d", &x);
			numbers.push_back(x);
		}

		printf("SET %d:\n", z);

		for (int i=0; i<q; i++)
		{
			dp.clear();
			scanf("%d%d", &d, &m);
			int res = findResult(0,0,0);

			printf("QUERY %d: %d\n", i+1, res);
		}
		z+=1;
	}
	return 0;
}