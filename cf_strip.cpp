#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;



class Node
{
public:
	int start, end, minValue, maxValue;
	Node *left, *right;
	Node(int, int);
	pair<int, int> constructTree(vector<int>&);
	int findMax(int, int);
	int findMin(int, int);
	void traverse();
};

Node::Node(int x, int y)
{
	start = x;
	end = y;
	minValue = 1000000000LL;
	maxValue = 0;
	left = NULL;
	right = NULL;
}

pair<int, int> Node::constructTree(vector<int> &numbers)
{
	if (start != end)
	{
		int mid = (start+end)/2;

		left = new Node(start, mid);
		pair<int, int> res = left->constructTree(numbers);
		minValue = res.first;
		maxValue = res.second;

		right = new Node(mid+1, end);
		res = right->constructTree(numbers);
		minValue = min(res.first, minValue);
		maxValue = max(res.second, maxValue);
	}
	else
	{
		minValue = numbers[start];
		maxValue = numbers[start];
	}

	return pair<int, int> (minValue, maxValue);
}

int Node::findMax(int x, int y)
{
	if ((start == x) && (end == y)) return maxValue;

	int res = 0;
	int mid = (start+end)/2;

	if ((start <= x) && (x <= mid)) res = max(res, left->findMax(x, min(mid, y)));
	if ((mid+1 <= y) && (y <= end)) res = max(res, right->findMax(max(x, mid+1), y));

	return res;
}

int Node::findMin(int x, int y)
{
	if ((start == x) && (end == y)) return minValue;

	int res = 1000000000LL;
	int mid = (start+end)/2;

	if ((start <= x) && (x <= mid)) res = min(res, left->findMin(x, min(mid, y)));
	if ((mid+1 <= y) && (y <= end)) res = min(res, right->findMin(max(x, mid+1), y));

	return res;
}

void Node::traverse()
{
	if (left != NULL) left->traverse();
	printf("%d %d %d %d\n", start, end, minValue, maxValue);
	if (right != NULL) right->traverse();
}

int n,s,l;
vector<int> numbers;
int dp[100002];
Node *root;

void reset()
{
	memset(dp, -1, sizeof(dp));
	numbers.clear();
}

int compute(int idx)
{
	if (idx == n)
		return 0;

	if (dp[idx] == -1)
	{
		int res = n+2;
		for (int i=l; i<n-idx+1; i++)
		{
			// printf("%d\n", i);
			if ((root->findMax(idx, idx+i-1) - root->findMin(idx, idx+i-1)) <= s) 
			{
				res = min(res, compute(idx+i) +1);
				// printf("%d %d %d %d\n", abs(root->findMax(idx, idx+i-1) - root->findMin(idx, idx+i-1)), i, idx, idx+i-1);
			}
				
		}

		// printf("%d %d\n", idx, res);

		dp[idx] = res;
	}

	return dp[idx];
}


int main()
{
	reset();
	scanf("%d%d%d", &n, &s, &l);

	int x;
	for (int i=0; i<n; i++)
	{
		scanf("%d", &x);
		numbers.push_back(x);
	}

	root = new Node(0, n-1);
	root->constructTree(numbers);

	// root->traverse();

	// printf("%d\n", root->findMin(0, 3));
	// printf("%d\n", root->findMin(6, 6));

	int res = compute(0);

	// printf("%d\n", res);

	if (res <= n) printf("%d\n", res);
	else
		printf("-1\n");

	return 0;
}