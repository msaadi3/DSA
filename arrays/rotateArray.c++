#include <bits/stdc++.h>
using namespace std;

// shifting ith in cyclic way around kth position
// arr[(i + k) % n] = arr[i]

void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> temp(n);
    for (int i = 0; i < n; i++)
    {
        temp[(i + k) % n] = nums[i];
    }
    nums = temp;
}

void printArr(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
}

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    rotate(v, 1);
    printArr(v);

    return 0;
}
