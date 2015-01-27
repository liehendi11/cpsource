#include <cstdio>
#include <set>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

#define SIZE 4

typedef struct State { int x[SIZE][SIZE]; } State;
struct Data
{
	State state;
	string steps;
	int approximate;
	int x,y;
	string stateString;
};

class comparison
{
public:
	bool operator() (const Data& left, const Data& right)
	{
		return (left.approximate > right.approximate);
	}
};

vector<pair<int, int> > targetedPositions;
set<string> visitedState;
State targetState;
State sourceState;

int posx, posy;

int findHeuristic(State stateString)
{
	int cost=0;
	for (int i=0; i<SIZE; i++)
	{
		for (int j=0; j<SIZE; j++)
		{
			int curNumber = stateString.x[i][j];
			cost += (abs(targetedPositions[curNumber].first - i) + abs(targetedPositions[curNumber].second - j));
		}
	}
	return cost;
}

string convertState(State stateString)
{
	ostringstream ss;
	for (int i=0; i<SIZE; i++)
	{
		for (int j=0; j<SIZE; j++)
		{
			ss<<stateString.x[i][j] << "-";
		}
	}
	return ss.str();
}



void init()
{
	targetedPositions.push_back(pair<int, int> (SIZE-1,SIZE-1));

	targetState.x[SIZE-1][SIZE-1] = 0;
	int bil=1;
	for (int i=0; i<SIZE; i++)
	{
		for (int j=0; j<SIZE; j++)
		{
			targetState.x[i][j] = bil;
			targetedPositions.push_back(pair<int, int> (i,j));
			bil+=1;
			if (bil==16) break;
		}
	}
}

void reset()
{
	visitedState.clear();
}

bool isSameState(State state1, State state2)
{
	bool same=true;
	for (int i=0; i<SIZE; i++)
	{
		for (int j=0; j<SIZE; j++)
		{
			same = same & (state1.x[i][j] == state2.x[i][j]);
			if (!same) return false;
		}
	}
	return same;
}

void swap(int *a, int *b)
{
	int *c = a;
	a=b;
	b=c;
}

void heuristicSearch()
{
	Data firstData;
	firstData.state = sourceState;
	firstData.stateString = convertState(sourceState);
	firstData.steps = "";
	firstData.approximate = findHeuristic(sourceState);
	firstData.x = posx;
	firstData.y = posy;

	priority_queue<Data, vector<Data>, comparison> pq;
	pq.push(firstData);

	bool found=false;

	while ((!pq.empty()) && (!found))
	{
		Data curData = pq.top();
		pq.pop();

		if (visitedState.count(curData.stateString) >0) continue;
		visitedState.insert(curData.stateString);
		//cout << pq.size() << endl;

		if (isSameState(curData.state, targetState))
		{
			found=true;
			cout << curData.steps << endl;
			break;
		}

		if (curData.steps.length() > 50) break;
		visitedState.insert(curData.stateString);

		int curx, cury;
		curx = curData.x;
		cury = curData.y;

		string tempStep = curData.steps;
		int tempApprox = curData.approximate;
		int tempx = curData.x;
		int tempy = curData.y;
		string stateString = curData.stateString;

		//top
		if (curx >0)
		{
			Data newData = curData;
			swap(newData.state.x[curx][cury], newData.state.x[curx-1][cury]);
			string tempStateStr = convertState(newData.state);

			if (visitedState.count(tempStateStr) ==0)
			{
				//change
				newData.steps += 'U';
				newData.approximate = newData.steps.length() + findHeuristic(newData.state);
				newData.x -=1;
				newData.stateString = tempStateStr;

				//push to queue
				pq.push(newData);

			}
		}

		if (curx <SIZE-1)
		{
			Data newData = curData;
			swap(newData.state.x[curx][cury], newData.state.x[curx+1][cury]);
			string tempStateStr = convertState(newData.state);

			if (visitedState.count(tempStateStr) ==0)
			{
				//change
				newData.steps += 'D';
				newData.approximate = newData.steps.length() + findHeuristic(newData.state);
				newData.x +=1;
				newData.stateString = tempStateStr;

				//push to queue
				pq.push(newData);
			}
		}

		//right
		if (cury <SIZE-1)
		{
			Data newData = curData;
			swap(newData.state.x[curx][cury], newData.state.x[curx][cury+1]);
			string tempStateStr = convertState(newData.state);

			if (visitedState.count(tempStateStr) ==0)
			{
				//change
				newData.steps += 'R';
				newData.approximate = newData.steps.length() + findHeuristic(newData.state);
				newData.y +=1;
				newData.stateString = tempStateStr;

				//push to queue
				pq.push(newData);
			}
		}

		//left
		if (cury >0)
		{
			Data newData = curData;
			swap(newData.state.x[curx][cury], newData.state.x[curx][cury-1]);
			string tempStateStr = convertState(newData.state);

			if (visitedState.count(tempStateStr) ==0)
			{
				//change
				newData.steps += 'L';
				newData.approximate = newData.steps.length() + findHeuristic(newData.state);
				newData.y -=1;
				newData.stateString = tempStateStr;

				//push to queue
				pq.push(newData);
			}
		}
	}

	if (!found)
	{
		printf("This puzzle is not solvable.\n");
	}
}

int main()
{
	init();

	int tc;
	scanf("%d", &tc);
	for (int z=1; z<=tc; z++)
	{
		reset();
		for (int i=0; i<SIZE; i++)
		{
			for (int j=0; j<SIZE; j++)
			{
				scanf("%d", &sourceState.x[i][j]);
				if (sourceState.x[i][j] ==0)
				{
					posx = i;
					posy = j;
				}
			}
		}

		heuristicSearch();
	}

	return 0;
}