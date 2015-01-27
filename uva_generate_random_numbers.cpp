#include <stdio.h>
#include <stdlib.h>
#include <unordered_set>

using namespace std;

int next_random(int x)
{
	return (((x*x)/100) % 10000);
}

void floyd_cycle_finding(int start)
{

	int tortoise = start;
	int hare = start;
	int ctr=0;

	while ((ctr==0) || (tortoise != hare))
	{
		
		tortoise = next_random(tortoise);
		hare = next_random(next_random(hare));

		ctr+=1;
	}

	printf("%d %d\n", tortoise, hare);

	int tortoise2 = start;
	while (tortoise != tortoise2)
	{
		tortoise = next_random(tortoise);
		tortoise2 = next_random(tortoise2);
		ctr+=1;
	}

	printf("%d\n", ctr);
}

void cycle_finding(int start)
{
	unordered_set<int> used;
	int tortoise = start;
	int ctr=0;

	while (used.count(tortoise) == 0)
	{
		used.insert(tortoise);
		tortoise = next_random(tortoise);
		ctr+=1;
	}

	printf("%d\n", ctr);
}

int main()
{
	int x;
	while (scanf("%d", &x))
	{
		if (x==0) break;

		cycle_finding(x);
	}
	return 0;
}