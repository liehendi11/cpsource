#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>

using namespace std;

struct Move
{
	int type;
	int room;
};

struct State
{
	vector<Move> moves;
	int curState;
	int pos;
};

bool state[12][3000];
vector<int> lampAdj[12];
vector<int> moveAdj[12];
queue<State> q;
int r,d,s,x,y;
int target;

void reset()
{
	memset(state, false, sizeof(state));
	for (int i=0; i<12; i++)
	{
		lampAdj[i].clear();
		moveAdj[i].clear();
	}

	while (!q.empty()) q.pop();
}

bool check(int bitArr, int pos)
{
	return ((bitArr & (1<<pos))>0);
}

int turnOn(int bitArr, int pos)
{
	int ret = (x | (1<<pos));
	return ret;
}

int turnOff(int bitArr, int pos)
{
	int ret = (x & (~(1<<pos)));
	return ret;
}

void printResult(State st)
{
	cout << "The problem can be solved in " << st.moves.size() << " steps:" << endl;
	//printf("The problem can be solved in %d steps:\n", st.moves.size());
	for (int i=0; i<st.moves.size(); i++)
	{
		if (st.moves[i].type == 0) printf("- Move to room %d.\n", st.moves[i].room);
		if (st.moves[i].type == 1) printf("- Switch off light in room %d.\n", st.moves[i].room);
		if (st.moves[i].type == 2) printf("- Switch on light in room %d.\n", st.moves[i].room);
	}
}

string interpretBit(int bit)
{
	string ret = "";
	for (int i=1; i<=r; i++)
	{
		if (check(bit, i)) ret+="1";
		else
			ret+="0";
	}

	return ret;
}

void search()
{
	bool found=false;
	int dum;

	while (!q.empty())
	{
		State cur = q.front();

		// cout << cur.pos << " " << interpretBit(cur.curState) << endl;

		// if ((cur.pos == 9) && (interpretBit(cur.curState) == "1111111111"))
		// {
		// 	printf("lalala\n");
		// }
		q.pop();

		if ((cur.pos == r) && (cur.curState == target))
		{
			printResult(cur);
			found = true;
			break;
		}

		for (int i=0; i<moveAdj[cur.pos].size(); i++)
		{
			if ((check(cur.curState, moveAdj[cur.pos][i])) && (!state[moveAdj[cur.pos][i]][cur.curState]))
			{
				State temp = cur;
				Move newStep;
				newStep.type = 0;
				newStep.room = moveAdj[cur.pos][i];
				temp.moves.push_back(newStep);
				temp.pos = moveAdj[cur.pos][i];

				state[temp.pos][temp.curState] = true;

				q.push(temp);
			}
		}

		for (int j=0; j<lampAdj[cur.pos].size(); j++)
		{
			if (check(cur.curState, lampAdj[cur.pos][j]))
			{
				//the lamp is turned on
				int newState = (cur.curState & (~(1<<lampAdj[cur.pos][j])));
				//turnOff(cur.curState, lampAdj[cur.pos][j]);
				if ((!state[cur.pos][newState]) && (check(newState, cur.pos)))
				{
					State temp = cur;
					Move newStep;
					newStep.type = 1;
					newStep.room = lampAdj[cur.pos][j];
					temp.moves.push_back(newStep);
					temp.curState = newState;

					state[temp.pos][newState] = true;

					q.push(temp);
				}
			}
			else
			{
				int newState = cur.curState | (1<<lampAdj[cur.pos][j]);
				//turnOn(cur.curState, lampAdj[cur.pos][j]);
				if (!state[cur.pos][newState])
				{
					State temp = cur;
					Move newStep;
					newStep.type = 2;
					newStep.room = lampAdj[cur.pos][j];
					temp.moves.push_back(newStep);
					temp.curState = newState;

					state[temp.pos][newState] = true;

					q.push(temp);
				}
			}
		}
	}

	if (!found)
	{
		printf("The problem cannot be solved.\n");
	}
}

void OPEN(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main()
{
	//OPEN("new_villa");
	r=-1; d=-1; s=-1;
	int z=0;

	while (!((r==0) && (d==0) && (s==0)))
	{
		z+=1;
		scanf("%d%d%d", &r, &d, &s);

		if ((r==0) && (d==0) && (s==0))	break;
		reset();

		for (int i=0; i<d; i++)
		{
			scanf("%d%d", &x, &y);
			moveAdj[x].push_back(y);
			moveAdj[y].push_back(x);
		}

		for (int j=0; j<s; j++)
		{
			scanf("%d%d", &x, &y);
			lampAdj[x].push_back(y);
		}

		//printf("%d\n", turnOn(0,r));
		target = 0 | (1<<r);

		//cout << interpretBit(target) << endl;

		//init first
		State firstState;
		firstState.curState = 0 | (1<<1);
		firstState.pos = 1;
		state[firstState.pos][firstState.curState] = true;
		q.push(firstState);

		printf("Villa #%d\n", z);
		search();
		printf("\n");
	}
	return 0;
}