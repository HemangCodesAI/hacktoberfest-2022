// Problem statement: Given a matrix, your task is to rotate matrix anti-clockwise by 90 degrees.

// Examples:

// Example 1:
// Input:   {{1,2,3},
//           {4,5,6},
//           {7,8,9}}
// Output:
//         3 6 9 
//         2 5 8 
//         1 4 7 
// Explanation: Rotate the matrix anti-clockwise by 90 degrees and return it.

// Example 2:
// Input:    {{1,2,3,4},   
//            {5,6,7,8},   
//            {9,10,11,12},  
//            {13,14,15,16}}
// Output:
//         4 8 12 16 
//         3 7 11 15 
//         2 6 10 14 
//         1 5 9 13 
// Explanation: Rotate the matrix anti-clockwise by 90 degrees and return it.

#include<bits/stdc++.h>

using namespace std;

void rotate(int matrix[][3]) {
  int n = 3;

  //Creating new matrix to store rotated values
  int temp[n][n];

  int ind = n - 1;
  for (int i = 0; i < n; i++) {

    for (int j = 0; j < n; j++) {
      temp[i][j] = matrix[j][ind];
    }
    ind--;
  }
  //Printing array after rotation
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << temp[i][j] << " ";
    }
    cout << endl;
  }
}
int main() {
  int matrix[][3] = {{1,2,3},{4,5,6},{7,8,9}};

  rotate(matrix);

}
