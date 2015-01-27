#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct Node
{
	int start,end,count;
	int left, right;
};

vector<Node> tree;
int t,n,p;
int a,b;

int constructTree(int x, int y)
{
	int pos;
	if (x > y) return -1;

	Node node;
	node.start = x;
	node.end = y;
	node.count = 0;
	tree.push_back(node);
	pos = tree.size()-1;

	if (x<y)
	{
		node.left = constructTree(x, (x+y)/2);
		node.right = constructTree(x, ((x+y)/2)+1);
	}

	return pos;
}

void update(int x, int y, Node curNode)
{
	if ((x==curNode.start) && (y == curNode.start))
	{
		
	}
}

int main()
{
	scanf("%d", &t);
	for (z=1; z<=t; z++)
	{
		scanf("%d", &n);
		for (i=0; i<n; i++)
		{
			scanf("%d%d", &a, &b);

		}
	}
	return 0;
}