// You are given an integer N and a binary 2D array of size N*N. The given binary matrix represents a maze and a rat starts from the top left cell and has to reach to the bottom right cell of the maze. The rat can move in all the four directions: up, down, left and right.
// In the given binary matrix, 0 signifies the cell is a dead end and 1 signifies the cell can be used to move from source to destination cell.
// You have to print all the paths, following which rat can move from the top left cell to the bottom right cell of the given binary matrix.

// Input Format
// The first line of input contains an integer, that denotes the value of N.
// Each of the following N lines denote rows of the binary matrix and contains either 0 or 1. Each row of the binary matrix contains N elements. 

// Output Format :
// Every possible solution has to be printed on a separate line. Each of the possible solution will have N*N elements, printed row wise and separated by space. The cells that are part of the path should be 1 and remaining all cells should be 0. Please refer to sample test cases for more clarity.   

// Input :
// 3
// 1 0 1
// 1 1 1
// 1 1 1

// Output :
// 1 0 0 1 1 1 1 1 1 
// 1 0 0 1 0 0 1 1 1 
// 1 0 0 1 1 0 0 1 1 
// 1 0 0 1 1 1 0 0 1 

#include<bits/stdc++.h>
using namespace std;

void ratInMaze(int **arr, int x, int y, int n, int **sol)
{
    if(x == n-1 && y == n-1 && arr[x][y] == 1)
    {
        sol[x][y] = 1;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<sol[i][j]<<" ";
            }
        }
        sol[x][y] = 0;
        cout<<endl;
        return;
    }
    if(x >= n || x < 0 || y >= n || y < 0 || arr[x][y] == 0 || sol[x][y] == 1)
    {
        return;
    }
    sol[x][y] = 1;
    ratInMaze(arr, x+1, y, n, sol);
    ratInMaze(arr, x-1, y, n, sol);
    ratInMaze(arr, x, y+1, n, sol);
    ratInMaze(arr, x, y-1, n, sol);
    sol[x][y] = 0;
    return;
}
int main() {
    int n;
    cin>>n;
    int **arr = new int*[n];
    for(int i=0; i<n; i++)
    {
        arr[i] = new int[n];
        for(int j=0; j<n; j++)
        {
            cin>>arr[i][j];
        }
    }
    int **sol = new int*[n];
    for(int i=0; i<n; i++)
    {
        sol[i] = new int[n];
        for(int j=0; j<n; j++)
        {
            sol[i][j] = 0;
        }
    }
    ratInMaze(arr, 0, 0, n, sol);
    return 0;
}
