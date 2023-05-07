#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
using namespace std;

// HASHING:

// IMPLEMENTATION OF HASHTABLE/HASHING/HASH_MAP IS REMAINING

// MAPS:

//                  | map                | unordered_map        | multi_map
// -------------------------------------------------------------------------------
// Ordering        | increasing  order   | no ordering          |
//                 | (by default)        |                      |

// Implementation  | Self balancing BST  | Hash Table           | Self balancing BST
//                 | like Red-Black Tree |                      | like red black tree

// search time     | log(n)              | O(1) -> Average      | time complexity same
//                 |                     | O(n) -> Worst Case   | as map (i think so)

// Insertion time  | log(n) + Rebalance  | Same as search       |

// Deletion time   | log(n) + Rebalance  | Same as search       |

// MULTIMAP IS VERY SIMILAR TO MAP BUT IN MULTIMAP VALUES CAN HAVE THE SAME KEY. THERE'S NO CONSTRAINAT OF HAVING UNIQUE KEYS IN MULTIMAP

// SETS:

//                 |     set             | unordered_set        | multi_set
// -------------------------------------------------------------------------------
// Ordering        | increasing  order   | no ordering          |
//                 | (by default)        |                      |

// Implementation  | Self balancing BST  | Hash Table           | Self balancing BST
//                 | like Red-Black Tree |                      | like Red-Black Tree

// search time     | log(n)              | O(1) -> Average      | time complexity same
//                 |                     | O(n) -> Worst Case   | as set (i think so)

// Insertion time  | log(n) + Rebalance  | Same as search       |

// Deletion time   | log(n) + Rebalance  | Same as search       |

// MULTISET IS VERY SIMILAR TO SET. THE ONLY DIFFERENCE IN MULTISET IS THAT MULTISET CAN CONTAIN DUPLICATES THERE'S NO CONSTRAINAT OF HAVING ONLY UNIQUE VALUES

// I think so (hash_maps in java / unordered_map in C++ / hash_set in java / unordered_set in C++)
int main()
{

    // MAP CREATION
    unordered_map<int, string> name;

    // INSERTION

    // 1ST METHOD:
    pair<int, string> p = make_pair(1, "Saad");
    name.insert(p);

    // 2ND METHOD:
    pair<int, string> p2(2, "saadi");
    name.insert(p2);

    // 3RD METHOD:
    name[3] = "saaad";

    // Search

    cout << name.at(2) << endl;
    cout << name[1] << endl;

    // MISCELLENIOUS
    cout << name.count(5) << endl;

    cout << name.size() << endl;

    name.erase(3);

    for (auto i : name)
    {
        cout << i.first << " " << i.second << endl;
    }

    // TRAVERSE THROUGH ITERATOR
    // unordered_map<int, string>::iterator it = name.begin();
    // other way
    auto it = name.begin();

    while (it != name.end())
    {
        cout << it->first << " " << it->second << endl;
        // cout << &(*it);
        it++;
    }

    // SET / UNORDERED SET

    // set and unordered set are same except the difference of ordered and unordered. i.e. only unique value.
    unordered_set<int> set;

    set.insert(2);
    set.insert(8);
    set.insert(12);

    // set.clear();
    // set.erase(set.begin(), set.end());
    // cout << set.size() << endl;
    // cout << set.count(8) << endl;

    // TRAVERSAL

    // 1ST METHOD:
    for (int i : set)
    {
        cout << i << endl;
    }

    // 2ND METHOD:
    for (auto i = set.begin(); i != set.end(); i++)
    {
        cout << (*i) << endl;
    }

    // 3RD METHOD / THORUGH ITERATOR
    unordered_set<int>::iterator si = set.begin();
    // auto si = set.begin();
    while (si != set.end())
    {
        cout << (*si) << endl;
        si++;
    }

    return 0;
}