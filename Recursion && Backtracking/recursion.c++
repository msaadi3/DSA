#include <iostream>
#include <string>
using namespace std;

// FACTORIAL
int factorial(int n)
{
    // Base Case
    if (n == 0)
    {
        return 1;
    }

    // Processing
    // cout << n << endl;

    // Recursive Relation
    return n * factorial(n - 1);

    // int smallerProblem = factorial(n-1);
    // int biggerProblem = n * smallerProblem;
    // return biggerProblem;
}

// FIBONACCI
int fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }

    if (n == 1)
    {
        return 1;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);

    // int ans = fibonacci(n-1) + fibonacci(n-2);

    // return ans;
}

// POWER OF 2 / 2^n
int power(int n)
{
    // base case (mandatory)
    if (n == 0)
    {
        return 1;
    }

    // processing (optional)

    // cout << n << endl;

    // recursive relation (mandatory)
    return 2 * power(n - 1);

    // int smallerProblem = power(n-1);
    // int biggerProblem = 2 * smallerProblem;
    // return biggerProblem;
}

void countingForward(int n, int f)
{
    if (n > f)
    {
        return;
    }

    cout << n << " , ";

    countingForward(n + 1, f);

    // cout << n << endl;
}

void countingBackward(int n)
{
    if (n < 0)
    {
        return;
    }

    cout << n << " , ";

    countingBackward(n - 1);

    // cout << n << endl;
}

void reachHome(int src, int dest)
{

    // processing
    cout << src << " ";

    // base case
    if (src == dest)
    {
        cout << "i reached home";
        return;
    }

    // recursive relation
    reachHome(src + 1, dest);
}

void sayDigits(int number)
{
    if (number == 0)
    {
        return;
    }

    int digit = number % 10;
    number = number / 10;

    string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    sayDigits(number);
    cout << arr[digit] << " ";
}

// ISSORTED USING RECURSION
bool isSorted(int arr[], int size)
{
    if (size == 0 || size == 1)
    {
        return true;
    }

    if (arr[0] > arr[1])
    {
        return false;
    }

    bool ans = isSorted(arr + 1, size - 1);
    return ans;
}

// SUM OF ARRAY ELEMENTS
int sumArr(int arr[], int size)
{
    if (size == 0)
    {
        return 0;
    }

    if (size == 1)
    {
        return arr[0];
    }

    int remainingPart = sumArr(arr + 1, size - 1);
    int sum = arr[0] + remainingPart;
    return sum;
}

// PRINT ARRAY UTIL FUNCTION FOR LINEAR SEARCH TO SEE PROCESSING
void print(int arr[], int size)
{
    cout << "size of array is " << size << endl;

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// LINEAR SEARCH
bool linearSearch(int arr[], int size, int key)
{
    print(arr, size);
    if (size == 0)
    {
        return false;
    }

    if (arr[0] == key)
    {
        return true;
    }

    // return linearSearch(arr+1, size-1, key);
    bool ans = linearSearch(arr + 1, size - 1, key);
    return ans;
}

// PRINT ARRAY UTIL FUNCTION FOR BINARY SEARCH TO SEE PROCESSING
void printForBinarySearch(int arr[], int start, int end)
{

    for (int i = start; i <= end; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// BINARY SEARCH
bool binarySearch(int arr[], int start, int end, int key)
{

    printForBinarySearch(arr, start, end);
    if (start > end)
    {
        return false;
    }

    int mid = start + (end - start) / 2;

    cout << " mid: " << arr[mid] << endl;
    // cout << " mid: " << mid << endl;

    if (arr[mid] == key)
    {
        return true;
    }

    if (arr[mid] > key)
    {
        return binarySearch(arr, start, mid - 1, key);
    }
    return binarySearch(arr, mid + 1, end, key);
}

// ____________________________________________________________________________________________________________________________________________

// RECURSION WITH STRINGS

void reverse(string &name, int i, int j)
{
    cout << "call recevied for " << name << endl;
    // BASE CASE
    if (i > j)
    {
        return;
    }

    swap(name[i++], name[j--]);
    // i++;
    // j--;

    // RECURSIVE RELATION
    reverse(name, i, j);
}

string reverseString(string str)
{
    reverse(str, 0, str.length() - 1);
    return str;
}

// PALINDROME

bool isPalindrome(string str, int i, int j)
{
    if (i > j)
    {
        return true;
    }

    if (str[i] != str[j])
    {
        return false;
    }

    return isPalindrome(str, i + 1, j - 1);
}

// POWER FUNCTION IN MORE OPTIMIZED WAY

int powerOptimized(int a, int b)
{
    // 'b' is power of 'a'
    // base case
    if (b == 0)
    {
        return 1;
    }

    if (b == 1)
    {
        return a;
    }

    // recursive relation
    int ans = powerOptimized(a, b / 2);
    if (b % 2 == 0)
    {
        // if b is even
        return ans * ans;
    }
    // if b is odd
    return a * ans * ans;
}

int main()

{

    // int n;
    // cout << "enter number" << endl;
    // cin >> n;

    // int ans = factorial(n);
    // cout << ans;

    // int n;
    // cout << "enter number" << endl;
    // cin >> n;

    // int ans = power(n);
    // cout << ans;

    // int n;
    // cout << "enter number" << endl;
    // cin >> n;

    // countingBackward(n);

    // int n, f;
    // cout << "enter number from where you want to start your counting" << endl;
    // cin >> n;
    // cout << "enter number till you want to print counting" << endl;
    // cin >> f;

    // countingForward(n,f);

    // int s, d;
    // cout << "enter your current location";
    // cin >> s;
    // cout << "enter your destination";
    // cin >> d;
    // reachHome(s, d);

    // int n;
    // cout << "enter number ";
    // cin >> n;

    // int ans = fibonacci(n);
    // cout << ans;

    // int number;
    // cout << "enter number" << endl;
    // cin >> number;
    // sayDigits(number);

    // int array[] = {1,3,5,7,9};
    // bool ans = isSorted(array, 5);
    // if (ans)
    // {
    //     cout << " array is sorted ";
    // } else
    // {
    //     cout << "array is not sorted ";
    // }

    // int array[] = {1,3,5,7,9};
    // int ans = sumArr(array, 5);
    // cout << ans;

    // int array[] = {1, 3, 5, 7, 9};
    // int size = 5;
    // int key = 7;

    // bool ans = linearSearch(array, size, key);
    // if (ans)
    // {
    //     cout << key << " is found ";
    // }
    // else
    // {
    //     cout << key << " is not found ";
    // }

    // int array[] = {1, 3, 5, 7, 9};
    // int key = 3;

    // bool ans = binarySearch(array, 0, 4, key);
    // if (ans)
    // {
    //     cout << key << " is found ";
    // }
    // else
    // {
    //     cout << key << " is not found ";
    // }

    // ________________________________________________________________________________________________________________________________________

    // RECURSION WITH STRINGS

    // string name = "abcde";
    // reverseString(name,0,name.length()-1);
    // cout << name;

    // string str = "abbccbba";
    // bool ans = isPalindrome(str, 0, str.length() - 1);
    // if (ans)
    // {
    //     cout << " yes it is a palindrome ";
    // }
    // else
    // {
    //     cout << " it is not a palindrome ";
    // }

    // int a, b;
    // cout << " enter number " << endl;
    // cin >> a;
    // cout << " enter power " << endl;
    // cin >> b;

    // int ans = powerOptimized(a,b);
    // cout << ans;
}