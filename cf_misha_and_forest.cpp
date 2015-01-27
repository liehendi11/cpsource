#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <cstring>

using namespace std;

class Vertex
{
public:
	int idx, xorSum, degree;
	Vertex(int aidx,  int adegree, int axorSum)
	{
		idx = aidx;
		xorSum = axorSum;
		degree = adegree;
	}
};

class mycomparison
{
public:
	bool operator() (const Vertex &lhs, const Vertex &rhs)
	{
		return (lhs.degree > rhs.degree);
	}
};

int findComplement(int sum, int known)
{
	int multiplier = 1;
	int res = 0;
	while ((sum > 0) || (known > 0))
	{
		int xs = (sum%2);
		int xk = (known%2);

		int bts = 0;
		if (((xs == 1) && (xk == 0)) || ((xs == 0) && (xk==1))) bts=1;

		res += (multiplier * bts);
		multiplier*=2;
		sum/=2;
		known/=2;
	}

	return res;
}

void process(vector<Vertex> &vertices)
{
	vector<pair<int, int> > edges;
	bool visited[vertices.size()+2];
	memset(visited, false, sizeof(visited));

	priority_queue<Vertex, vector<Vertex>, mycomparison> pq;

	for (int i=0; i<vertices.size(); i++)
	{
		if (vertices[i].degree == 1) pq.push(vertices[i]);
	}


	while (!pq.empty())
	{
		Vertex cur = pq.top();
		pq.pop();

		if (visited[cur.idx]) continue;

		visited[cur.idx] = true;

		if (cur.degree > 0)
		{
			edges.push_back(pair<int, int> (cur.idx, cur.xorSum));
			vertices[cur.xorSum].degree -=1;
			vertices[cur.xorSum].xorSum = findComplement(vertices[cur.xorSum].xorSum, cur.idx);

			if (vertices[cur.xorSum].degree == 1) pq.push(vertices[cur.xorSum]);
		}
		
	}

	printf("%d\n", (int) edges.size());
	for (int i=0; i<edges.size(); i++)
	{
		printf("%d %d\n", edges[i].first, edges[i].second);
	}
}

int main()
{
	int n;
	vector<Vertex> vertices;

	int a,b;
	scanf("%d", &n);
	for (int i=0; i<n; i++)
	{
		scanf("%d%d", &a, &b);
		vertices.push_back(Vertex(i, a, b));
	}

	process(vertices);
	return 0;
}