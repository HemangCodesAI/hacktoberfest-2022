// Permutation of a given number is the number of ways
// one can arrange the digits of the number & obtain
// unique numbers.
// There can be 'n!' permutations for a number with 'n' digits.
// This program gives you the 'k'th permutation for the given number
// without figuring out the other permutations.

#include <bits/stdc++.h>
using namespace std;

int getNthPermutation(int n, int k)
{
    k--;
    int res = 0;
    vector<int> nums;
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
        nums.push_back(i);
    }
    // fact = fact / n;
    while (n > 0)
    {
        fact = fact / n;
        res = res * 10 + nums[k / fact];
        nums.erase(nums.begin() + k / fact);
        k = k % fact;
        n--;
    }
    return res;
}

int main()
{
    int n;
    int k;
    cout << "Enter the no. of digits of your number : ";
    cin >> n;
    cout << "Enter the no of permutation you want : ";
    cin >> k;

    cout << getNthPermutation(n, k) << endl;
}