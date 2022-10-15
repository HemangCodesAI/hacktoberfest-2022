#include <iostream>
#include <vector>
using namespace std;

class TrieNode
{
    public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for(int i=0; i<26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};
class Trie
{
    TrieNode *root;
    public:
    int count;

    Trie()
    {
        root = new TrieNode('\0');
        count = 0;
    }

    void insertWord(TrieNode *root, string word)
    {
        if(word.length() == 0)
        {
            if(!root->isTerminal)
            {
                root->isTerminal = true;
            }
            return;
        }
        int index = word[0] - 'a';
        TrieNode *child;
        if(root->children[index])
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertWord(child, word.substr(1));
    }
    void insertWord(string word)
    {
        insertWord(root, word);
    }

    bool searchWord(TrieNode *root, string word)
    {
        if(word.size() == 0)
        {
            return true;
        }
        int index = word[0] - 'a';
        TrieNode *child;
        if(root->children[index])
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }
        return searchWord(child, word.substr(1));
    }
    bool searchWord(string word)
    {
        return searchWord(root, word);
    }

    bool patternMatching(vector<string> vect, string pattern)
    {
        for(int i=0; i<vect.size(); i++)
        {
            string word = vect[i];
            for(int j=0; j<word.length(); j++)
            {
                insertWord(word.substr(j));
            }
        }
        return searchWord(pattern);
    }
};
int main()
{
    Trie t;
    int n;
    cin>>n;
    string word, pattern;
    vector<string> vect;
    for(int i=0; i<n; i++)
    {
        cin>>word;
        vect.push_back(word);
    }
    cin>>pattern;
    cout<<(t.patternMatching(vect, pattern) ? "true":"false")<<endl;
}