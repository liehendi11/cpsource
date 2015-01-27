#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

long long canada[367], usa[367];
vector<double> exchanges;
int n;

void reset()
{
	memset(canada, -1, sizeof(canada));
	memset(usa, -1, sizeof(usa));
	exchanges.clear();
}

void compute()
{
	canada[0] = 100000;
	usa[0] = 100000 / exchanges[0] * 0.97;
	for (int i=1; i<exchanges.size(); i++)
	{
		long long x = usa[i-1] * exchanges[i] * 0.97;
		long long y = canada[i-1] / exchanges[i] * 0.97;
		canada[i] = max(canada[i-1], x);
		usa[i] = max(usa[i-1], y);
	}
}

int main()
{
	n=-1;
	while (n!=0)
	{
		scanf("%d", &n);
		if (n==0) break;

		reset();

		double x;
		for (int i=0; i<n; i++)
		{
			scanf("%lf", &x);
			exchanges.push_back(x);
		}

		compute();
		long long res = canada[n-1];

		printf("%.2f\n",  (((double)res)/100));

	}

	return 0;
}