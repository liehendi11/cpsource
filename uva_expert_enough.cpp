#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Data
{
	string name;
	int lowest, highest;
};

vector<Data> makers;

string search(int x)
{
	string res="";
	int ctr=0;

	for (int i=0; i<makers.size(); i++)
	{
		if ((makers[i].lowest <= x) && (x<= makers[i].highest))
		{
			ctr+=1;
			res = makers[i].name;
		}
	}

	if (ctr ==1) return res;
	else
		return "UNDETERMINED";
}

int main()
{
	int tc;
	scanf("%d", &tc);

	for (int z=1; z<=tc; z++)
	{
		makers.clear();
		int n,m;
		Data in;

		scanf("%d", &n);
		for (int i=0; i<n; i++)
		{
			cin >> in.name >> in.lowest >> in.highest;
			makers.push_back(in);
		}
		
		if (z>1) printf("\n");
		int q;
		scanf("%d", &m);
		for (int i=0; i<m; i++)
		{
			cin >> q;
			cout << search(q) << endl;
		}
	}

	return 0;
}