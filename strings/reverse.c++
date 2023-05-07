#include <iostream>
using namespace std;

void reverse(char arr[], int size)
{
    int i = 0;
    int j = size - 1;
    while (i < j)
    {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

// same as above but with a little tweak in code

void reverse2(char arr[], int n)
{
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        swap(arr[i++], arr[j--]);
    }
}
void print(char A[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main()
{
    char name[5] = {"saad"};
    reverse2(name, 5);
    print(name, 5);
    return 0;
}