#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#define INF 402

struct Node
{
	int data;
	Node *left, *right;	
};

int maxDepth;
int maxLeft, maxRight;
int sum[INF];

void readTree(Node *curNode, int depth)
{
	maxDepth=max(maxDepth, depth);
	int left;
	scanf("%d", &left);
	if (left != -1)
	{
		curNode->left = new Node;
		curNode->left->data = left;
		curNode->left->left=NULL;
		curNode->left->right=NULL;

		readTree(curNode->left, depth+1);
	}

	int right;
	scanf("%d", &right);
	if (right != -1)
	{
		curNode->right = new Node;
		curNode->right->data = right;
		curNode->right->left=NULL;
		curNode->right->right=NULL;

		readTree(curNode->right, depth+1);
	}
}

void createSum(Node *curNode, int pos)
{
	sum[pos] += curNode->data;

	maxLeft = min(maxLeft, pos);
	maxRight = max(maxRight, pos);
	if (curNode->left != NULL) createSum(curNode->left, pos-1);
	if (curNode->right != NULL) createSum(curNode->right, pos+1);
}

int main()
{
	int temp=0;
	int z=1;
	while (temp!=-1)
	{
		scanf("%d", &temp);

		if (temp==-1) break;

		for (int i=0; i<INF; i++) sum[i]=0;
		maxDepth=0;

		Node *root = new Node;
		root->data = temp;
		root->left = NULL;
		root->right = NULL;

		readTree(root,1);

		maxLeft = 200;
		maxRight=200;
		createSum(root, 200);

		printf("Case %d:\n", z);
		z+=1;

		for (int i=maxLeft; i<=maxRight; i++)
		{
			if (i>maxLeft) printf(" ");
			printf("%d", sum[i]);
		}

		printf("\n\n");
	}
	return 0;
}