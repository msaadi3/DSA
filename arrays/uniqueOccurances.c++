#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> count;
        set<int> s;

        for (int i = 0; i < arr.size(); i++)
        {
            count[arr[i]]++;
        }

        for (auto i = count.begin(); i != count.end(); i++)
        {
            s.insert(i->second);
        }

        return s.size() == count.size() ? true : false;
    }
};

// Another one / best approach / faster than 100%

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> m;
        set<int> s;

        for (auto i : arr)
        {
            m[i]++;
        }

        for (auto i : m)
        {
            // auto c = s.insert(i.second);
            if (!s.insert(i.second).second)
            {
                return false;
            }
        }

        return true;
    }
};
int main()
{
    return 0;
}