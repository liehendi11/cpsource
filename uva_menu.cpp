#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

struct Data
{
	int spent;
	string path;
	double benefit;
};

Data dp[52][23][102];
vector<pair<int, double> > dishes;
int days, budget, n;
vector<string> converts;

string convertToString(int x)
{
	if (x==0) return "0";

	string ret="";
	while (x > 0)
	{
		ret = ((char)((x%10)+48)) + ret;
		x=x/10;
	}
	return ret;
}

void reset()
{
	for (int i=0; i<52; i++)
	{
		for (int j=0; j<23; j++)
		{
			for (int k=0; k<102; k++)
			{
				dp[i][j][k].spent = -1;
				dp[i][j][k].path = "-";
				dp[i][j][k].benefit = -1;
			}
		}
	}

	dishes.clear();
}

Data compute(int prev, int curDay, int curSum)
{
	if (curDay == days)
	{
		Data ret;
		ret.spent = 0;
		ret.path = "";
		ret.benefit = 0;
		return ret;
	}

	if (prev!=-1)
		if (dp[prev][curDay][curSum].spent != -1) return dp[prev][curDay][curSum];

	Data res;
	res.spent = 200;
	res.benefit = -210002;
	res.path = "";

	for (int i=0; i<dishes.size(); i++)
	{
		if ((i != prev) && (curSum+dishes[i].first <= budget))
		{
			Data temp = compute(i, curDay+1, curSum+dishes[i].first);
			temp.benefit += dishes[i].second;
			temp.spent += dishes[i].first;

			if (temp.path.length() >0) temp.path = converts[i+1] + "/" + temp.path;
			else
				temp.path = converts[i+1];

			if (temp.benefit > res.benefit) res = temp;
			else
				if ((res.benefit == temp.benefit) && (temp.spent < res.spent)) res = temp;
		}


		if ((i != prev) && (curSum+(dishes[i].first*2) <= budget) && (curDay < days-1))
		{
			Data temp = compute(i, curDay+2, curSum+(dishes[i].first*2));
			temp.benefit += (dishes[i].second*1.5);
			temp.spent += (dishes[i].first*2);

			if (temp.path.length() >0) temp.path = converts[i+1] + "/" + converts[i+1] + "/" + temp.path;
			else
				temp.path = converts[i+1] + "/" + converts[i+1];

			if (temp.benefit > res.benefit) res = temp;
			else
				if ((res.benefit == temp.benefit) && (temp.spent < res.spent)) res = temp;
		}
	}

	if (prev !=-1) dp[prev][curDay][curSum] = res;
	
	return res;
}

void OPEN(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main()
{
	converts.clear();
	for (int i=0; i<52; i++) converts.push_back(convertToString(i));
	OPEN("menu");
	days=-1;
	budget=-1;
	n=-1;

	while (true)
	{
		scanf("%d%d%d", &days, &n, &budget);
		if ((days==0) && (n==0) && (budget==0)) break;
		reset();

		int a;
		double b;
		for (int i=0; i<n; i++)
		{
			scanf("%d%lf", &a, &b);
			dishes.push_back(pair<int, double> (a,b));
		}

		Data res = compute(-1, 0, 0);

		if (res.benefit <0) printf("0.0\n\n");
		else
		{
			printf("%.1f\n", res.benefit);
			for (int i=0; i<res.path.length(); i++)
			{
				if (res.path[i] == '/') printf(" ");
				else
					printf("%c", res.path[i]);
			}
			printf("\n");
		}
			
	}
	return 0;
}