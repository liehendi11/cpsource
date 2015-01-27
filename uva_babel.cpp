#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>

using namespace std;

#define INF 2000000009LL

struct Edge
{
	int node, weight;
	char initial;
};

struct Node
{
	int index, cost;
	char initial;
};

map<string, int> languageMap;
vector<Edge> edges[4003];
int cost[28][4003];
int destIndex;

class comparison
{
public:
	bool operator() (const Node& left, const Node& right)
	{
		return left.cost > right.cost;
	}
};

void dijkstra()
{
	priority_queue<Node, vector<Node>, comparison> pq;
	Node first;
	first.index = 0;
	first.cost = 0;
	first.initial = 0;
	pq.push(first);
	bool found=false;

	while ((!found) && (!pq.empty()))
	{
		Node cur = pq.top();
		pq.pop();

		//printf("%d %d %c\n", cur.index, cur.cost, cur.initial);

		if (first.initial!=0)
		cost[cur.initial-97][cur.index] = -1;

		if (cur.index == destIndex)
		{
			found=true;
			printf("%d\n", cur.cost);
		}
		else
		{
			for (int i=0; i<edges[cur.index].size(); i++)
			{
				Edge curEdge = edges[cur.index][i];

				if ((cost[curEdge.initial-97][curEdge.node] > cur.cost + curEdge.weight) && (curEdge.initial != cur.initial))
				{
					Node newNode = cur;
					newNode.index = curEdge.node;
					newNode.cost += curEdge.weight;
					newNode.initial = curEdge.initial;
					pq.push(newNode);

					cost[curEdge.initial-97][curEdge.node] = newNode.cost;
				}
			}
		}
	}

	if (!found)
	{
		printf("impossivel\n");
	}
}

void OPEN(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void reset()
{
	for (int i=0; i<4003; i++)
	{
		edges[i].clear();
	}
	languageMap.clear();
	memset(cost, INF, sizeof(cost));
}

int main()
{
	//OPEN("babel");
	int n=-1;

	while (n!=0)
	{
		scanf("%d", &n);
		getchar();
		if (n==0) break;

		reset();
		string source, dest;
		cin >> source >> dest;
		languageMap.insert(pair<string, int> (source, 0));
		int count=1;
		if (source != dest)
		{
			languageMap.insert(pair<string, int> (dest, 1));
			destIndex = 1;
		}
		else
		{
			count = 0;
			destIndex=0;
		}
		getchar();

		
		string first, second, word;

		for (int i=0; i<n; i++)
		{
			cin >> first >> second >> word;

			int indexFirst, indexSecond, weight;
			if (languageMap.count(first) >0) indexFirst = languageMap[first];
			else
			{
				count +=1;
				languageMap.insert(pair<string, int> (first, count));
				indexFirst = count;
			}

			if (languageMap.count(second) >0) indexSecond = languageMap[second];
			else
			{
				count +=1;
				languageMap.insert(pair<string, int> (second, count));
				indexSecond = count;
			}

			weight = word.length();

			Edge newEdge1,newEdge2;
			newEdge1.node = indexFirst;
			newEdge1.weight = weight;
			newEdge1.initial = word[0];
			edges[indexSecond].push_back(newEdge1);

			newEdge2.node = indexSecond;
			newEdge2.weight = weight;
			newEdge2.initial = word[0];
			edges[indexFirst].push_back(newEdge2);
			getchar();
		}

		dijkstra();
	}

	return 0;
}