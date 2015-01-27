#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

struct Data
{
	string s;
	int steps;
};

unordered_map<string, int> left;
unordered_map<string, int> right;
string source, dest;
int n;
bool found=false;

void reset()
{
	left.clear();
	right.clear();
	found=false;

	dest = "";
	source = "";
	for (int i=1; i<=n; i++)
	{
		dest+=(48+i);
	}
}

void findLeft()
{
	Data first;
	first.s = source;
	first.steps = 0;

	queue<Data> q;
	q.push(first);

	while (!q.empty())
	{

		Data cur = q.front();
		//fprintf(stderr, "left %s %d\n", cur.s.c_str(), cur.steps);
		q.pop();

		if (cur.s == dest)
		{
			printf("%d\n", cur.steps);
			found=true;
			break;
		}

		if (cur.steps <= (n/2))
		{
			//fprintf(stderr, "%d\n", n);
			for (int i=0; i<n; i++)
			{
				for (int j=1; j<=(n-i); j++)
				{
					//fprintf(stderr, "%d %d\n", i,j);
					string a = cur.s.substr(i, j);
					string b = cur.s;
					
					b.erase(i,j);

					for (int k=0; k<=b.length(); k++)
					{
						string c = b;
						c.insert(k, a);

						//fprintf(stderr, "%s %s %s\n", a.c_str(), b.c_str(), c.c_str());
						if (left.count(c) ==0)
						{
							left.insert(pair<string, int> (c, cur.steps+1));
							Data newData;
							newData.s = c;
							newData.steps = cur.steps+1;
							q.push(newData);
						}
					}
				}
			}
		}
	}
}

void findRight()
{
	Data first;
	first.s = dest;
	first.steps = 0;

	queue<Data> q;
	q.push(first);

	int mn=0;

	while (!q.empty())
	{
		Data cur = q.front();
		q.pop();

		//fprintf(stderr, "right %s %d\n", cur.s.c_str(), cur.steps);

		if (left.count(cur.s) >0)
		{
			left[cur.s] += cur.steps;
			mn = min(left[cur.s], mn);
			found=true;
			break;
		}

		if (cur.steps <= (n/2))
		{
			for (int i=0; i<n; i++)
			{
				for (int j=1; i+j-1<n; j++)
				{
					string a = cur.s.substr(i, j);
					string b = cur.s;
					b.erase(i,j);

					for (int k=0; k<=b.length(); k++)
					{
						string c = b;
						c.insert(k, a);

						if (right.count(c) ==0)
						{
							right.insert(pair<string, int> (c, cur.steps+1));
							Data newData;
							newData.s = c;
							newData.steps = cur.steps+1;
							q.push(newData);
						}
					}
				}
			}
		}
	}

	printf("%d\n", mn);
}

int main()
{
	n=-1;
	int z=1;
	while (n!=0)
	{
		scanf("%d", &n);
		if (n==0) break;

		reset();
		int x;
		for (int i=0; i<n; i++)
		{
			scanf("%d", &x);
			source += (x+48);
		}

		printf("Case %d: ", z);
		findLeft();
		if (!found) findRight();
		z+=1;
	}
	return 0;
}