#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

struct Data
{
	string curStr;
	int curPos;
	int steps;	
};

int res;
vector<string> dict;
vector<int> adj[202];

bool differByOne(string a, string b)
{
	if (abs(a.length() - b.length()) >0) return false;

	// if (a.length() < b.length()) a+=" ";
	// if (b.length() < a.length()) b+=" ";

	int diff=0;
	for (int i=0; i<a.length(); i++)
	{
		if (a[i] != b[i]) diff++;
	}

	return (diff == 1);
}

void preprocessing()
{
	for (int i=0; i<dict.size(); i++)
	{
		string cur = dict[i];
		for (int j=i+1; j<dict.size(); j++)	
		{
			string cur2 = dict[j];
			if (cur != cur2)
			{
				if (differByOne(cur,cur2))
				{
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
		}
	}
}

bool f(string a, string b)
{
	if (a.length() != b.length()) return a.length() < b.length();
	else
		return (a<b);
}

void bfs(string source, string dest)
{
	bool visited[202];
	for (int i=0; i<202; i++) visited[i] = false;

	int startPos = 0;
	for (int i=1; i<dict.size(); i++)
		if (dict[i] == source) startPos=i;

	//fprintf(stderr, "Started bfs from %s/%d to %s\n", source.c_str(), startPos, dest.c_str());

	Data newData;
	newData.curStr = source;
	newData.curPos = startPos;
	newData.steps = 0;
	visited[startPos] = true;

	queue<Data> q;
	q.push(newData);

	while (!q.empty())
	{
		Data cur = q.front();
		q.pop();

		////fprintf(stderr, "Cur %s/%d: %d\n", cur.curStr.c_str(), cur.curPos, cur.steps);

		if (cur.curStr == dest)
		{
			res = cur.steps;
			break;
		}

		for (int i=0; i<adj[cur.curPos].size(); i++)
		{
			int nextDest = adj[cur.curPos][i];
			if (!visited[nextDest])
			{
				visited[nextDest] = true;
				Data newData;
				newData.curPos = nextDest;
				newData.curStr = dict[nextDest];
				newData.steps = cur.steps+1;
				q.push(newData);
			}
		}
	}
}

void OPEN(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main()
{
	//OPEN("word_transformation");
	int tc;
	scanf("%d", &tc);
	getchar();
	getchar();
	
	for (int z=1; z<=tc; z++)
	{
		for (int i=0; i<202; i++) adj[i].clear();
		dict.clear();

		string in = "";

		while (in != "*")
		{
			getline(cin, in);
			if (in=="*") break;
			dict.push_back(in);
		}

		sort(dict.begin(), dict.end(),f);
		// printf("sorted\n");
		preprocessing();
		// printf("preprocessing\n");

		//fprintf(stderr,"Case %d: %d words\n", z, (int) dict.size());
		for (int i=0; i<dict.size(); i++)
		{
			//fprintf(stderr,"%s:", dict[i].c_str());
			for (int j=0; j<adj[i].size(); j++)
			{
				//fprintf(stderr, " %s", dict[adj[i][j]].c_str());
			}
			//fprintf(stderr, "\n");
		}
		//fprintf(stderr, "\n");

		in= "0";

		if (z>1) printf("\n");
		while ((in.length() >0) && (!cin.eof()))
		{
			getline(cin, in);
			res = -1;

			if (in.length() ==0) break;

			string source="", dest="";
			int x=0;

			for (int i=0; i<in.length(); i++)
			{
				if (in[i] == ' ') x+=1;
				else
					if (x==0) source+=in[i];
				else
					dest += in[i];
			}
			//fprintf(stderr, "Read %s %s\n", source.c_str(), dest.c_str());

			bfs(source, dest);

			//fprintf(stderr, "Done bfs for %s %s\n", source.c_str(), dest.c_str());

			cout << source << " " << dest<< " "  << res << endl;
		}
	}

	return 0;
}