#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

vector<int> occurences[1000002];

void reset()
{
	for (int i=0; i<1000002; i++) occurences[i].clear();
}

int main()
{
	int n,m;

	while (scanf("%d%d", &n, &m) != EOF)
	{
		int x;
		reset();
		for (int i=0; i<n; i++)
		{
			scanf("%d", &x);
			occurences[x].push_back(i+1);
		}

		int k,v;
		for (int i=0; i<m; i++)
		{
			scanf("%d%d", &k, &v);
			if (k > occurences[v].size()) printf("0\n");
			else
				printf("%d\n", occurences[v][k-1]);
		}
	}
	return 0;
}