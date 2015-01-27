#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

#define INF 1000000009LL

pair<int, int> dp[1002][502];
vector<int> topics;
int n,c,l;
int z;

void reset()
{
	pair<int, int> res = pair<int, int> (-1,-1);
	for (int i=0; i<1002; i++)
	{
		for (int j=0; j<502; j++)
		{
			dp[i][j] = res;
		}
	}
	topics.clear();
}

pair<int, int> compute(int idx, int tempSum)
{
	if (idx==n)
	{
		int t = l-tempSum;
		if (t == 0) return pair<int, int> (0, 0);
		else
			if (t <= 10) return pair<int, int> (0,-c);
			else
				return pair<int, int> (0, pow((t-10),2));
	}

	if (dp[idx][tempSum].first == -1)
	{
		pair<int, int> res = pair<int, int> (INF,INF);

		if ((topics[idx] + tempSum <= l) && (idx!=0))
		{
			pair<int, int> temp = compute(idx+1, tempSum+topics[idx]);
			if (temp.first < res.first) res = temp;
			else
				if ((temp.first == res.first) && (temp.second < res.second)) res = temp;
		}
		
		int dissatisfaction =0;

		if (idx !=0)
		{
			int t = l-tempSum;
			if (t==0) dissatisfaction=0;
			else
			if (t <= 10) dissatisfaction = -c;
			else
				dissatisfaction = pow((t-10),2);
		}
		

		pair<int, int> temp = compute(idx+1, topics[idx]);
		temp.first +=1;
		temp.second += dissatisfaction;
		if (temp.first < res.first) res = temp;
		else
			if ((temp.first == res.first) && (temp.second < res.second)) res = temp;

		dp[idx][tempSum] = res;
	}

	return dp[idx][tempSum];
}

int main()
{
	n=-1;
	z=1;
	while (n!=0)
	{
		scanf("%d", &n);
		if (n==0) break;

		scanf("%d%d", &l, &c);
		reset();
		int x;
		for (int i=0; i<n; i++)
		{
			scanf("%d", &x);
			topics.push_back(x);
		}

		pair<int, int> res = compute(0,0);

		if (z>1) printf("\n");

		printf("Case %d:\n", z);
		printf("Minimum number of lectures: %d\n", res.first);
		printf("Total dissatisfaction index: %d\n", res.second);

		z++;
	}

	return 0;
}