#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<stack<char> > stacks;

int main()
{
	string s = "";
	int z=1;

	while (s!= "end")
	{
		getline(cin, s);
		if (s=="end") break;
		stacks.clear();

		for (int i=0; i<s.length(); i++)
		{
			bool getStack = false;
			for (int j=0; j<stacks.size(); j++)
			{
				if (stacks[j].top() >= s[i])
				{
					getStack=true;
					stacks[j].push(s[i]);
					break;
				}
			}

			if (!getStack)
			{
				stack<char> newStack;
				newStack.push(s[i]);
				stacks.push_back(newStack);
			}
		}

		cout << "Case " << z << ": " << stacks.size() << endl;
		z+=1;
	}
	return 0;
}