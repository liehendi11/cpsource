#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;


#define INF 20000LL

int dp[1000003];
int t,n,i,j,z, result;
int digit[10];

void OPEN(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}


bool isDigitConstruct(int x)
{
	while (x != 0)
	{
		if (digit[x%10] != 1) return false;
		x /=10;
	}
	
	return true;
}

bool digitCount(int x)
{
	int res2 = 0;
	int temp = x;

	while (temp > 0)
	{
		res2+=1;
		temp = temp/10;
	}
	// printf("digit counter %d %d\n", x , res2);
	return res2;
}

int find(int bil)
{
	int res = INF;
	int i,j;

	if (dp[bil] != -1) return dp[bil];
	
	if (isDigitConstruct(bil))
	{
		int res2 = 0;
		int temp = bil;

		while (temp > 0)
		{
			res2+=1;
			temp = temp/10;
		}

		// cout << "dari digit" << bil << " " << res2 << " " << digitCount(bil) << endl;
		dp[bil] = res2;
		
		return res2;
	}

	for (i=2; i*i<bil; i++)
	{
		if (bil % i == 0) res = min(res, find(i) + find(bil/i) + 1);	
	}

	dp[bil] = res;
	// cout << bil << " " << res << endl;
	return res;
}

int main()
{
	OPEN("C-large-practice");
	scanf("%d", &t);
	for (z=1; z<=t; z++)
	{
		for (i=0; i<10; i++)
		{
			scanf("%d", &digit[i]);
		}
		memset(dp, -1, sizeof(dp));
		scanf("%d", &n);

		result = find(n);

		if (result < INF)
		{
			printf("Case #%d: %d\n", z, result+1);
		}
		else
			printf("Case #%d: Impossible\n", z);
	}
}