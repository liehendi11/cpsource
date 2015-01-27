#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <stack>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef stack<char> tdata;
string a,b;
vector<string> res;

void printResultOperations(string op)
{
	for (int i=0; i<op.length(); i++)
	{
		printf("%c", op[i]);
		if (i<op.length()-1) printf(" ");
		//if (i<op.length()-1) printf(" ");
	}

	printf("\n");
}

void find(tdata state, string op, int firstIdx, int secondIdx)
{
	if (firstIdx == a.length())
	{
		bool isAnagram = true;

		while (!state.empty())
		{
			if (state.top() == b[secondIdx])
			{
				secondIdx+=1;
				state.pop();
				op+='o';
			}
			else
			{
				isAnagram=false;
				break;
			}
		}

		if (isAnagram) res.push_back(op);
	}
	else
	{
		if (!state.empty())
		{
			if (state.top() == b[secondIdx])
			{
				tdata newState = state;
				string newOp = op;
				newState.pop();
				newOp+='o';
				find(newState, newOp, firstIdx, secondIdx+1);
			}
		}

		tdata newState = state;
		string newOp = op;
		newState.push(a[firstIdx]);
		newOp+='i';
		find(newState, newOp, firstIdx+1, secondIdx);
	}
}

void OPEN(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main()
{
	//OPEN("test");
	while (getline(cin, a))
	{
		res.clear();
		getline(cin,b);

		tdata st;
		string op = "";
		int firstIdx = 0;
		int secondIdx = 0;

		printf("[\n");

		find(st, op, 0, 0);

		sort(res.begin(), res.end());
		for (int i=0; i<res.size(); i++) printResultOperations(res[i]);
		
		printf("]\n");
	}

	return 0;
}