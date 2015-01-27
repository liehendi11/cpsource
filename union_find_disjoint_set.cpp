#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int parents[1000002];

int findParent(int x)
{
	if (parents[x] == x) return x;
	else
    {
        parents[x] = findParent(parents[x]);
        return parents[x];
    }

}

void unionSet(int a, int b)
{
	parents[findParent(b)] = a;
}

bool isSameSet(int x, int y)
{
    return (findParent(x) == findParent(y));
}

void OPEN(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    //freopen((s + ".out").c_str(), "w", stdout);
}

int main()
{
//    OPEN("network");
    string inputString="";
    int tc;

    getline(cin, inputString);
    sscanf(inputString.c_str(), "%d", &tc);

    //scanf("%d", &tc);
    getline(cin, inputString);
    memset(parents, 0, sizeof(parents));
    for (int z=1; z<=tc; z++)
    {
        if (z>1) printf("\n");


        int n;
        getline(cin, inputString);

        sscanf(inputString.c_str(), "%d", &n);

        for (int i=1; i<=n; i++)
        {
            parents[i]=i;
        }

        char com;
        int success = 0;
        int notsuccess = 0;
        inputString="0";

        while (!(cin.eof() || (inputString.length()==0)))
        {
            getline(cin, inputString);
            if (inputString.length()==0) break;

            istringstream stream(inputString);
            
            int a,b;
            stream >> com >> a >> b;
            
            if (com=='c') unionSet(a,b);
            else
            {
                if (isSameSet(a,b)) success+=1;
                else
                    notsuccess+=1;
            }
        }

        printf("%d, %d\n",success, notsuccess);
    }
	return 0;
}
