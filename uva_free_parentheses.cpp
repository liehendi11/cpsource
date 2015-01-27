#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

vector<int> numbers;
bool dp[32][32][7002];
bool reached[7002];
int ctr;

void reset()
{
	numbers.clear();
	ctr=0;
	for (int k=0; k<7002; k++)
	{
		reached[k] = false;
		for (int i=0; i<32; i++)
		{
			for (int j=0; j<32; j++)
			{
				dp[i][j][k] = false;
			}
		}
	}
}

void find(int pos, int openParent, int val)
{
	if (dp[pos][openParent][val+3500]) return;
	dp[pos][openParent][val+3500] = true;

	if (pos==numbers.size())
	{
		if (!reached[val+3500]) ctr+=1;
		reached[val+3500] = true;
		return;
	}

	int mode = (openParent%2) == 0 ? 1 : -1;

	//normal - do nothing
	find(pos+1, openParent, val + (numbers[pos] * mode));
		// , temp+to_string(numbers[pos]));
	//if there is any open parenthesses
	if (openParent>0) find(pos+1, openParent-1, val + (numbers[pos] * mode * -1));
	// , temp+")" + to_string(numbers[pos]));

	if (numbers[pos] <0) find(pos+1, openParent+1, val+(numbers[pos]));
	// , temp+"("+to_string(numbers[pos]));
}

void OPEN(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main()
{
	//OPEN("free_parenthesses");
	string in;
	while (getline(cin, in))
	{
		reset();

		stringstream ss(in);

		int num;
		char sign;
		ss>>num;
		numbers.push_back(num);

		while (ss>>sign>>num)
		{
			numbers.push_back((sign=='+')? num: -num);
		}

		// int temp = 0;
		// int mode = 1;
		// for (int i=0; i<in.length(); i++)
		// {
		// 	if (in[i] == ' ')
		// 	{
		// 		numbers.push_back(temp*mode);
		// 		mode=1;
		// 		temp=0;
		// 	}
		// 	else
		// 	if (in[i] == '+')
		// 	{
		// 		mode=1;
		// 		i+=1;
		// 	}
		// 	else
		// 	if (in[i] == '-')
		// 	{
		// 		mode=-1;
		// 		i+=1;
		// 	}
		// 	else
		// 	{
		// 		temp = (temp*10) + (in[i]-48);
		// 	}
		// }

		// numbers.push_back(temp*mode);

		find(0,0,0);
		printf("%d\n", ctr);
	}

	return 0;

}