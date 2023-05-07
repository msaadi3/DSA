#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void solve(stack<int> &s, int sizeOfStack, int cnt)
    {
        // base case
        if (cnt == sizeOfStack / 2)
        {
            s.pop();
            return;
        }

        int top = s.top();
        s.pop();

        // recursive call
        solve(s, sizeOfStack, cnt + 1);

        // push back the top elements while returning from recursive calls
        s.push(top);
    }

public:
    // Function to delete middle element of a stack.
    void deleteMid(stack<int> &s, int sizeOfStack)
    {
        int cnt = 0;
        solve(s, sizeOfStack, cnt);
    }
};

int main()
{
    return 0;
}