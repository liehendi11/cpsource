#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define SIZE 10000000

int a,b,k;
bool sieve[SIZE];
int primacity[SIZE];
int primacityTable[9][SIZE];


void computeSieve()
{
	int maxPrimacity = 0;
	memset(sieve, true, sizeof(sieve));
	memset(primacity, 0, sizeof(primacity));
	memset(primacityTable, 0, sizeof(primacityTable));

	int count = 0;

	for (int i=2; i<=SIZE; i++)
	{
		if (sieve[i])
		{
			primacity[i] = 1;
			int multiplier = 2;

			while (multiplier*i <= SIZE)
			{
				primacity[multiplier*i] += 1;
				sieve[multiplier*i] = false;
				multiplier+=1;
			}
		}

		for (int k=1; k<=8; k++) primacityTable[k][i] = primacityTable[k][i-1];
		primacityTable[primacity[i]][i] += 1;
	}
}

void OPEN(string s) {
	freopen((s + ".txt").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main()
{
	// OPEN("homework");
	computeSieve();

	int tc;
	scanf("%d", &tc);
	for (int z=1; z<=tc; z++)
	{
		scanf("%d%d%d", &a, &b, &k);
		printf("Case #%d: %d\n", z, primacityTable[k][b] - primacityTable[k][a-1]);
	}
	return 0;
}