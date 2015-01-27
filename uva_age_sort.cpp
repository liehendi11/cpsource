#include <stdio.h>
#include <stdlib.h>
#include <cstring>

using namespace std;

int arr[102];
bool isFirst;

void reset()
{
	memset(arr, 0, sizeof(arr));
	isFirst = true;
}

int main()
{
	int n=-1;
	while (n!=0)
	{
		scanf("%d", &n);
		if (n==0) break;

		reset();
		int x;
		for (int i=0; i<n; i++)
		{
			scanf("%d", &x);
			arr[x] +=1;
		}

		for (int i=1; i<=100;i++)
		{
			for (int j=0; j<arr[i]; j++)
			{
				if (isFirst)
				{
					printf("%d", i);
					isFirst=false;
				}
				else
					printf(" %d", i);
			}
		}

		printf("\n");
	}
	return 0;
}