#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <bits/stdc++.h> // stl libraries don't need to inculde every single header file
#include <string>
using namespace std;

int main()
{

    // VECTORS

    // vector<int> v;
    // vector<int> v2(5, 1);
    // vector<char> c(5, 'c');

    // v2[1] = 2;
    // v2[2] = 3;
    // v2[3] = 4;
    // v2[4] = 5;

    // cout << v2.at(2) << " ";
    // cout << v2.back() << " ";
    // cout << v2.front() << " ";
    // for (int i = 0; i < v2.size(); i++)
    // {
    // cout << v2[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < c.size(); i++)
    // {
    //     cout << c[i] << " ";
    // }

    // v.push_back(2);
    // v.push_back(2);
    // v.push_back(2);
    // v.push_back(2);
    // cout << v.empty() << endl;
    // cout << v.capacity() << endl;
    // v.pop_back();
    // cout << "ELEMENT : " << v.at(2) << endl;

    // ARRAYS

    // array<int,5> arr = {1,2,3,4,5};
    // array<int,5> arr;

    // cout << arr.at(2) << " ";
    // cout << arr.front() << " ";
    // cout << arr.back() << " ";
    // cout << arr.size() << " ";

    // DEQUE / DOUBLE ENDED QUEUE

    // deque<int> d;

    // d.push_back(2);
    // d.push_front(1);
    // int r = d.empty();
    // cout << r << endl;
    // cout << d.empty() << endl;
    // cout << d.front() << endl;
    // cout << d.back() << endl;
    // cout << d.at(1) << endl;
    // for (int i = 0; i < d.size(); i++)
    // {
    // cout << d[i] << endl;
    // }
    // d.erase(d.begin(), d.begin()+1);
    // d.pop_back();
    // d.pop_front();

    // LIST / DOUBLY LINKED LIST

    // list<int> c(l);          to copy another list into newly created list. l is copied to c
    // list<int> i(5,0);        1st argument is the size that is 5 and 2nd argument is to initialize
    // list<int> l;

    // l.push_back(2);
    // l.push_front(1);
    // l.pop_front();
    // l.pop_back();
    // l.push_back(1);
    // l.push_back(2);
    // l.push_back(3);
    // l.push_back(4);

    // for (int i : l)          // for range
    // {
    //     cout << i << " ";
    // }
    // l.erase(l.begin());
    // cout << l.front();
    // cout << l.back();
    // cout << l.size();

    // STACKS

    // stack<string> name;

    // name.push("saad");
    // name.push("bin");
    // name.push("abi");
    // name.push("usama");
    // cout << name.top() << endl;
    // cout << name.size() << endl;
    // name.pop();
    // name.pop();
    // name.pop();
    // cout << name.top();

    // QUEUE

    // queue<string> name;
    // name.push("saad");
    // name.push("saadi");

    // cout << name.front() << endl;
    // cout << name.back() << endl;
    // cout << name.empty() << endl;
    // cout << name.size() << endl;
    // name.pop();

    // PRIORITY QUEUE

    // MAX HEAP /DEFAULT IS MAX HEAP
    // priority_queue<int> maxi;

    // maxi.push(3);
    // maxi.push(2);
    // maxi.push(10);
    // maxi.push(7);
    // maxi.push(0);
    // int n = maxi.size();
    // for (int i = 0; i < n; i++)
    // {
    //     cout << maxi.top() << " ";
    //     maxi.pop();
    // }
    // cout << maxi.empty();

    // MIN HEAP
    // priority_queue<int, vector<int>, greater<int> > mini;

    // mini.push(2);
    // mini.push(5);
    // mini.push(7);
    // mini.push(0);
    // mini.push(11);
    // int s = mini.size();
    // for (int i = 0; i < s; i++)
    // {
    //     cout << mini.top()  << " ";
    //     mini.pop();
    // }

    // SET

    // set<int> s;

    // s.insert(1);
    // s.insert(2);
    // s.insert(3);
    // s.insert(4);
    // s.insert(5);

    // int n = s.size();
    // cout << n << endl;

    // // s.erase(1);
    // for (int i : s)
    // {
    //     cout << i << endl;
    // }

    // MAP / ORDERED MAP

    // map<int,string> name;

    // name[1] = "saad";
    // name[2] = "bin";
    // name[5] = "abi";
    // name[10] = "usama";
    // name.insert({3,"saadi"});

    // cout << name.at(2);
    // cout << name.count(10);
    // for (auto i : name)
    // {
    //     cout << i.first << " " <<i.second << " ";

    // }
    // name.erase(3);

    // ALGORITHMS

    // vector<int> t;
    // t.push_back(2);
    // t.push_back(5);
    // t.push_back(10);
    // t.push_back(15);

    // cout << binary_search(t.begin(),t.end(),10)<<endl;
    // cout << upper_bound()

    // int a = 10;
    // int b = 5;
    // cout << max(a,b)<<endl;
    // cout << min(a,b)<<endl;
    // swap(a,b);
    // cout << a << " and " << b << endl;

    // string name = "Saad";
    // reverse(name.begin(),name.end());
    // cout<<name;
    return 0;
}