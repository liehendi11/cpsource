#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int tc,n;
	scanf("%d", &tc);
	vector<string> phone_numbers;
	for (int z=1; z<=tc; z++)
	{
		scanf("%d", &n);
		string s;
		phone_numbers.clear();
		for (int i=0; i<n; i++)
		{
			cin >> s;
			phone_numbers.push_back(s);
		}

		sort(phone_numbers.begin(), phone_numbers.end());

		bool consistent = true;
		for (int i=0; i<n-1; i++)
		{
			int j=i+1;
			bool same=true;
			for (int k=0; k<min(phone_numbers[i].length(), phone_numbers[j].length()); k++)
			{
				if (phone_numbers[i][k] != phone_numbers[j][k])
				{
					same=false;
					break;
				}
			}

			if (same)
			{
				consistent=false;
				break;
			}

			if (!consistent) break;
		}

		if (consistent) printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}