#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	if (argc >1) freopen(argv[1], "r", stdin);

	int n,m,k,i,j,z, bil;
	int sum;
	string s;
	int pay[300];
	char c;

	scanf("%d", &n);

	for (z=0; z<n; z++)
	{
		scanf("%d", &k);
		getchar();
		memset(pay, 0, sizeof(pay));

		for (i=0; i<k; i++)
		{
			c = getchar();
			scanf("%d", &bil);
			getchar();

			pay[c+128] = bil;
		}

		// for (i=0; i<300; i++)
		// {
		// 	if (pay[i] >0) printf("%c %d\n",i-128, pay[i]);
		// }

		scanf("%d", &m);
		sum=0;
		for (i=0; i<m; i++)
		{
			getline(cin, s);
			for (j=0; j<s.length(); j++)
			{

				sum += pay[s[j] + 128];
				//if (pay[s[j]+128] > 0) printf("%c %d %d %d\n",s[j], s[j], pay[s[j]+128], sum);
			}
		}
		//printf("%d\n",sum);

		printf("%d.", sum/100);

		if (sum %100 < 10)
		{
			printf("0");
		}
		printf("%d$\n", sum%100);
	}

	if (argc >1) fclose(stdin);

	return 0;
}