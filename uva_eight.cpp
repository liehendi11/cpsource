#include <stdio.h>
#include <stdlib.h>
#include <unordered_set>
#include <map>
#include <string>
#include <queue>
#include <cmath>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

struct Data
{
	int state;
	string steps;
};

unordered_set<int> visited;
map<int, string> results;
int target =87654321;

void reset()
{
	visited.clear();
	results.clear();
}

int doMove(int state, string direction, int posx, int posy)
{
	int prevState = state;
	if (direction == "up")
	{
		int zeropower = pow(10, ((posx)*3) + posy);
		int digitpower = pow(10, ((posx-1)*3) + posy);
		int digit = (state/digitpower)%10;

		state += digit*zeropower;
		state -= (digit * digitpower);
		
		return state;
	}
	
	if (direction == "down")
	{
		int zeropower = pow(10, ((posx)*3) + posy);
		int digitpower = pow(10, ((posx+1)*3) + posy);
		int digit = (state/digitpower)%10;

		state += digit*zeropower;
		state -= (digit * digitpower);

		return state;
	}

	if (direction == "left")
	{
		int zeropower = pow(10, ((posx)*3) + posy);
		int digitpower = pow(10, ((posx)*3) + posy-1);
		int digit = (state/digitpower)%10;

		state += digit*zeropower;
		state -= (digit * digitpower);
		return state;
	}

	if (direction == "right")
	{
		int zeropower = pow(10, ((posx)*3) + posy);
		int digitpower = pow(10, ((posx)*3) + posy+1);
		int digit = (state/digitpower)%10;

		state += digit*zeropower;
		state -= (digit * digitpower);
		return state;
	}
}

void bfs()
{
	Data firstData;
	firstData.state = target;
	firstData.steps = "";
	visited.insert(target);

	queue<Data> q;
	q.push(firstData);

	while (!q.empty())
	{
		Data curData = q.front();
		q.pop();

		results.insert(pair<int, string> (curData.state, curData.steps));

		//find position of 0
		int px, py;
		int temp=1;
		for (int i=0; i<3; i++)
		{
			for (int j=0; j<3; j++)
			{
				if (((curData.state/temp) %10) ==0)
				{
					px=i;
					py=j;
					//break;
				}
				//printf("%d %d %d/", i, j, ((curData.state/temp) %10));
				temp*=10;
			}
		}
		
		if (px > 0)
		{
			int newState = doMove(curData.state, "up", px, py);
			if (visited.count(newState) ==0)
			{
				Data newData = curData;
				newData.state = newState;
				newData.steps += "d";
				q.push(newData);
				visited.insert(newState);
			}
		}

		if (px < 2)
		{
			int newState = doMove(curData.state, "down", px, py);
			if (visited.count(newState) ==0)
			{
				Data newData = curData;
				newData.state = newState;
				newData.steps += "u";
				q.push(newData);
				visited.insert(newState);
			}
		}

		if (py > 0)
		{
			int newState = doMove(curData.state, "left", px, py);
			if (visited.count(newState) ==0)
			{
				Data newData = curData;
				newData.state = newState;
				newData.steps += "r";
				q.push(newData);
				visited.insert(newState);
			}
		}

		if (py < 2)
		{
			int newState = doMove(curData.state, "right", px, py);
			if (visited.count(newState) ==0)
			{
				Data newData = curData;
				newData.state = newState;
				newData.steps += "l";
				q.push(newData);
				visited.insert(newState);
			}
		}
	}
}

void OPEN(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main()
{
//	OPEN("eight");
	reset();
	bfs();
	int tc;
	scanf("%d", &tc);

	getchar();
	for (int i=0; i<tc; i++)
	{
		getchar();

		int digitpower = 1;
		char c;
		int inputState=0;
		for (int i=0; i<9; i++)
		{
			scanf("%c", &c);
			if (c=='x') inputState += digitpower*0;
			else
				inputState += digitpower * (c-48);

			digitpower*=10;
			getchar();
		}

		if (i>0) printf("\n");
		if (results.count(inputState) ==0) printf("unsolvable\n");
		else
		{
			string output = string (results[inputState].rbegin(), results[inputState].rend());
			printf("%s\n", output.c_str());
		}
	}
	return 0;
}