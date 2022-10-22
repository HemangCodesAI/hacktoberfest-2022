// Given a chain of matrices A1, A2, A3,.....An, you have to figure out the most efficient way to multiply these matrices. In other words, determine where to place parentheses to minimize the number of multiplications.
// You will be given an array p[] of size n + 1. Dimension of matrix Ai is p[i - 1]*p[i]. You need to find minimum number of multiplications needed to multiply the chain.

// Input Format:
// The first line of input contains an integer, that denotes the value of n. The following line contains n+1 integers, that denote the value of elements of array p[].

// Output Format:
// The first and only line of output prints the minimum number of multiplication needed.

// Input :
// 3
// 10 15 20 25

// Output :
// 8000

// Output Explanation:
// There are two ways to multiply the chain - A1*(A2*A3) or (A1*A2)*A3.
// If we multiply in order- A1*(A2*A3), then number of multiplications required are 11250.
// If we multiply in order- (A1*A2)*A3, then number of multiplications required are 8000.
// Thus minimum number of multiplications required are 8000.

#include <iostream>
#include <climits>
using namespace std;

int helper(int *arr, int start, int end, int **output)
{
    if(start == end - 1)
    {
        return 0;
    }
    if(output[start][end] != -1)
    {
        return output[start][end];
    }
    int mn = INT_MAX;
    for(int k=start+1; k<end; k++)
    {
        int count = helper(arr, start, k, output) + helper(arr, k, end, output) + arr[start] * arr[k] * arr[end];
        
        mn = min(mn, count);
    }
    output[start][end] = mn;
    return mn;
}
int matrixChainMultiplication(int* arr, int n)
{
    int **output = new int*[n + 1];
    for(int i=0; i<= n; i++)
    {
        output[i] = new int[n + 1];
        for(int j=0; j<=n; j++)
        {
            output[i][j] = -1;
        }
    }
    return helper(arr, 0, n, output);
}

int main()
{
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i <= n; i++) {
        cin >> arr[i];
    }

    cout << matrixChainMultiplication(arr, n);

    delete[] arr;
}