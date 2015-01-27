#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

queue <int> q;


int main()
{
	int n=-1;
	while (n!=0)
	{
		scanf("%d", &n);
		if (n==0) break;

		for (int i=1; i<=n; i++) q.push(i);

		
		int z=0;

		vector<int> output;
		int res;
		while (!q.empty())
		{
			int a = q.front();
			q.pop();

			if (q.empty())
			{
				res = a;
			}
			else
			{
				z+=1;
				output.push_back(a);

				int b = q.front();
				q.pop();
				q.push(b);
			}
		}

		printf("Discarded cards:");
		for (int i=0; i<output.size(); i++)
		{
			printf(" %d", output[i]);
			if (i<output.size()-1) printf(",");
		}
		printf("\n");

		printf("Remaining card: %d\n", res);
	}
	return 0;
}