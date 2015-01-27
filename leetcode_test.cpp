#include <string>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

class Data
{
public:
    string cur;
    int steps;
    vector<string> visited;
    Data(string start)
    {
        cur = start;
        steps = 0;
        visited.clear();
        visited.push_back(cur);
    }
    
    Data(const Data &copyClass)
    {
        cur = copyClass.cur;
        steps = copyClass.steps;
        visited = copyClass.visited;
    }
};

class Solution {
public:
    
    bool diffByOne(string a, string b)
    {
        int ctr=0;
        for (int i=0; i<a.length(); i++)
        {
            if (a[i] != b[i]) ctr+=1;
            if (ctr > 1) return false;
        }
        
        return (ctr==1);
    }
    
    
    
    void traverseWords(string start, string end, unordered_set<string> &dict, vector<vector<string>> &res)
    {
        
        queue<Data> q;
        q.push(Data(start));
        
        bool found = false;
        int foundSteps = 0;
        
        while (!q.empty())
        {
            Data cur = q.front();
            q.pop();
            
            if (cur.cur == end)
            {
                if (!found)
                {
                    found = true;
                    foundSteps = cur.steps;
                }
                
                if (cur.steps == foundSteps) res.push_back(cur.visited);
                else
                    break;
            }
            else
            {
                for (auto itr = dict.begin(); itr!= dict.end(); ++itr)
                {
                    if (diffByOne(cur.cur, *itr))
                    {
                        Data newData(cur);
                        newData.steps += 1;
                        newData.cur = *itr;
                        newData.visited.push_back(*itr);
                    }
                }
            }
        }
    }
    
    
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string>> res;
        
        traverseWords(start, end, dict, res);
        
        return res;
    }
};

int main()
{
    return 0;
}