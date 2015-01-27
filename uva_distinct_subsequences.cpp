#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

typedef signed char sc;

string dp[10002][102];
string x, z;
int n;

void reset()
{
	for (int i=0; i<10002; i++)
	{
		for (int j=0; j<102; j++)
		{
			dp[i][j] = "-1";
		}
	}
}

bool isBigger(string a, string b)
{
	if (a.length() > b.length()) return true;
	if (a.length() == b.length())
	{
		for (int i=a.length()-1; i>=0; i--)
		{
			if (a[i] > b[i]) return true;
			if (a[i] < b[i]) return false;
		}
	}
	return false;
}

string maxStr(string a, string b)
{
	if (a>b) return a;
	else
		return b;
}

void printReverse(string in)
{
	for (int i=in.size()-1; i>=0; i--)
	{
		printf("%c", in[i]);
	}
	printf("\n");
}

string sum(string a, string b)
{
	int remain=0;
	string res = "";
	int temp;

	for (int i=0; i<max(a.length(), b.length()); i++)
	{
		temp=0;
		if (i < a.length()) temp += (a[i]-48);
		if (i < b.length()) temp += (b[i]-48);

		remain = temp/10;
		temp = temp%10;
		res+= (temp+48);
	}

	if (remain>0)
	{
		temp = remain;
		res += (temp+48);
		remain=0;
	}
	return res;
}

string findResult(int a, int b)
{
	if (b == z.length()) return "1";
	if (a==x.length()) return "0";

	if (dp[a][b] == "-1")
	{
		string res = "0";
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