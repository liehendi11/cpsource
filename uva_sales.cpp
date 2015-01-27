#include <stdio.h>
#include <stdlib.h>

using namespace std;

int a[5002], b[5002];
int n,i,j,t,z;
int temp;
int sum;

int main()
{
	scanf("%d", &t);
	for (z=1; z<=t; z++)
	{
		scanf("%d", &n);

		for (i=0; i<n; i++)
		{
			scanf("%d", &a[i]);
		}

		temp=0;
		sum=0;

		for (i=1; i<n; i++)
		{
			temp=0;
			for (j=0; j<i; j++)
			{
				if (a[i] >= a[j]) temp+=1;
			}

			sum+=temp;
		}

		printf("%d\n", sum);
	}
	return 0;
}