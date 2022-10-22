// A 9*9 sudoku board. The board contains non zero and zero values. Non zero values lie in the range: [1, 9]. Cells with zero value indicate that the particular cell is empty and can be replaced by non zero values.
// You need to find out whether the sudoku board can be solved. If the sudoku board can be solved, then print true, otherwise print false.

// Input Format:
// There are nine lines in input. Each of the nine lines contain nine space separated integers. These nine lines represent the sudoku board.

// Output Format:
// The first and only line of output contains boolean value, either true or false, as described in problem statement.

// Constraints:
// The cell values lie in the range: [0, 9]

// Input :
// 9 0 0 0 2 0 7 5 0 
// 6 0 0 0 5 0 0 4 0 
// 0 2 0 4 0 0 0 1 0 
// 2 0 8 0 0 0 0 0 0 
// 0 7 0 5 0 9 0 6 0 
// 0 0 0 0 0 0 4 0 1 
// 0 1 0 0 0 5 0 8 0 
// 0 9 0 0 7 0 0 0 4 
// 0 8 2 0 4 0 0 0 6

// Output :
// true

#include <bits/stdc++.h>
using namespace std;
# define N 9

bool findEmptyLocation(int grid[N][N], int &row, int &col)
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(grid[i][j] == 0)
            {
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

bool isSafeInRow(int grid[N][N], int row, int num)
{
    for(int i=0; i<N; i++)
    {
        if(grid[row][i] == num)
        {
            return false;
        }
    }
    return true;
}

bool isSafeInColumn(int grid[N][N], int col, int num)
{
    for(int i=0; i<N; i++)
    {
        if(grid[i][col] == num)
        {
            return false;
        }
    }
    return true;
}

bool isSafeInGrid(int grid[N][N], int row, int col, int num)
{
    int rowFactor = row - (row % 3);
    int colFactor = col - (col % 3);
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(grid[i + rowFactor][j + colFactor] == num)
            {
                return false;
            }
        }
    }
    return true;
}

bool isSafe(int grid[N][N], int row, int col, int num)
{
    if(isSafeInRow(grid, row, num) && isSafeInColumn(grid, col, num) && isSafeInGrid(grid, row, col, num))
    {
        return true;
    }
    return false;
}

bool solveSudoku(int grid[N][N])
{
    int row, col;
    if(!findEmptyLocation(grid, row, col))
    {
        return true;
    }
    for(int i=1; i<=N; i++)
    {
        if(isSafe(grid, row, col, i))
        {
            grid[row][col] = i;
            if(solveSudoku(grid))
            {
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}

int main()
{
    int grid[N][N];
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin>>grid[i][j];
        }
    }
    cout<<(solveSudoku(grid) ? "true":"false");
    return 0;
}