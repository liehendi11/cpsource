#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <iostream>
#include <string>

using namespace std;

vector<int> subord[202];
pair<int, bool> dp[202][2];
map<string, int> nameMap;
int n;

void reset()
{
	for (int i=0; i<202; i++)
	{
		subord[i].clear();
		dp[i][0].first = -1;
		dp[i][1].first = -1;
	}
	nameMap.clear();
}

pair<int, bool> compute(int idx, int bossChosen)
{
	if (dp[idx][bossChosen].first == -1)
	{
		int res = 0;
		bool unique = true;

		if (bossChosen == 0)
		{
			if (subord[idx].size() ==0)
			{
				res=1;
				unique=true;
			}
			else
			{
				int sum = 0;
				int childUnique = true;
				for (int i=0; i<subord[idx].size(); i++)
				{
					pair<int, bool> temp = compute(subord[idx][i], 1);	
					sum+= temp.first;
					childUnique = childUnique & temp.second;
				}
				
				sum+=1;

				res = sum;
				unique = childUnique;
			}
		}

		int sum = 0;
		int childUnique = true;
		for (int i=0; i<subord[idx].size(); i++)
		{
			pair<int, bool> temp = compute(subord[idx][i], 0);
			sum+= temp.first;
			childUnique = childUnique & temp.second;
		}

		if (sum > res)
		{
			res = sum;
			unique = childUnique;
		}
		else
			if (sum==res) unique = false;

		dp[idx][bossChosen] = pair<int, bool> (res, unique);
	}

	return dp[idx][bossChosen];
}

void OPEN(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main()
{
	n=-1;
	while (n!=0)
	{
		scanf("%d", &n);
		if (n==0) break;

		reset();

		string boss, employee;
		cin >> boss;
		nameMap.insert(pair<string, int> (boss, 0));

		int x = 0;

		for (int i=0; i<n-1; i++)
		{
			cin >> employee >> boss;

			int idxEmp, idxBoss;

			if (nameMap.count(boss) == 0)
			{
				x+=1;
				nameMap.insert(pair<string, int> (boss, x));
				idxBoss = x;
			}
			else
				idxBoss = nameMap[boss];

			if (nameMap.count(employee) == 0)
			{
				x+=1;
				nameMap.insert(pair<string, int> (employee, x));
				idxEmp = x;
			}
			else
				idxEmp = nameMap[employee];

			subord[idxBoss].push_back(idxEmp);
		}

		// for (int i=0; i<n; i++)
		// {
		// 	printf("%d : ", i);
		// 	for (int j=0; j<subord[i].size(); j++)
		// 	{
		// 		printf("%d ", subord[i][j]);
		// 	}

		// 	printf("\n");
		// }

		pair<int, bool> res = compute(0, 0);

		if (res.second) printf("%d Yes\n", res.first);
		else
			printf("%d No\n", res.first);
	}

	return 0;
}