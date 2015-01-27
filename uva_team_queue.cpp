#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>

using namespace std;


struct Node
{
	int data;
	int team;
	struct Node* next;
};

class TeamQueue
{
	Node *head;
	Node *tail;
public:
	TeamQueue();
	void push(int, int);
	void pop();
	int front();
	void printQueue();
};

TeamQueue::TeamQueue()
{
	head = NULL;
	tail = NULL;
}

void TeamQueue::push(int bil, int team)
{
	Node *temp = new Node;
	if (head==NULL)
	{
		head = temp;
		head->team = team;
		head->data = bil;
		head->next = NULL;
		tail = head;
		tail->next = NULL;
		return;
	}
	else
	{
		Node *traverse = head;
		temp->data = bil;
		temp->team = team;

		while (traverse != NULL)
		{
			if (traverse->team == team)
			{
				if (traverse->next == NULL)
				{
					//end
					traverse->next = temp;
					temp->next = NULL;
					tail= temp;
					tail->next = NULL;
					return;
				}
				else
					if (traverse->next->team != team)
					{
						temp->next = traverse->next;
						traverse->next = temp;
						tail->next = NULL;
						return;
					}
			}
			
			traverse = traverse->next;
		}

		temp->next = NULL;
		tail->next = temp;
		tail = temp;
		tail->next = NULL;
		return;
	}
}

void TeamQueue::pop()
{
	if (head->next == NULL) head=NULL;
	else
		head=head->next;
}

int TeamQueue::front()
{
	return head->data;
}

void TeamQueue::printQueue()
{
	Node *traverse= head;
	while (traverse!=NULL)
	{
		printf("%d ", traverse->data);
		traverse = traverse->next;
	}
	printf("\n");
}

void OPEN(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main()
{
	//OPEN("test");
	int n=-1;
	int z=1;
	while (n!=0)
	{
		scanf("%d", &n);
		if (n==0) break;

		printf("Scenario #%d\n", z);

		map<int, int> teamMap;
		TeamQueue tq;
		
		for (int i=0; i<n; i++)
		{
			int x,bil;
			scanf("%d", &x);
			for (int j=0; j<x; j++)
			{
				scanf("%d", &bil);
				teamMap.insert(pair<int, int> (bil,i));
			}
		}

		getchar();
		string com = "";
		int input;
		while (com != "STOP")
		{
			cin >> com;
			if (com=="STOP") break;

			if (com=="ENQUEUE")
			{
				scanf("%d", &input);
				tq.push(input, teamMap[input]);
			}
			else
			{
				printf("%d\n",tq.front());
				tq.pop();
			}

			getchar();
		}

		z+=1;
		printf("\n");
	}
	

	return 0;
}
