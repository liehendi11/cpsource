#include <stdio.h>
#include <stdlib.h>
#include <set>

using namespace std;

int friends[10002];
set<int> enemies[10002];

void reset()
{
	for (int i=0; i<10002; i++)
	{
		friends[i] = i;
		enemies[i].clear();
	}
}

int findFriends(int x)
{
	if (friends[x] == x) return x;
	else
	{
		friends[x] = findFriends(friends[x]);
		return friends[x];
	}
}

bool isFriend(int x, int y)
{
	return (findFriends(x) == findFriends(y));
}

bool isEnemy(int x, int y)
{
	int friendParentX = findFriends(x);
	int friendParentY = findFriends(y);
	return (enemies[friendParentX].count(friendParentY) >0);
}

bool uniteFriends(int x, int y)
{
	int friendParentX = findFriends(x);
	int friendParentY = findFriends(y);

	//check if they are not enemies and are not friends before
	if ((friendParentX != friendParentY) && (enemies[friendParentX].count(friendParentY) ==0))
	{
		friends[friendParentX] = friendParentY;
		//unite the enemies
		set<int>::iterator it;
		for (it=enemies[friendParentX].begin(); it!= enemies[friendParentX].end(); ++it)
		{
			int temp = *it;
			//if (enemies[friendParentY].count(temp) ==0) 
			enemies[friendParentY].insert(temp);
		}

		return true;
	}
	return false;
}

bool uniteEnemies(int x, int y)
{
	int friendParentX = findFriends(x);
	int friendParentY = findFriends(y);

	//check if they are not friends and are not enemies before
	if ((friendParentX != friendParentY))
	{
		bool isFriendWithEnemyEnemy = true;

		set<int>::iterator it;
		for (it=enemies[friendParentY].begin(); it!= enemies[friendParentY].end(); ++it)
		{
			int temp = *it;
			if (isEnemy(x,temp)) isFriendWithEnemyEnemy=false;
		}

		if (isFriendWithEnemyEnemy)
		{
			//unite the enemies by parent
			// if (enemies[x].count(y) ==0) 
			enemies[x].insert(y);
			// if (enemies[friendParentX].count(y) ==0) 
			enemies[friendParentX].insert(y);

			//if (enemies[y].count(x) ==0) 
			enemies[y].insert(x);
			//if (enemies[friendParentY].count(x) ==0) 
			enemies[friendParentY].insert(x);

			//make x friends with all enemies of y
			//set<int>::iterator it;
			for (it=enemies[friendParentY].begin(); it!= enemies[friendParentY].end(); ++it)
			{
				int temp = *it;
				uniteFriends(friendParentX, temp);
			}
			return true;
		}
		else
			return false;
	}
	return false;
}

// bool uniteEnemies(int x, int y)
// {
// 	int friendParentX = findFriends(x);
// 	int enemyParentX = findEnemies(friendParentX);

// 	int friendParentY = findFriends(y);
// 	int enemyParentY = findEnemies(friendParentY);

// 	if ((enemyParentX != enemyParentY) && (friendParentX != friendParentY))
// 	{
// 		enemies[friendParentX] = enemyParentY;
// 		return true;
// 	}
// 	else
// 		return false;
// }

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		//scanf("%d", &n);
		reset();

		int com,x,y;
		com = -1;
		x=-1;
		y=-1;

		while (!((com == 0) && (x == 0) && (y == 0)))
		{
			scanf("%d%d%d", &com, &x, &y);
			if ((com == 0) && (x == 0) && (y == 0)) break;

			if (com==1)
			{
				if (!uniteFriends(x,y)) printf("-1\n");
			}
			if (com==2)
			{
				if (!uniteEnemies(x,y)) printf("-1\n");
			}
			if (com==3)
			{
				if (isFriend(x,y)) printf("1\n");
				else
					printf("0\n");
			}

			if (com==4)
			{
				if (isEnemy(x,y)) printf("1\n");
				else
					printf("0\n");
			}
		}
	}
	
	return 0;
}