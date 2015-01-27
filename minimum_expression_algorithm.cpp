#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

int minimumExpression(string s) {
	s = s + s;
	int len = s.length();
	int i = 0, j = 1, k = 0;

	while((i + k < len) && (j + k < len))
	{
		if (s[i+k] == s[j+k]) k++;
		else if(s[i+k] > s[j+k])
		{
			i = i+k+1;
			if(i <= j) i = j+1;
			k = 0;
		}
		else if(s[i+k] < s[j+k])
		{
			j = j+k+1;
			if(j <= i) j = i+1;
			k = 0;
		}
	}
	return min(i, j);
}

int main()
{
	int tc;
	string str;
	scanf("%d", &tc);
	getchar();
	for (int z=1; z<=tc; z++)
	{
		getline(cin, str);

		printf("%d\n", minimumExpression(str)+1);
	}
	return 0;
}