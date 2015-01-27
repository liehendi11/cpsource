#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unordered_map>

using namespace std;

struct Combo
{
	vector<int> foods;
	int price;
};

int idvPrice[8];
vector<Combo> combos;
vector<int> foodCombos[8];
unordered_map<int> dp;

void reset()
{
	combos.clear();
	for (int i=0; i<8; i++)
	{
		idvPrice[i] = -1;
		foodCombos[i].clear();
	}
}

int findResult(string state)
{
	if (dp.count(state) ==0)
	{
		int res=0;
		for (int i=0; i<state.length(); i++)
		{
			int x = state[i]-48;
			if (x>0)
			{
				
			}
		}
	}
	else
		return dp[state];
}

int main()
{

	return 0;
}