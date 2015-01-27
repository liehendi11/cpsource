#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n,p;
int distArr[100002];
string s;

int findCharDist(char a, char b)
{
	int first = max(a,b);
	int second = min(a,b);

	return min((first-second), (second+26)-first);
}

int findSmallestLeft()
{
	for (int i=0; i<n/2; i++)
	{
		if (distArr[i]>0) return i;
	}
}

int findBiggestLeft()
{
	for (int i=(n/2)-1; i>=0; i--)
	{
		if (distArr[i]>0) return i;
	}
}

int findSmallestRight()
{
	for (int i=n/2; i<n; i++)
	{
		if (distArr[i]>0) return i;
	}
}

int findBiggestRight()
{
	for (int i=n-1; i>=(n/2); i--)
	{
		if (distArr[i]>0) return i;
	}
}

int main()
{
	memset(distArr, 0, sizeof(distArr));

	scanf("%d%d", &n, &p);

	p-=1;
	getchar();

	getline(cin, s);
	long long sumDist=0;

	for (int i=0; i<(n/2); i++)
	{
		if (s[i] != s[n-i-1])
		{
			distArr[i] = findCharDist(s[i], s[n-i-1]);
			distArr[n-i-1] = distArr[i];
		}
		else
		{
			distArr[i] = 0;
			distArr[n-i-1] = distArr[i];
		}
		sumDist += distArr[i];
	}

	//special case, the pointer is on the middle
	if ((n%2==1) && (p== ((n/2))))
	{
		//cout << "Here" << endl;
		int left = findSmallestLeft();
		cout << abs(p-left)+sumDist<<endl;
		return 0;
	}

	if (p<n/2)
	{
		// printf("Left\n");
		int left = findSmallestLeft();
		int right = findBiggestLeft();

		//printf("%d %d %lld\n", left, right, sumDist);

		//case where it is on the left, goes straight to left, destroy everything on path, goes back on right
		long long cyclicCost = p + 1 + ((n-1) - findSmallestRight()) + sumDist;

		// cout << cyclicCost << endl;
		// cout << p + 1 << " " << (n-1)-findSmallestRight() << " " << sumDist << endl;

		if ((left <= p) && (right<=p)) cout << sumDist + abs(p-left) << endl; //right extreme
		else
			if ((p <= left) && (p<=right)) cout << sumDist + abs(p-right) << endl; //left extreme
		else
		{
			//middle
			//cout << (min(abs(p-left), abs(p-right)) *2) << " " << max(abs(p-left), abs(p-right)) << endl;
			cout << min((sumDist + (min(abs(p-left), abs(p-right)) *2) + max(abs(p-left), abs(p-right))), cyclicCost) << endl;
		}
			
	}
	else
	{
		///printf("Right\n");
		int left = findSmallestRight();
		int right = findBiggestRight();

		long long cyclicCost = n-p+findBiggestLeft() + sumDist;

		// cout << cyclicCost << endl;

		if ((left <= p) && (right<=p)) cout << sumDist + abs(p-left) << endl; 
		else
			if ((p <= left) && (p<=right)) cout << sumDist + abs(p-right) << endl;
		else
			cout << min((sumDist + (min(abs(p-left), abs(p-right)) *2) + max(abs(p-left), abs(p-right))), cyclicCost) << endl;
	}

	return 0;
}