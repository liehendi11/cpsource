#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#define UPPER 2147483647

long long dp[202];
string s;

long long compute(int idx)
{
	if (idx == s.length()) return 0;

	if (dp[idx] == -1)
	{
		long long res = 0;

		long long temp=0;
		for (int i=0; i<(s.length() - idx); i++)
		{
			if ((s[idx+i]=='0') && (temp==0) && (i!=0)) break;
			temp = (temp*10) + (s[idx+i]-48);
			if (temp <= UPPER)
			{
				res = max(res, temp+compute(idx+i+1));
			}
			else
				break;
		}

		dp[idx] = res;
	}

	return dp[idx];
}

int main()
{
	int tc;
	scanf("%d", &tc);
	getchar();

	for (int z=1; z<=tc; z++)
	{
		getline(cin, s);

		for (int i=0; i<202; i++) dp[i] = -1;

		printf("%lld\n", compute(0));
	}
	return 0;
}
