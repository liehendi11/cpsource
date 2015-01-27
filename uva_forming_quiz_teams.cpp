#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

#define INF 2000000000LL

unordered_map<int, double> dp;
vector<pair<double, double>> students;
int n;

void reset()
{
	dp.clear();
	students.clear();
}

double findDistance(double x1, double y1, double x2, double y2)
{
	return sqrt(pow(abs(x1-x2),2) + pow(abs(y1-y2),2));
}

double find(int x, int state)
{
	if (x==n) return 0;

	if (dp.count(state) ==0)
	{
		double mx=INF;
		for (int i=0; i<2*n; i++)
		{
			if (!(state & (1<<i)))
				for (int j=i+1; j<2*n; j++)
					if (!(state & (1<<j)))
					{
						int temp = state;
						temp = temp | (1<<j);
						temp = temp | (1<<i);

						mx = min(find(x+1, temp) + findDistance(students[i].first, students[i].second, students[j].first, students[j].second), mx);
					}
		}

		dp.insert(pair<int, double> (state, mx));
	}

	return dp[state];
}

int main()
{
	n=-1;
	int z=1;
	while (n!=0)
	{
		scanf("%d", &n);
		if (n==0) break;

		reset();
		string s;
		double a,b;
		for (int i=0; i<2*n; i++)
		{
			cin >> s >> a >> b;
			students.push_back(pair<double, double> (a,b));
		}

		printf("Case %d: %.2f\n", z,find(0,0));
		z++;
	}
	return 0;
}