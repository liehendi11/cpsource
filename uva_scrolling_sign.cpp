#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<string> signs;
int k,w;

void process()
{
	int length=k;

	for (int x=1; x<signs.size(); x++)
	{
		int a=k-1;
		int b=0;

		string sa="",sb="";
		int mxLength = 0;

		while (a>=0)
		{
			sa = signs[x-1][a] + sa;
			sb = sb + signs[x][b];

			if (sa == sb)
			{
				mxLength = max(mxLength, (int) sa.length());
			}

			a-=1;
			b+=1;
		}

		length = length + (k-mxLength);
	}

	printf("%d\n", length);
}

int main()
{
	int tc;
	scanf("%d", &tc);
	for (int z=1; z<=tc; z++)
	{
		scanf("%d%d", &k, &w);
		getchar();

		string s;
		signs.clear();
		for (int i=0; i<w; i++)
		{
			getline(cin, s);
			signs.push_back(s);
		}

		process();
	}
	return 0;
}