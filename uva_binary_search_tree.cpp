#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

struct Node
{
	int data;
	Node *left, *right;
};

Node *root = NULL;

void insert(int bil)
{
	if (root == NULL)
	{
		root = new Node;
		root->data = bil;
		root->left = NULL;
		root->right = NULL;
	}
	else
	{
		Node *traverse = root;
		Node *newNode = new Node;
		newNode->data = bil;
		newNode->left = NULL;
		newNode->right = NULL;	

		while (traverse != NULL)
		{
			if (traverse->data > bil)
			{
				if (traverse->left == NULL)
				{
					traverse->left = newNode;
					break;
				}
				else
					traverse = traverse->left;
			}
			else
			{
				if (traverse->right == NULL)
				{
					traverse->right = newNode;
					break;
				}
				else
					traverse = traverse->right;
			}
		}
	}
}

void postOrder(Node *cur)
{
	if (cur->left != NULL) postOrder(cur->left);
	if (cur->right != NULL) postOrder(cur->right);
	printf("%d\n", cur->data);
}

void OPEN(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main()
{
	//OPEN("binary_search_tree");
	int x;
	while (scanf("%d", &x) != EOF) insert(x);

	postOrder(root);

	return 0;
}