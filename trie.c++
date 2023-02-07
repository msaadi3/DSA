#include <iostream>
#include <string>
using namespace std;

class trieNode
{

public:
    trieNode *children[26];
    bool eow;

    trieNode()
    {
        for (int i = 0; i <= 26; i++)
        {
            children[i] = NULL;
        }
        eow = false;
    };

    trieNode *root;
    // INSERT

    void insert(string word)
    {
        trieNode *temp = root;
        for (int i = 0; i < word.length(); i++)
        {
            int index = word.at(i) - 'a';

            if (root->children[index] == NULL)
            {
                temp->children[index] = new trieNode();
            }

            if (temp->children[index] != NULL)
            {
                temp = temp->children[index];
            }

            if (i == word.length() - 1)
            {
                temp->children[index]->eow = true;
            }
        }
    }

    // SEARCHING
    bool searching(string key)
    {
        trieNode *temp = root;
        for (int i = 0; i < key.length(); i++)
        {
            int index = key.at(i) - 'a';
            if (temp->children[index] == NULL)
            {
                return false;
            }

            if (i == key.length() - 1 && temp->children[index]->eow == false)
            {
                return false;
            }
            temp = temp->children[index];
        }
        return true;
    }
};

int main()
{
    trieNode t;
    t.insert("word");
    // auto re = t.searching();
    // cout << re;

    return 0;
}