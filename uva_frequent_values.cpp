#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Range
{
public:
	int lower, upper, num, count;
	Range(int xlow, int xup, int xnum, int xcount)
	{
		lower = xlow;
		upper = xup;
		num = xnum;
		count = xcount;
	}
};

class Node
{
public:
	Node *left, *right;
	int lower, upper;
	int value;
	Node(int x, int y)
	{
		lower = x;
		upper = y;
		value = 0;
		left = NULL;
		right = NULL;
	}

	int constructTree(vector<Range> &counts)
	{
		if (upper == lower)
			value = counts[lower].count;
		else
		{
			int xmid = (lower+upper)/2;

			left = new Node(lower, xmid);
			right = new Node(xmid+1, upper);

			value = max(left->constructTree(counts), right->constructTree(counts));
		}

		return value;
	}

	int findMax(int xlower, int xupper)
	{
		if (xlower > xupper) return 0;
		if ((lower == xlower) && (upper == xupper)) return value;
		else
		{
			int mid = (lower+upper)/2;
			int res = 0;

			if ((lower <= xlower) && (xlower <= mid)) res = max(res, left->findMax(xlower, min(xupper, mid)));
			if ((mid+1 <= xupper) && (xupper <= upper)) res = max(res, right->findMax(max(xlower, mid+1), xupper));

			return res;
		}
	}
};

vector<int> numbers;
vector<Range> counts;
unordered_map<int, int> countMap;
Node *root;

void preprocess()
{
	int prev = 0;
	int count = 1;
	for (int i=1; i<numbers.size(); i++)
	{
		if (numbers[i] == numbers[i-1]) count+=1;
		else
		{
			counts.push_back(Range(prev, i-1, numbers[i-1], count));
			countMap.insert(pair<int, int> (numbers[i-1], counts.size()-1));
			prev = i;
			count = 1;
		}
	}

	counts.push_back(Range(prev, numbers.size()-1, numbers[numbers.size()-1], count));
	countMap.insert(pair<int, int> (numbers[numbers.size()-1], counts.size()-1));

	root = new Node(0, counts.size()-1);
	root->constructTree(counts);
}

int findMax(int xlower, int xupper)
{
	int leftIdx = countMap[numbers[xlower]];
	int rightIdx = countMap[numbers[xupper]];

	if (leftIdx == rightIdx) return xupper-xlower+1;
	else
	{
		int leftCount = counts[leftIdx].upper - xlower + 1;
		int rightCount = xupper - counts[rightIdx].lower + 1;

		return max(max(leftCount, rightCount), root->findMax(leftIdx+1, rightIdx-1));
	}
}

int main()
{
	int n,q;
	while (scanf("%d", &n))
	{
		if (n==0) break;
		scanf("%d", &q);

		counts.clear();
		numbers.clear();
		countMap.clear();
		root = NULL;

		int a,b;
		for (int i=0; i<n; i++)
		{
			scanf("%d", &a);
			numbers.push_back(a);
		}

		preprocess();

		for (int i=0; i<q; i++)
		{
			scanf("%d%d", &a, &b);
			printf("%d\n", findMax(a-1,b-1));
		}
	}
	

	return 0;
}
