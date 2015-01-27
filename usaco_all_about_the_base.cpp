#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
#include <string>

using namespace std;

long long convertBase(int base, int multi)
{
	return (base%10) + (((base/10) %10) * multi) + (((base/100) %10) * multi * multi);
}

int findMaxBase(int base)
{
	return max(max(base%10, (base/10)%10), (base/100)%10);
}

void OPEN(string inputFile, string outputFile) {
	freopen(inputFile.c_str(), "r", stdin);
	freopen(outputFile.c_str(), "w", stdout);
}

int main()
{
	OPEN("whatbase.in", "whatbase.out");
	int k, base1, base2;

	scanf("%d", &k);

	for (int z=0; z<k; z++)
	{
		unordered_map<long long, int> baseMap;

		int base1, base2;
		scanf("%d%d", &base1, &base2);
		int res1, res2;


		//first pass
		for (int i=10; i<=15000; i++)
		{
			long long res = convertBase(base1, i);
			// if (i<10) printf("%lld %d\n", res, i);
			baseMap.insert(pair<long long, int> (res, i));
		}

		for (int i=10; i<=15000; i++)
		{
			long long res = convertBase(base2, i);

			if (baseMap.count(res) > 0)
			{
				res1 = baseMap[res];
				res2 = i;
				break;
			}
			
		}

		printf("%d %d\n", res1, res2);
	}

	return 0;
}