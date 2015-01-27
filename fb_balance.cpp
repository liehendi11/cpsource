/*
Please write complete compilable code.
Read input from standard input (STDIN) and print output to standard output(STDOUT).
For more details, please check https://www.interviewstreet.com/recruit/challenges/faq/view#stdio
*/

#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <iostream>


using namespace std;

class Balance
{
//class for holding balance information
public:
    long long weightLeft, weightRight;
    vector<int> balanceLeft, balanceRight;
    long long addLeft, addRight;
    long long totalWeight;
    bool visited;
    Balance()
    {
        weightLeft = 0;
        weightRight = 0;
        balanceLeft.clear();
        balanceRight.clear();
        addLeft = 0;
        addRight = 0;
        visited = false;
        totalWeight = 0;
    }
};

long long findBalance(int x, vector<Balance> &balances)
{
    if (!balances[x].visited)
    {
        long long totalLeftWeight = balances[x].weightLeft;
        for (int i=0; i<balances[x].balanceLeft.size(); i++)
            totalLeftWeight += findBalance(balances[x].balanceLeft[i], balances);
        
        long long totalRightWeight = balances[x].weightRight;
        for (int i=0; i<balances[x].balanceRight.size(); i++)
            totalRightWeight += findBalance(balances[x].balanceRight[i], balances);
        
        if (totalLeftWeight > totalRightWeight)
        {
            balances[x].addLeft = 0;
            balances[x].addRight = totalLeftWeight - totalRightWeight;
        }
        else
        {
            balances[x].addRight = 0;
            balances[x].addLeft = totalRightWeight - totalLeftWeight;
        }
        
        balances[x].totalWeight = totalLeftWeight + balances[x].addLeft + totalRightWeight + balances[x].addRight + 10;
        balances[x].visited = true;
    }
    
    return balances[x].totalWeight;
}

int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    
    vector<Balance> balances;
    
    for (int i=0; i<n; i++)
    {
        Balance newBalance;
        string line1, line2;
        getline(cin, line1);
        getline(cin, line2);
        
        //parse input for first line
        long long inputNum;
        istringstream ss1 (line1);
        
        //get left weight
        ss1 >> inputNum;
        newBalance.weightLeft = inputNum;
        
        //get all left balances
        while (ss1>>inputNum) newBalance.balanceLeft.push_back(inputNum);
        
        
        //parse input for second line
        istringstream ss2 (line2);
        
        //get right weight
        ss2 >> inputNum;
        newBalance.weightRight = inputNum;
        while (ss2 >> inputNum) newBalance.balanceRight.push_back(inputNum);
        
        balances.push_back(newBalance);
    }
    
    for (int i=0; i<n; i++)
    {
        if (!balances[i].visited) findBalance(i, balances);
    }
    
    for (int i=0; i<n; i++)
    {
        printf("%d: %lld %lld\n", i, balances[i].addLeft, balances[i].addRight);
    }
    
    return 0;
}