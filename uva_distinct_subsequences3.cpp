#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

typedef signed char sc;

int dp[10002][102][1002];
string x, z;
int n;

void reset()
{
	for (int i=0; i<10002; i++)
	{
		for (int j=0; j<102; j++)
		{
			dp[i][j].clear();
		}
	}
}

bool isBigger(vector<sc> a, vector<sc> b)
{
	if (a.size() > b.size()) return true;
	if (a.size() == b.size())
	{
		for (int i=a.size()-1; i>=0; i--)
		{
			if (a[i] > b[i]) return true;
			if (a[i] < b[i]) return false;
		}
	}
	return false;
}

vector<sc> maxStr(vector<sc> a, vector<sc> b)
{
	if (isBigger(a,b)) return a;
	else
		return b;
}

void printReverse(vector<sc> in)
{
	for (int i=in.size()-1; i>=0; i--)
	{
		printf("%d", in[i]);
	}
	printf("\n");
}

vector<sc> sum(vector<sc> a, vector<sc> b)
{
	int remain=0;
	vector<sc> res;
	int temp;

	for (int i=0; i<max(a.size(), b.size()); i++)
	{
		temp=0;
		if (i < a.size()) temp += (a[i]);
		if (i < b.size()) temp += (b[i]);

		remain = temp/10;
		temp = temp%10;
		res.push_back(temp);
	}

	if (remain>0)
	{
		temp = remain;
		res.push_back(temp);
		remain=0;
	}
	return res;
}

vector<sc> findResult(int a, int b)
{
	if (b == z.length())
	{
		vector<sc> vc;
		vc.push_back(1);
		return vc;
	}
	if (a==x.length())
	{
		vector<sc> vc;
		vc.push_back(0);
		return vc;
	}

	if (dp[a][b].size() ==0)
	{
		vector<sc> res;
		res.push_back(0);
		if (x[a] == z[b]) res = sum(res, findResult(a+1, b+1));

		res = sum(res, findResult(a+1, b));
		dp[a][b] = res;
	}

	return dp[a][b];
}

void OPEN(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main()
{
	OPEN("distinct_subsequences");
	scanf("%d", &n);
	getchar();
	for (int i=0; i<n; i++)
	{
		getline(cin, x);
		getline(cin, z);

		reset();
		printReverse(findResult(0,0));
	}
	return 0;
}