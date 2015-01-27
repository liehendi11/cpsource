#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

string s;

void process()
{
	for (int i=1; i<=(s.length()/2); i++)
	{
		if (s.length() % i ==0)
		{
			bool yes = true;
			for (int j=0; j<i; j++)
			{
				int x=j+i;
				while (x<s.length())
				{
					if (s[j] != s[x])
					{
						yes=false;
						break;
					}
					x+=i;
				}

				if (!yes) break;
			}

			if (yes)
			{
				printf("%d\n", i);
				return;
			}
		}
	}

	printf("%d\n", (int) s.length());
}

int main()
{
	int tc;
	scanf("%d", &tc);
	//getchar();
	for (int z=1; z<=tc; z++)
	{
		cin >> s;
		// getchar();

		// cout << s << endl;

		if (z>1) printf("\n");
		process();

	}
	return 0;
}
