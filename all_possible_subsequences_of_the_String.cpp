// Problem Statement: Given a string, find all the possible subsequences of the string.

// Example 1:
// Input: str = "abc"
// Output: a ab abc ac b bc c
// Explanation: Printing all the 7 subsequence for the string "abc".

// Example 2:
// Input: str = "aa"
// Output: a a aa 
// Explanation: Printing all the 3 subsequences for the string "aa"

#include<bits/stdc++.h>
using namespace std;
vector<string> AllPossibleStrings(string s) {
	int n = s.length();
	vector<string>ans;
	for (int num = 0; num < (1 << n); num++) {
		string sub = "";
		for (int i = 0; i < n; i++) {
			//check if the ith bit is set or not
			if (num & (1 << i)) {
				sub += s[i];
			}
		}
		if (sub.length() > 0) {
			ans.push_back(sub);
		}
	}
	sort(ans.begin(), ans.end());
	return ans;
}
int main()
{


	string s="abc";
	vector<string>ans = AllPossibleStrings(s);
	//printint all the subsequence.
	cout<<"All possible subsequences are "<<endl;
	for (auto it : ans) {
		cout << it << " ";
	}

}
