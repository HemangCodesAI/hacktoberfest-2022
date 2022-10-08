// Question :-
// Given a string s, return the longest palindromic substring in s.
// A string is called a palindrome string if the reverse of that string is the same as the original string.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int find(int i,int j, string s){
        int ans=0,n=s.length();
        while(i>0 && j<n){
            if(s[i]==s[j]) ans+=2;
            else return ans;
            i--;j++;
        }
        return ans;
    }
    string longestPalindrome(string s) {
        int i=0,j=0;
        int n=s.length();
        int maxi=0;
        while(j<n){
            if(s[i]==s[j])
                maxi=max(maxi,find(i,j,s));
            i++;j++;
        }
        i=0,j=2;
        while(j<n){
            if(s[i]==s[j])
                maxi=max(maxi,1+find(i,j,s));
            i++;j++;
        }
        return maxi;
    }
};