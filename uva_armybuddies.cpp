#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
	int s,b, i, j, x,y;
	int left[100002], right[100002];
	s=-1;
	b=-1;

	while (true)
	{
		scanf("%d%d", &s, &b);

		if ((s==0) && (b==0)) break;
		for (i=1; i<=s; i++)
		{
			left[i] = i-1;
			right[i] = i+1;
			if (i==1) left[i] = -1;
			if (i==s) right[i] = -1;
		}

		for (i=0; i<b; i++)
		{
			scanf("%d%d", &x, &y);

			if (left[x] == -1)
			{
				printf("* ");
			}
			else
				printf("%d ", left[x]);

			if (right[y] == -1) printf("*\n");
			else
				printf("%d\n", right[y]);

			if (left[x] != -1) right[left[x]] = right[y];
			if (right[y] != -1) left[right[y]] = left[x];
			
			//right[x-1] = right[y];
			// left[y+1] = left[x-1];
		}
		printf("-\n");
	}

	return 0;
}