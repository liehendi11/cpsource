#include <stdio.h>
#include <stdlib.h>
#include <stack>

using namespace std;

int bil[1002];

int main()
{
	int n=-1;
	int z=1;
	while (n!=0)
	{
		
		scanf("%d", &n);
		if (n==0) break;

		//if (z>1) printf("\n");

		bil[0] = 1;
		while (bil[0] !=0)
		{
			scanf("%d", &bil[0]);
			if (bil[0]==0) break;

			for (int i=1; i<n; i++) scanf("%d", &bil[i]);
			
			stack<int> temp;

			int x = 0;
			for (int i=1; i<=n; i++)
			{	
				while (!temp.empty())
				{
					if (temp.top() == bil[x])
					{
						temp.pop();
						x+=1;
					}
					else
						break;
				}

				if (i == bil[x]) x+=1;
				else
					temp.push(i);
			}

			while (!temp.empty())
			{
				if (temp.top() == bil[x])
				{
					temp.pop();
					x+=1;
				}
				else
					break;
			}

			if (x==n)
				printf("Yes\n");
			else
				printf("No\n");	
		}

		printf("\n");
		z+=1;
	}

	return 0;
}