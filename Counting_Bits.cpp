// Problem statement : Given an integer n, return an array ans whose length is n+1 such that for each i (0 <= i <= n) ans[i] is the number of 1’s in binary representation of i. 

// Example:

// Input:  n = 5
// Output: [0, 1, 1, 2, 1, 2 ]

#include <bits/stdc++.h>
using namespace std;

vector<int> countingSetBits(int n)
{
    vector<int> ans(n + 1);
    for (int i = 0; i <= n; i++)
    {
        int num = i, cnt = 0;
        while (num > 0)
        {
            if (num & 1)
                cnt++;
            num = num >> 1;
        }
        ans[i] = cnt;
    }
    return ans;
}
int main()
{
    int n=5;
    vector<int> ans = countingSetBits(n);
    for (auto &val : ans)
        cout << val << " ";
    return 0;
} 
