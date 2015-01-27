#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define SIZE 1048576

class Data
{
public:
	int p,c,f;
	Data(int ap, int ac, int af)
	{
		p = ap;
		c = ac;
		f = af;
	}
};

char dp[22][SIZE];
vector<Data> foods;
int targetP, targetC, targetF,n;

Data recoverState(int curIdx, int state)
{
	Data ret(0,0,0);
	for (int i=0; i<curIdx; i++)
	{
		if (state & (1<<i))
		{
			ret.p += foods[i].p;
			ret.c += foods[i].c;
			ret.f += foods[i].f;
		}
	}

	return ret;
}

bool compute(int curIdx, int state)
{
	if (dp[curIdx][state] == -1)
	{
		Data curState = recoverState(curIdx, state);

		if (curIdx == foods.size())
		{
			if ((curState.p == targetP) && (curState.c == targetC) && (curState.f == targetF))
				dp[curIdx][state] = 1;
			else
				dp[curIdx][state] = 0;
		}
		else
		{
			bool res = false;
			if ((curState.p + foods[curIdx].p <= targetP) && (curState.c + foods[curIdx].c <= targetC) && (curState.f + foods[curIdx].f <= targetF))
			{
				int newState = (state | (1<<curIdx));
				res = (res || compute(curIdx+1, newState));
			}

			if (res == false)
			{
				res = res || compute(curIdx+1, state);
			}

			if (res) dp[curIdx][state] = 1;
			else
				dp[curIdx][state] = 0;
		}
	}
	
	return (dp[curIdx][state] == 1);	
}

void reset()
{
	memset(dp, -1, sizeof(dp));
	foods.clear();
}

void OPEN(string s) {
	freopen((s + ".txt").c_str(), "r", stdin);
	freopen((s + "_out.txt").c_str(), "w", stdout);
}

int main()
{
	// OPEN("new_years_resolution");
	int tc;
	scanf("%d", &tc);
	for (int z=1; z<=tc; z++)
	{
		reset();
		scanf("%d%d%d", &targetP, &targetC, &targetF);
		scanf("%d", &n);
		
		int a,b,c;
		for (int i=0; i<n; i++)
		{
			scanf("%d%d%d", &a, &b, &c);
			foods.push_back( Data(a,b,c));
		}

		if (compute(0, 0)) printf("Case #%d: yes\n", z);
		else
			printf("Case #%d: no\n", z);
	}
	return 0;
}