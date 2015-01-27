#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

char findCharInEncodedString(string s, int idx)
{
	int lastIdx = -1;
	string temp = "";
	int multiplier = 0;
	bool isMultiplying=false;

	for (int i=0; i<s.length(); i++)
	{
		if ((s[i] >= 97) && (s[i] <= 122))
		{
			if (isMultiplying)
			{
				int nextLastIdx = (temp.length() * multiplier) + lastIdx;
				if ((idx > lastIdx) && (idx <= nextLastIdx))
				{
					int idxPosInTemp = (idx-lastIdx-1)%temp.length();
					return temp[idxPosInTemp];
				}
				else
				{
					lastIdx = nextLastIdx;
					temp = "";
					multiplier = 0;
					isMultiplying = false;
				}
			}
			temp += s[i];
		}
		else
		{
			isMultiplying = true;
			multiplier = (multiplier*10) + (s[i]-48);
		}
	}

	//not found till last, must be in last substring
	int idxPosInTemp = (idx-lastIdx-1)%temp.length();
	return temp[idxPosInTemp];
}

int main()
{
	printf("%c\n", findCharInEncodedString("a2bc3d4", 4));
	return 0;
}