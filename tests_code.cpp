#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Node
{
	vector<Node*> child;
	int value;
};

int find_route(int posx, int posy, const char (&map) [2][2])
{
	cout << sizeof(map) << endl;
	for (int i=0; i<2; i++)
	{
		for (int j=0; j<2; j++)
		{
			printf("%c\n", map[i][j]);
		}
	}

	return 0;
}

vector<string> permuteString(string s)
{
	if (s.length() == 0)
	{
		vector<string> ret;
		ret.push_back("");
		return ret;
	}

	vector<string> ret;
	for (int i=0; i<s.length(); i++)
	{
		string remain = s;
		remain.erase(i, 1);

		char chosenChar = s[i];

		vector<string> tempRes = permuteString(remain);
		for (int i=0; i<tempRes.size(); i++)
		{
			ret.push_back(chosenChar+tempRes[i]);
		}
	}

	return ret;
}

int getAtZero(vector<int> &nom)
{
	return nom[0];
}

void printParenthesses(int target, string curParent="", int used=0, int open=0)
{
	if (used == target)
	{
		cout << curParent;
		for (int i=0; i<open; i++) printf(")");
		printf("\n");
	}
	else
	{
		if (used < target) printParenthesses(target, curParent+'(', used+1, open+1);
		if (open > 0) printParenthesses(target, curParent+')', used, open-1);
	}
	
}

class Solution {
private:

    bool checkInterleave(string &s1, string &s2, string &s3, int x, int y, char **dp)
    {
        int z = x+y;
        if ((x == s1.length()) && (y == s2.length()) && (z == s3.length())) return true;
        
        if (dp[x][y] == -1)
        {
            bool temp = false;
            
            if (x < s1.length())
                if (s1[x] == s3[z]) temp = temp || checkInterleave(s1,s2,s3,x+1,y, dp);
            
            if (y < s2.length())
                if (s2[y] == s3[z]) temp = temp || checkInterleave(s1,s2,s3,x,y+1, dp);
            
            if (temp) dp[x][y] = 1;
            else
                dp[x][y] = 0;
        }
        
        return (dp[x][y] == 1);
    }
    
public:
    bool isInterleave(string s1, string s2, string s3) {
        int s1Size = s1.length();
        int s2Size = s2.length();
        //int s3Size = s3.length();
        
        char **dp;
        dp = new char *[s1.length()];

        for (int i=0; i<s1.length(); i++)
        {
        	dp[i] = new char[s2.length()];
        }

        for (int i=0; i<s1.length(); i++)
        {
        	for (int j=0; j<s2.length(); j++)
        	{
        		dp[i][j] = -1;
        	}
        }

        // memset(dp, -1, sizeof(dp));
        if (s1.length() + s2.length() != s3.length()) return false;
        return checkInterleave(s1,s2,s3, 0,0, dp);
    }
};

int main()
{
	char tes[2][2];
	tes[0][0] = 'a';
	tes[0][1] = 'b';
	tes[1][0] = 'c';
	tes[1][1] = 'd';

	find_route(0,0, tes);

	vector<int> dum;
	dum.push_back(1);

	cout << getAtZero(dum) << endl;

	// vector<string> permutation = permuteString("abcdefg");

	// for (int i=0; i<permutation.size(); i++)
	// {
	// 	cout << permutation[i] << endl;
	// }

	printParenthesses(3);

	return 0;
}