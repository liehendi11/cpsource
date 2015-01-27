#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <iostream>
#include <string>

using namespace std;

stack<char> charStack;
bool isCorrect;

void reset()
{
	while (!charStack.empty())
	{
		charStack.pop();
	}
	isCorrect=true;
}

bool checkCorrectness(char c)
{
	if ((c=='(') || (c=='['))
	{
		charStack.push(c);
		return true;
	}
	else
	if (!charStack.empty())
	{
		if (c==')')
		{
			if (charStack.top() == '(')
			{
				charStack.pop();
				return true;
			}
			else
				return false;
		}

		if (c==']')
		{
			if (charStack.top() == '[')
			{
				charStack.pop();
				return true;
			}
			else
				return false;
		}
	}
	else
		return false;
}

int main()
{
	int tc;
	scanf("%d", &tc);
	getchar();
	for (int z=1; z<=tc; z++)
	{
		string s;
		getline(cin, s);
		reset();


		for (int i=0; i<s.size(); i++)
		{
			if ((s[i]=='(') || (s[i]=='[') || (s[i]==')') || (s[i]==']'))
				isCorrect &= checkCorrectness(s[i]);
			if (!isCorrect) break;
		}

		if (!charStack.empty()) isCorrect=false;

		if (isCorrect) printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}