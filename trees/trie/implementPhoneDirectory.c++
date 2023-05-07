#include <bits/stdc++.h>
using namespace std;

// T.C is (n*m2) and S.C is (n*m)  where n is the number of strings in the vector and m is the averege length of string
class TrieNode
{
public:
    TrieNode *children[26];
    bool isTerminal;
    char data;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0');
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
            root->children[index] = child;
        }

        // recursive call
        insertUtil(child, word.substr(1));
    }

    void insert(string word)
    {
        insertUtil(root, word);
    }

    void printSuggestions(TrieNode *curr, string &prefix, vector<string> &temp)
    {
        if (curr->isTerminal)
        {
            temp.push_back(prefix);
            // return;  // why we removed return statment from here
        }

        TrieNode *next = NULL;

        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            next = curr->children[ch - 'a'];

            if (next != NULL)
            {
                prefix.push_back(ch);
                printSuggestions(next, prefix, temp);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestions(string &queryStr)
    {
        TrieNode *prev = root;
        vector<string> temp;
        vector<vector<string>> ans;
        string prefix = "";

        for (int i = 0; i < queryStr.size(); i++)
        {
            char lastChar = queryStr[i];
            prefix.push_back(lastChar);

            TrieNode *curr = prev->children[lastChar - 'a'];

            // if not found
            if (curr == NULL)
            {
                break;
            }
            else
            {
                // if found
                printSuggestions(curr, prefix, temp);
                ans.push_back(temp);
                temp.clear();
                prev = curr;
            }
        }

        return ans;
    }
};

vector<vector<string>> phoneDirectory(vector<string> &contactList, string &queryStr)
{
    Trie *t = new Trie();

    // insert contact list in trie
    for (int i = 0; i < contactList.size(); i++)
    {
        string str = contactList[i];
        t->insert(str);
    }

    return t->getSuggestions(queryStr);
}