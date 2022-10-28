// Whis and Beerus are playing a new game today. They form a tower of N coins and make a move in alternate turns. Beerus plays first. In one step, the player can remove either 1, X, or Y coins from the tower. The person to make the last move wins the game. Can you find out who wins the game?

// Input format :
// The first and the only line of input contains three integer values separated by a single space. They denote the value of N, X and Y, respectively.

// Output format :
// Prints the name of the winner, either 'Whis' or 'Beerus' (Without the quotes).

// Input :
// 10 2 4

// Output :
// Beerus

// Explanation to Input :
// Initially, there are 4 coins,  In the first move, Beerus can remove either 1, 2, or 3 coins in all three cases, Whis can win by removing all the remaining coins. 

#include <iostream>
#include <string>
using namespace std;

string findWinner(int n, int x, int y)
{
    if(x > y)
    {
        int temp = x;
        x = y;
        y = temp;
    }
    int *output = new int[n + 1];
    
    for(int i=1; i<=n; i++)
    {
        if(i == 1 || i == x || i == y)
        {
            output[i] = 1;
        }
        else if(i < x)
        {
            output[i] = !output[i - 1];
        }
        else if(i < y)
        {
            output[i] = !(output[i - 1] && output[i - x]);
        }
        else
        {
            output[i] = !(output[i - 1] && output[i - x] && output[i - y]);
        }
    }
    if(output[n] == 0)
    {
        return "Whis";
    }
    return "Beerus";
}

int main()
{
	int n, x, y;
	cin >> n >> x >> y;
	cout << findWinner(n, x, y);
}