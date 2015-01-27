#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <stack>

using namespace std;

struct Node
{
	char data;
	Node *left, *right;
};

struct Data
{
	int left, right, cur;
	Node *curNode;
};

string preorder, inorder;
int pos[27];

void reset()
{
	for (int i=0; i<27; i++) pos[i]=-1;
}

void traverse(Node *node)
{
	if (node->left != NULL) traverse(node->left);
	if (node->right != NULL) traverse(node->right);
	printf("%c", node->data);
}

void OPEN(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main()
{
	//OPEN("tree_recovery");
	while (!(cin.eof()))
	{
		cin >> preorder >> inorder;
		getchar();
		reset();

		stack<Data> orders;
		for (int i=0; i<inorder.size(); i++) pos[inorder[i]-65] = i;
		
		Node *root = new Node;
		root->data = preorder[0];
		root->left = NULL;
		root->right = NULL;

		Data newData;
		newData.left = 0;
		newData.right = preorder.size()-1;
		newData.cur = pos[preorder[0]-65];
		newData.curNode = root;
		orders.push(newData);


		for (int i=1; i<preorder.size(); i++)
		{
			bool found=false;
			int posx = pos[preorder[i]-65];

			Node *newNode = new Node;
			newNode->data = preorder[i];
			newNode->left=NULL;
			newNode->right=NULL;

			while (!found)
			{
				Data curData = orders.top();
				//printf("%d %d %d %d\n", posx, curData.left, curData.cur, curData.right);
				
				if ((posx < curData.cur) && (posx >= curData.left) && (posx <= curData.right))
				{
					//left
					curData.curNode->left = newNode;

					Data newData;
					newData.left = curData.left;
					newData.right = curData.cur-1;
					newData.cur = posx;
					newData.curNode = newNode;
					orders.push(newData);

					found=true;
				}
				else
					if ((posx > curData.cur) && (posx >= curData.left) && (posx <= curData.right))
					{
						//right
						curData.curNode->right = newNode;
					
						Data newData;
						newData.right = curData.right;
						newData.left = curData.cur+1;
						newData.cur = posx;
						newData.curNode = newNode;
						orders.push(newData);

						found=true;
					}
					else
						orders.pop();
			}
		}

		traverse(root);
		printf("\n");
	}


	return 0;
}