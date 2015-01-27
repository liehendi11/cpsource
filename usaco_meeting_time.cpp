#include <stdio.h>
#include <stdlib.h>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Path
{
public:
	int dest, bessie, elsie;
	Path(int adest, int abessie, int aelsie)
	{
		dest = adest;
		bessie = abessie;
		elsie = aelsie;
	}
};

void OPEN(string inputFile, string outputFile) {
	freopen(inputFile.c_str(), "r", stdin);
	freopen(outputFile.c_str(), "w", stdout);
}

vector<Path> adj[18];
int n,m;
vector<int> bessieRes;
unordered_set<int> elsieRes;

void traverseBessie(int x, int totalCost)
{
	if (x==n) 
	{
		bessieRes.push_back(totalCost);
	}
	else
	{
		for (int i=0; i<adj[x].size(); i++)
			traverseBessie(adj[x][i].dest, adj[x][i].bessie+totalCost);
	}
}

void traverseElsie(int x, int totalCost)
{
	if (x==n) 
	{
		elsieRes.insert(totalCost);
	}
	else
	{
		for (int i=0; i<adj[x].size(); i++)
			traverseElsie(adj[x][i].dest, adj[x][i].elsie+totalCost);
	}
}

int main()
{
	OPEN("meeting.in", "meeting.out");
	scanf("%d%d", &n, &m);
	for (int i=0; i<18; i++) adj[i].clear();

	int a,b,c,d;
	for (int i=0; i<m; i++)
	{
		scanf("%d%d%d%d",&a, &b, &c, &d);
		Path newPath (b,c,d);
		adj[a].push_back(newPath);
	}

	traverseElsie(1,0);
	traverseBessie(1,0);
	sort(bessieRes.begin(), bessieRes.end());

	bool found=false;
	for (int i=0; i<bessieRes.size(); i++)
	{
		if (elsieRes.count(bessieRes[i]) > 0)
		{
			found=true;
			printf("%d\n", bessieRes[i]);
			break;
		}
	}

	if (!found) printf("IMPOSSIBLE\n");

	return 0;
}