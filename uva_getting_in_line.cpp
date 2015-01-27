#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

#define INF 100000
#define SIZE 1026

double adj[10][10];
double dp[10][SIZE];
bool visited[10][SIZE];
int path[10][SIZE];
vector<pair<double, double> > computers;
int n;
int npow;

void OPEN(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void init()
{
	memset(adj, 0, sizeof(adj));
	memset(dp, 0, sizeof(dp));
	memset(visited, false, sizeof(visited));
	memset(path, 0, sizeof(path));
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			if (i!=j)
			{
				adj[i][j] = sqrt(pow(abs(computers[i].first - computers[j].first), 2) + pow(abs(computers[i].second-computers[j].second), 2)) + 16;
			}
		}
	}
}

double compute(int start, int state)
{
	if (visited[start][state]) return dp[start][state];
	if (state ==0) return 0;

	double res = INF;
	double temp = INF;
	for (int i=0; i<n; i++)
	{
		int mask = (npow-1) - (1<<i);
		int nextState = state & mask;
		if (nextState != state)
		{
			temp = adj[start][i] + compute(i, nextState);
			if (temp <res)
			{
				res = temp;
				path[start][state] = i;
			}
		}
	}

	return dp[start][state] = res;
}

void reconstructPath(int start, int state)
{
	if (state ==0) return;
	int x = path[start][state];

	printf("Cable requirement to connect (%.0f,%.0f) to (%.0f,%.0f) is %.2f feet.\n", computers[start].first, computers[start].second, computers[x].first, computers[x].second, adj[start][x]);

	int mask = (npow-1) - (1<<x);
	int nextState = state & mask;
	
	reconstructPath(x, nextState);
}

void TSP(int z)
{
	init();
	npow = pow(2,n);

	int allFull = npow-1;
	double minRes = compute(0,npow-2);
	int minStart=0;
	int minState = npow-2;

	for (int i=1; i<n; i++)
	{
		int nextState = allFull - (1<<i);
		double res = compute(i, nextState);
		if (res < minRes)
		{
			minRes = res;
			minStart = i;
			minState = nextState;
		}
	}

	printf("**********************************************************\n");
	printf("Network #%d\n", z);

	reconstructPath(minStart, minState);

	printf("Number of feet of cable required is %.2f.\n", minRes);
}

int main()
{
	// OPEN("getting_in_line");

	int z=1;
	n=-1;
	while (n!=0)
	{
		scanf("%d", &n);
		if (n==0) break;

		computers.clear();
		int a,b;

		for (int i=0; i<n; i++)
		{
			scanf("%d%d", &a, &b);
			computers.push_back(pair<double, double> (a,b));
		}

		TSP(z);
		z+=1;
	}

	return 0;
}