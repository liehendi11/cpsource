#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

struct Node
{
	char data;
	Node *left, *right;
};

struct Data
{
	int mn, mx, mid;
	Node *curNode;
};

int pos[54];

int findCharPosition(char c)
{
	if ((c >= 65) && (c<=90)) return c-65;
	else
		return c-71;
}

void postorder(Node *curNode)
{
	if (curNode->left != NULL) postorder(curNode->left);
	if (curNode->right != NULL) postorder(curNode->right);
	printf("%c", curNode->data);
}

int main()
{
	int tc;
	scanf("%d", &tc);
	getchar();
	for (int z=1; z<=tc; z++)
	{
		int n;
		string preorder, inorder;
		cin >> n >>  preorder >> inorder;
		getchar();

		for (int i=0; i<54; i++) pos[i] = -1;

		for (int i=0; i<n; i++)
		{
			pos[findCharPosition(inorder[i])] = i;
		}	

		stack<Data> st;

		Node *root = new Node;
		root->data = preorder[0];
		root->left = NULL;
		root->right = NULL;

		Data newData;
		newData.mn = 0;
		newData.mx = n-1;
		newData.mid = pos[findCharPosition(preorder[0])];
		newData.curNode = root;
		st.push(newData);

		

		for (int i=1; i<n; i++)
		{
			bool found=false;
			int posx = pos[findCharPosition(preorder[i])];

			Node *newNode = new Node;
			newNode->data = preorder[i];
			newNode->left = NULL;
			newNode->right = NULL;


			while (!found)
			{
				Data curData = st.top();

				// printf("%d %d %d %d\n", posx, curData.mn, curData.mid, curData.mx);
				if ((posx < curData.mid) && (curData.mn <= posx))
				{
					curData.curNode->left = newNode;

					Data newData;
					newData.mn = curData.mn;
					newData.mid = posx;
					newData.mx = curData.mid-1;
					newData.curNode = newNode;
					st.push(newData);

					found=true;
				}
				else
					if ((curData.mid< posx) && (posx <= curData.mx))
					{
						curData.curNode->right = newNode;

						Data newData;
						newData.mn = curData.mid+1;
						newData.mid = posx;
						newData.mx = curData.mx;
						newData.curNode = newNode;
						st.push(newData);

						found=true;
					}
					else
						st.pop();
			}

		}


		postorder(root);
		printf("\n");
	}

	return 0;
}