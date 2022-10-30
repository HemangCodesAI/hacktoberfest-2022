// A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.

// Input format :
// The first line of input contains an integer value of 'n'. It is the total number of houses.
// The second line of input contains 'n' integer values separated by a single space denoting the amount of money each house has.

// Output format :
// Print the the maximum money that can be looted.

// Input :
// 6
// 10 2 30 20 3 50

// Output :
// 90

// Explanation of Output:
// Looting first, third, and the last houses([10 + 30 + 50]) will result in the maximum loot, and all the other possible combinations would result in less than 90.

#include <iostream>
using namespace std;

int maxMoneyLooted(int *arr, int n)
{
    if(n <= 0)
    {
        return 0;
    }
    int *output = new int[n];
    output[0] = arr[0];
    output[1] = max(arr[0], arr[1]);
    
    for(int i=2; i<n; i++)
    {
        int x = arr[i] + output[i - 2];
        int y = output[i - 1];
        
        output[i] = max(x, y);
    }
    return output[n - 1];
}

int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << maxMoneyLooted(arr, n);

	delete[] arr;
}