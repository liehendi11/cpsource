#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
	int n, i, j, ctr;
	int bil[3002];
	bool appeared[3002];
	
	while (scanf("%d",&n) != EOF)
	{
		memset(appeared, false, sizeof(appeared));

		for (i=0; i<n; i++)
		{
			scanf("%d", &bil[i]);
		}

		ctr = 0;
		for (i=0; i<n-1; i++)
		{
			int diff = abs(bil[i]-bil[i+1]);
			if ((appeared[diff] == false) && (diff >=0) && (diff <= (n-1)))
			{
				appeared[diff]=true;
				ctr+=1;
			}
		}

		if (ctr == n-1) printf("Jolly\n");
		else
			printf("Not jolly\n");
	}



	return 0;
}