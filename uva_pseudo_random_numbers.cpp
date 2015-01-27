#include <stdio.h>
#include <stdlib.h>

using namespace std;

long long next_random(long long z, long long i, long long m, long long l)
{
	return (z*l+i)%m;
}

void floyd_cycle_finding(int tc, long long z, long long i, long long m, long long seed)
{
	long long tortoise = seed;
	long long hare = seed;
	bool start = true;
	int ctr = 0;

	while ((start) || (tortoise != hare))
	{
		start=false;

		tortoise = next_random(z,i,m,tortoise);
		hare = next_random(z,i,m,next_random(z,i,m,hare));
		ctr+=1;
	}

	printf("Case %d: %d\n", tc, ctr);
}

int main()
{
	int z,i,m,seed,x;
	x=0;
	while (scanf("%d%d%d%d", &z, &i, &m, &seed))
	{
		if ((z==0) && (i==0) && (m==0) && (seed==0)) break;
		x+=1;

		floyd_cycle_finding(x, z, i, m, seed);
	}
	return 0;
}