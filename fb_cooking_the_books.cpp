#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

long long convertToString(string &s, int x, int y)
{
	long long temp=0;
	for (int i=0; i<s.length(); i++)
	{
		if (i == x) temp = (temp*10) + (s[y]-48);
		else
			if (i==y) temp = (temp*10) + (s[x]-48);
			else
			temp = (temp*10) + (s[i]-48);
	}

	return temp;
}

void calculateMinMax(string s, int z)
{
	long long minVal = convertToString(s, 0, 0);
	long long maxVal = minVal;

	for (int i=0; i<s.length(); i++)
	{
		for (int j=i+1; j<s.length(); j++)
		{
			if (!((i==0) && (s[j] == '0')))
			{
				long long temp = convertToString(s, i, j);
				minVal = min(minVal, temp);
				maxVal = max(maxVal, temp);
			}
		}
	}

	printf("Case #%d: %lld %lld\n", z, minVal, maxVal);
}

void OPEN(string s) {
	freopen((s + ".txt").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main()
{
	// OPEN("cooking_the_books");	
	int tc;

	scanf("%d", &tc);
	for (int z=1; z<=tc; z++)
	{
		string s;
		cin >> s;
		calculateMinMax(s, z);
	}
	return 0;
}