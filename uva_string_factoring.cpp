#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#define INF 1000

int dp[82][82];
string s;


int compute(int x, int y)
{
	if (x == y) return 1;
	if (x > y) return 0;

	if (dp[x][y] == -1)
	{
		int res = INF;
		for (int i=x; i<y; i++)
		{
			int len = i-x+1;
			int right = x+len;
			string subs = s.substr(x, len);

			while (right + len - 1 <= y)
			{
				string multi = s.substr(right, len);
				if (multi == subs)
					right += len;
				else
					break;
			}

			res = min(res, compute(x, x+len-1) + compute(right, y));
		}

		dp[x][y] = res;
	}

	return dp[x][y];
}

int main()
{
	while (getline(cin, s))
	{
		if (s == "*") break;

		memset(dp, -1, sizeof(dp));

		printf("%d\n", compute(0, s.length()-1));
	}
	return 0;
}