#include <stdio.h>
#include <unordered_set>
#include <stdlib.h>
#include <string>
#include <queue>

using namespace std;

class Data
{
public:
    string cur;
    int steps;
    Data (string xcur, int xsteps)
    {
        cur = xcur;
        steps = xsteps;
    }
};

class Solution {
    bool diffByOne(string a, string b)
    {
        int diff = 0;
        for (int i=0; i<a.length(); i++)
        {
            if (a[i] != b[i]) diff+=1;
        }
        
        return (diff == 1);
    }
    
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<Data> q;
        q.push(Data(start, 1));
        
        while (!q.empty())
        {
            Data cur = q.front();
            // printf("%s %d\n", cur.cur.c_str(), cur.steps);
            q.pop();
            
            if (cur.cur == end) return cur.steps;
            
            vector<string> visited;
            for (auto it: dict)
            {
                if (diffByOne(cur.cur, it))
                {
                    Data newData (it, cur.steps+1);
                    visited.push_back(it);
                    q.push(newData);
                }
            }

            for (int i=0; i<visited.size(); i++) dict.erase(visited[i]);
        }
        
        return 0;
    }
};

int main()
{
    unordered_set<string> dict = {"hot","dot","dog","lot","log"};
    // dict.insert("hit");
    dict.insert("cog");
    Solution solution;

    printf("%d\n", solution.ladderLength("hit", "cog", dict));
    return 0;
}