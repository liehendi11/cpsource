#include <stdio.h>
#include <stdlib.h>
#include <cstring>

using namespace std;

struct tdata
{
	bool taken[18];
	int numbers[18];
};

int primes[11] = {2,3,5,7,11,13,17,19,23,29,31};
int n;

void printState(tdata state)
{
	for (int i=0; i<n; i++)
	{
		printf("%d", state.numbers[i]);
		if (i< n-1) printf(" ");
	}
	printf("\n");
}

bool isPrime(int bil)
{
	for (int i=0; i<11; i++)
	{
		if (bil==primes[i]) return true;
	}

	return false;
}

void find(int ix, tdata state)
{
	if (ix == n)
	{
		printState(state);
		return;
	}

	for (int i=2; i<=n; i++)
	{
		if (!state.taken[i])
		{
			bool ok = true;
			if (!isPrime(state.numbers[ix-1] + i)) ok=false;
			if (ix == n-1) if (!isPrime(i+state.numbers[0])) ok=false;
			
			if (ok)
			{
				tdata neo = state;
				neo.taken[i] = true;
				neo.numbers[ix] = i;
				find(ix+1, neo);
			}
		}
	}
}

int main()
{
	tdata def;
	memset(def.taken, false, sizeof(def.taken));
	memset(def.numbers, 0, sizeof(def.numbers));
	def.taken[1] = true;
	def.numbers[0] = true;

	int z=1;

	while (scanf("%d", &n) != EOF)
	{
		if (z>1) printf("\n");
		printf("Case %d:\n", z);
		find(1, def);
		z++;
	}

	return 0;
}