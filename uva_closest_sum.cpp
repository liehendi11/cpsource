#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define INF 2000000000LL

long long bil[1002];
vector<long long> sums;

int main()
{
	long long n=-1, m=0, z=1;

	while (n!=0)
	{
		//scanf("%d", &n);
		cin >> n;
		if (n==0) break;

		for (long long i=0; i<n; i++)
		{
			// scanf("%d", &bil[i]);
			cin >> bil[i];
		}

		sums.clear();

		for (long long i=0; i<n; i++)
		{
			for (long long j=i+1; j<n; j++)
			{
				if (bil[i] != bil[j])
				{
					long long tempSum = bil[i]+bil[j];
					sums.push_back(tempSum);
				}
			}
		}

		sort(sums.begin(), sums.end());

		//prlong longf("Case #%d:\n", z);
		cout << "Case " << z << ":\n";
		cin >> m;
		// scanf("%d", &m);
		//prlong longf("%d\n", m);
		for (long long i=0; i<m; i++)
		{
			long long q;
			cin >> q;
			//scanf("%d", &q);
			// prlong longf("%d\n", q);

			long long def = INF;
			long long x=-1;
			for (long long j=0; j<sums.size(); j++)
			{
				if (def > abs(sums[j]-q))
				{
					def = min(def, abs(sums[j]-q));
					x = sums[j];
				}
			}

			//prlong longf("Closest sum to %d is %d.\n", q, x);
			cout << "Closest sum to "<<q<<" is " << x << ".\n";
		}

		z+=1;
	}

	return 0;
}