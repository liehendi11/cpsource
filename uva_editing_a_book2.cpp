#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

struct Data
{
	int s;
	int steps;
};

unordered_map<int, int> left;
unordered_map<int, int> right;
int source, dest;
int n;
bool found=false;

void reset()
{
	left.clear();
	right.clear();
	found=false;

	dest = 0;
	source = 0;
	for (int i=1; i<=n; i++)
	{
		dest = (dest*10) + i;
	}
}

int copy(int init, int start, int len)
{
	int divider = pow(10, n-start-len);
	int moduler = pow(10, len);

	return ((init/divider) % moduler);
}

int remove(int init, int start, int len)
{
	int firstHalf = copy(init, 0, start);
	int secondHalf = copy(init, start+len, n-start-len);
	return (firstHalf*pow(10, n-start-len)) + secondHalf;
}

int insert(int init, int start, int data)
{
	int dataLength = log10(data);
	int initLength = log10(init)+1;

	int left = copy(init, 0, start);
	int right = copy(init, start, initLength-start+1);
	printf("insert %d %d %d %d %d\n",dataLength, initLength, left, right, data);

	int res=0;
	res += copy(init, 0, start);
	res = res*pow(10, dataLength+1);
	res += data;
	res = res*pow(10, initLength-start);
	res+= copy(init, start, initLength-start+1);

	return res;
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
		fprintf(stderr, "left %d %d\n", cur.s, cur.steps);
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
				for (int j=1; j<(n-i); j++)
				{
					//fprintf(stderr, "%d %d\n", i,j);
					int a = copy(cur.s, i,j);
					int b = remove(cur.s, i,j);
					//printf("%d %d\n", a,b);
					
					
					for (int k=0; k<=log10(b); k++)
					{
						int c=insert(b,k,a);
						printf("%d %d %d %d\n", a,b,k,c);
						getchar();
						//fprintf(stderr, "%d\n", c);

						if (left.count(c) ==0)
						{
							left.insert(pair<int, int> (c, cur.steps+1));
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

		if (cur.steps <= (n+1/2))
		{
			for (int i=0; i<n; i++)
			{
				for (int j=1; i+j-1<n; j++)
				{
					int a = copy(cur.s, i,j);
					int b = remove(cur.s, i,j);
					// cur.s.substr(i, j);
					// string b = cur.s;
					// b.erase(i,j);

					for (int k=0; k<=log10(b); k++)
					{
						//string c = b;
						// c.insert(k, a);
						int c=insert(b,k,a);

						if (right.count(c) ==0)
						{
							right.insert(pair<int, int> (c, cur.steps+1));
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
			source = (source*10) + x;
		}

		printf("Case %d: ", z);
		findLeft();
		if (!found) findRight();
		z+=1;
	}
	// n=6;
	// //printf("%d\n", copy(12345,0,2));

	// for (int i=0; i<=6; i++)
	// {
	// 	printf("Insert 999 at %d: %d\n", i,insert(123456, i,999));
	// }
	
	return 0;
}