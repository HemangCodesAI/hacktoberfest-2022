// Problem Statement : Given two Strings let’s say  S and P, return the array of all start indices of P’s anagram in S.

// An Anagram is a word or phrase or name formed by rearranging the letters of another word or phrase or name.

// Note: S and P contains only Lower Case Letters

// Examples: 

// Example 1: 
// Input: S = “abcdefcbagbac”, P = “abc”
// Output:  [0,6,10]
// Explanation: 
// substrings with starting indexes 0,6,10 and 
// having length equal to length of P are 
// “abc” , “cba”, “bac”. 
// These substrings can be formed by arranging 
// the characters in string P. Hence they are 
// the anagrams of string P.

// Example 2: 
// Input: S = “tufuftfut”, P = “tuf”
// Output:  [0,3,5,6]
// Explanation: substrings with starting indexes 
// 0,3,5,6 and having length equal to length of 
// P are “tuf”, “uft”, ,”tfu”,”fut”. 
// These substrings can be formed by arranging 
// the characters in string P. Hence they are the 
// anagrams of string P.


#include <bits/stdc++.h>
using namespace std;

vector<int> FindAnagrams(string &s, string &p)
{
    vector<int> ans;
    int n = s.length(), m = p.length();
    // sortedP stores the sorted version of string P
    string sortedp = p;
    sort(sortedp.begin(), sortedp.end());
    string temp;
    for (int i = 0; i <= (n - m); i++)
    {
        temp = "";
        // temp stores the every substring of length m
        for (int k = i; k < m + i; k++)
            temp.push_back(s[k]);
        sort(temp.begin(), temp.end());
        // checking sorted version of substring equal to sorted P are not
        if (temp == sortedp)
            ans.push_back(i);
    }
    return ans;
}
int main()

{
    string s = "tufuftfut", p = "tuf";
    vector<int> arr = FindAnagrams(s, p);
    if (arr.empty())
        cout << "There are No Anagrams of " << p << " in " << s << endl;
    else
    {
        cout << "starting Indices of Anagrams are " << endl;
        for (auto &val : arr)
            cout << val << " ";
    }
    return 0;
} 
