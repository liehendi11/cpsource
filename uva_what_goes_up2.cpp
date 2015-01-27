#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <stack>

using namespace std;

#define SIZE 200005

int numbers[SIZE], seqCount[SIZE], seqPoint[SIZE];
int tempSeq[SIZE], tempSeqIdx[SIZE];
int n;

int binarySearch(int q, int upperBound)
{
	int mx = upperBound;
	int mn = 0;
	int res = -1;

	while (mx>= mn)
	{
		int mid = (mx+mn)/2;
		if (tempSeq[mid] < q)
		{
			res = mid;
			mn = mid+1;
		}
		else
			mx = mid-1;
	}

	return res;
}

void printSeq(int mx)
{
	for (int i=0; i<=mx; i++)
	{
		fprintf(stderr, "%d ", tempSeq[i]);
		if (i==mx) fprintf(stderr, "|");
	}

	fprintf(stderr, "\n");
}

void lis()
{
	int maxCount=1; int maxPoint=0;
	
	int mx=-1;
	for (int i=0; i<n; i++)
	{
		int tempCount=0;
		int tempPoint=-1;

		int pos = binarySearch(numbers[i], mx)+1;

		printSeq(mx);

		tempSeq[pos] = numbers[i];
		tempSeqIdx[pos] = i;

		if (pos == 0) tempPoint=-1;
		else
			tempPoint = tempSeqIdx[pos-1];
		
		mx=pos;
		tempCount=mx+1;

		
		fprintf(stderr, "%d %d %d %d %d\n", i, numbers[i], pos, tempCount, tempPoint);
		printSeq(mx);
		fprintf(stderr, "-------------------\n");

		seqCount[i]= tempCount;
		seqPoint[i] = tempPoint;

		if (tempCount >= maxCount)
		{
			maxCount = tempCount;
			maxPoint = i;
		}
	}

	printf("%d\n-\n", maxCount);

	stack<int> st;
	while ((maxPoint!=-1))
	{
		//printf("%d\n", numbers[maxPoint]);
		st.push(numbers[maxPoint]);
		maxPoint = seqPoint[maxPoint];
	}

	while (!st.empty())
	{
		printf("%d\n", st.top());
		st.pop();
	}
}

void OPEN(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen("debug.txt", "w", stderr);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main()
{
	OPEN("what_goes_up");
	int bil;
	n=0;

	while (scanf("%d", &bil) != EOF)
	{
		numbers[n] = bil;
		n+=1;
	}

	lis();
	return 0;
}