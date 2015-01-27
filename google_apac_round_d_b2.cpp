#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>

using namespace std;

int updates[5003];
int sum[5003];
int t,n,p;
int a,b;
int q;

void applyUpdates()
{
	int tempTotal = 0;
	int i,j;

	for (int i=0; i<5003; i++)
	{
		tempTotal+=updates[i];
		sum[i] = tempTotal;
	}

}	

void OPEN(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main()
{
	OPEN("B-large");
	int i,j,z;
	scanf("%d", &t);
	for (z=1; z<=t; z++)
	{
		scanf("%d", &n);
		memset(updates, 0, sizeof(updates));
		memset(sum, 0, sizeof(sum));

		for (i=0; i<n; i++)
		{
			scanf("%d%d", &a, &b);
			updates[a] +=1;
			updates[b+1] -=1;
		}
		applyUpdates();
		printf("Case #%d:", z);

		scanf("%d", &p);

		for (i=0; i<p; i++)
		{
			scanf("%d", &q);
			printf(" %d", sum[q]);
		}
		printf("\n");
	}


	return 0;
}