// Given n number of words and an incomplete word w. You need to auto-complete that word w.
// That means, find and print all the possible words which can be formed using the incomplete word w.

// Input Format :
// The first line of input contains an integer, that denotes the value of n.
// The following line contains n space separated words.
// The following line contains the word w, that has to be auto-completed.

// Output Format :
// Print all possible words in separate lines.

// Input:
// 7
// do dont no not note notes den
// no

// Output:
// no
// not
// note
// notes

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word) {
        if (insertWord(root, word)) {
            this->count++;
        }
    }
    
    void printAllOccurence(TrieNode *root, string pattern, string result)
    {
        if(pattern.length() == 0)
        {
            if(root->isTerminal)
            {
                cout<<result<<endl;
            }
            for(int i=0; i<26; i++)
            {
                if(root->children[i])
                {
                    TrieNode *child = root->children[i];
                    printAllOccurence(child, pattern, result + child->data);
                }
            }
            return;
        }
        int index = pattern[0] - 'a';
        TrieNode *child;
        if(root->children[index])
        {
            child = root->children[index];
        }
        else
        {
            return;
        }
        printAllOccurence(child, pattern.substr(1), result + pattern[0]);
    }
    void autoComplete(vector<string> input, string pattern) {
        for(int i=0; i<input.size(); i++)
        {
            insertWord(input[i]);
        }
        printAllOccurence(root, pattern, "");
    }
};

int main() {
    Trie t;
    int n;
    cin >> n;

    vector<string> vect;

    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        vect.push_back(word);
    }

    string pattern;
    cin >> pattern;

    t.autoComplete(vect, pattern);
}