// Problem Statement: Given a Matrix, print the given matrix in spiral order.

// Examples:

// Example 1:
// Input: Matrix[][] = { { 1, 2, 3, 4 },
// 		      { 5, 6, 7, 8 },
// 		      { 9, 10, 11, 12 },
// 	              { 13, 14, 15, 16 } }

// Outhput: 1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10.
// Explanation: The output of matrix in spiral form.

// Example 2:
// Input: Matrix[][] = { { 1, 2, 3 },
// 	              { 4, 5, 6 },
// 		      { 7, 8, 9 } }
			    
// Output: 1, 2, 3, 6, 9, 8, 7, 4, 5.
// Explanation: The output of matrix in spiral form.


#include <bits/stdc++.h>

using namespace std;

const int R = 4, C = 4;

void printSpiral(int mat[4][4], int R, int C) {
  int top = 0, left = 0, bottom = R - 1, right = C - 1;

  while (top <= bottom && left <= right) {
    for (int i = left; i <= right; i++)
      cout << mat[top][i] << " ";

    top++;

    for (int i = top; i <= bottom; i++)
      cout << mat[i][right] << " ";

    right--;

    if (top <= bottom) {
      for (int i = right; i >= left; i--)
        cout << mat[bottom][i] << " ";

      bottom--;
    }

    if (left <= right) {
      for (int i = bottom; i >= top; i--)
        cout << mat[i][left] << " ";

      left++;
    }
  }
}

int main() {
  int arr[R][C] = {{1, 2, 3, 4},
                   {5, 6, 7, 8},
	           {9, 10, 11, 12},
		   {13, 14, 15, 16}};
  printSpiral(arr, R, C);

  return 0;
}
