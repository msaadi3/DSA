#include <bits/stdc++.h>
using namespace std;

// Trie is also called prefix tree
// Trie deletion function is remaining
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

// T.C of insertion / deletion / searching in trie is O(l) and T.C of starts with / prefix is O(P) where p is the length of the prefix
// Using Recursion
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
        int index = word[0] - 'A';
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

    // Searching
    bool searchUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            return root->isTerminal;
        }

        // assumption, word will be in CAPS
        int index = word[0] - 'A';
        TrieNode *child;

        // character present case
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // character absent case
            return false;
        }

        // Recursion
        return searchUtil(child, word.substr(1));
    }

    bool search(string word)
    {
        return searchUtil(root, word);
    }

    // Prefix / starts with

    bool prefixUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            return true;
        }

        // assumption, word will be in CAPS
        int index = word[0] - 'A';
        TrieNode *child;

        // character present case
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // character absent case
            return false;
        }

        // Recursion
        return prefixUtil(child, word.substr(1));
    }

    bool startsWith(string prefix)
    {
        return prefixUtil(root, prefix);
    }

    // Deletion
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

// ----------------------------------------------------------------------------------------------------------------------------------------

// Iterative approach of all operations
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

    void insert(string word)
    {
        TrieNode *node = root;

        for (char ch : word)
        {
            // assumption word will be in no CAPS
            int index = ch - 'a';
            if (node->children[index] == NULL)
            {
                node->children[index] = new TrieNode(ch);
                node = node->children[index];
            }
            else
            {
                node = node->children[index];
            }
        }
        node->isTerminal = true;
    }

    // Searching

    bool search(string word)
    {

        TrieNode *node = root;

        for (char ch : word)
        {
            // assumption word will be in no CAPS
            int index = ch - 'a';
            if (node->children[index] != NULL)
            {
                node = node->children[index];
            }
            else
            {
                return false;
            }
        }

        if (node->isTerminal)
        {
            return true;
        }

        return false;
    }

    // Prefix / starts with

    bool startsWith(string prefix)
    {
        TrieNode *node = root;

        for (char ch : prefix)
        {
            // assumption word will be in no CAPS
            int index = ch - 'a';
            if (node->children[index] != NULL)
            {
                node = node->children[index];
            }
            else
            {
                return false;
            }
        }
        return true;
    }

    // Deletion
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */