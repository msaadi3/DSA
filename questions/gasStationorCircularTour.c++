#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int dificit = 0;
        int balance = 0;
        int start = 0;

        for (int i = 0; i < gas.size(); i++)
        {
            balance += gas[i] - cost[i];
            if (balance < 0)
            {
                dificit += balance;
                start = i + 1;
                balance = 0;
            }
        }

        if (dificit + balance >= 0)
        {
            return start;
        }
        else
        {
            return -1;
        }
    }
};
