#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &nums)
{
    int size = nums.size();
    int count = 0;

    for (int i = 1; i < size; i++)
    {
        if (nums[i - 1] > nums[i])
        {
            count++;
        }
    }

    if (nums[size - 1] > nums[0])
    {
        count++;
    }

    // or we can do this way using modulus
    // for (int i = 0; i < size; i++)
    // {
    //     if (nums[i] > nums[(i + 1) % size])
    //     {
    //         count++;
    //     }
    // }

    // if(count <= 1){
    //     return true;
    // }
    // return false;

    return count <= 1;
}

int main()
{
    return 0;
}