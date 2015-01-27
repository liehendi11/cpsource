#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <stack>

using namespace std;

vector<int> numbers, seqCount, seqPoint;

void lis()
{
	int maxCount=1; int maxPoint=0;
	for (int i=0; i<numbers.size(); i++)
	{
		int tempCount=0;
		int tempPoint=-1;

		for (int j=0; j<i; j++)
		{
			if ((seqCount[j] >=tempCount) && (numbers[j] < numbers[i]))
			{
				tempCount = seqCount[j];
				tempPoint = j;
			}
		}

		tempCount+=1;

		seqCount.push_back(tempCount);
		seqPoint.push_back(tempPoint);

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
	freopen((s + ".out").c_str(), "w", stdout);
}

int main()
{
	// OPEN("what_goes_up");
	int bil;

	while (scanf("%d", &bil) != EOF)
	{
		numbers.push_back(bil);
	}

	lis();
	return 0;
}