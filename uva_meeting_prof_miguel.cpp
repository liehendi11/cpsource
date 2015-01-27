#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#define INF 10000000LL

int young[28][28];
int adult[28][28];
int source1, source2;

void reset()
{
	for (int i=0; i<28; i++)
	{
		for (int j=0; j<28; j++)
		{
			if (i!=j)
			{
				young[i][j]=INF;
				adult[i][j]=INF;	
			}
			else
			{
				young[i][j]=0;
				adult[i][j]=0;
			}
		}
	}
}

void floyd_warshall()
{
	for (int k=1; k<=26; k++)
	{
		for (int i=1; i<=26; i++)
		{
			for (int j=1; j<=26; j++)
			{
				young[i][j] = min(young[i][j], young[i][k]+young[k][j]);
				adult[i][j] = min(adult[i][j], adult[i][k]+adult[k][j]);
			}
		}
	}

	int mn = INF;
	for (int i=1; i<=26; i++) mn = min(young[source1][i] + adult[source2][i], mn);
	
	if (mn < INF)
	{
		printf("%d", mn);
		for (int i=1; i<=26; i++)
		{
			if (young[source1][i] + adult[source2][i] == mn)
			{
				printf(" %c", i+64);
			}
		}	
	}
	else
	printf("You will never meet.");
	
	printf("\n");
}

void printMatrix()
{
	printf("Young\n");
	for (int i=1; i<=26; i++)
	{
		for (int j=1; j<=26; j++)
		{
			if (young[i][j] < INF) printf("%d ", young[i][j]);
			else
				printf("X ");
		}
	}
	printf("\n");

	printf("Adult\n");
	for (int i=1; i<=26; i++)
	{
		for (int j=1; j<=26; j++)
		{
			if (adult[i][j] < INF) printf("%d ", adult[i][j]);
			else
				printf("X ");
		}
	}
	printf("\n");
}

int main()
{
	int n=-1;

	while (n!=0)
	{
		scanf("%d", &n);
		getchar();
		if (n==0) break;

		reset();
		char type, direction, source, dest;
		int weight;
		for (int i=0; i<n; i++)
		{
			scanf("%c %c %c %c %d", &type, &direction, &source, &dest, &weight);
			getchar();

			if (source != dest)
			{
				if (type=='Y')
				{
					young[source-64][dest-64] = weight;
					if (direction == 'B') young[dest-64][source-64] = weight;
				}

				if (type=='M')
				{
					adult[source-64][dest-64] = weight;
					if (direction == 'B') adult[dest-64][source-64] = weight;
				}	
			}
			
		}

		scanf("%c %c", &source, &dest);

		source1 = source-64;
		source2 = dest-64;

		// if (source1 == source2)
		// {
		// 	printf("0 %c\n", source1+64);
		// }
		//else
		floyd_warshall();

		//printMatrix();
	}
	return 0;
}