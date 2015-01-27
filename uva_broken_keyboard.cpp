#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <list>

using namespace std;

int main(int argc, char **argv)
{
	if (argc >1) freopen(argv[1], "r", stdin);

	string s;
	int i;
	while (getline(cin,s))
	{	
		if (!cin) break;

		list<string> stringList;

		string cur="";
		string head = "";
		string tail = "";
		string mode = "end";
		for (i=0; i<s.length(); i++)
		{
			if (s[i] == '[')
			{

				mode = "home";
				if (head.length() >0)
					stringList.push_front(head);

				head="";
			}
			else
				if (s[i] == ']')
				{
					mode = "end";
					if (tail.length() >0)
						stringList.push_back(tail);

					tail = "";
				}
				else
					if (mode=="home")
					{
						head = head+s[i];
					}
					else
						tail = tail+s[i];
		}

		stringList.push_front(head);
		stringList.push_back(tail);

		for (list<string>::iterator it = stringList.begin(); it!=stringList.end(); ++it)
		{
			cout << *it;
		}
		printf("\n");
	}

	if (argc >1) fclose(stdin);

	return 0;
}