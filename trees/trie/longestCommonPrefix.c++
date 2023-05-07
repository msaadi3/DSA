#include <bits/stdc++.h>
using namespace std;

// Not the best approach but just to prectise trie other accepted approaches of this problem is in strings folder
// not accepted on leet code and coding ninjas failing one test case at run time i don't know why so i just left it / didn't get it

class TrieNode
{
public:
    TrieNode *children[26];
    bool isTerminal;
    char data;
    int childCount;
    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie(char ch)
    {
        root = new TrieNode(ch);
    }

    // Insertion
    void insertUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // assumption, word will be in CAPS
        int index = word[0] - 'a';
        TrieNode *child;

        // present case
        if (root->children[index] != NULL)
        {
            // move forward
            child = root->children[index];
        }
        else
        {
            // absent case
            // create node for it
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }

        // recursive call
        insertUtil(child, word.substr(1));
    }

    void insert(string word)
    {
        insertUtil(root, word);
    }

    void lcp(string word, string &ans)
    {
        for (int i = 0; i < word.length(); i++)
        {
            char ch = word[i];

            if (root->childCount == 1)
            {
                ans.push_back(ch);

                int index = ch - 'a';
                root = root->children[index];
            }
            else
            {
                break;
            }

            if (root->isTerminal)
            {
                break;
            }
        }
    }
};

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
        {
            return "";
        }

        Trie *t = new Trie('\0');

        // insert all strings in trie
        for (int i = 0; i < strs.size(); i++)
        {
            t->insert(strs[i]);
        }

        string word = strs[0];
        string ans = "";
        t->lcp(word, ans);
        return ans;
    }
};