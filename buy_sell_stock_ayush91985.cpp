// problem statement- Write a C++ Program to find best buying and selling days of stock




/*
The cost of a stock on each day is given in an array. 
Find the maximum profit that you can make by buying and selling on those days.
If the given array of prices is sorted in decreasing order, then profit cannot be earned at all.

Examples:

Input: arr[] = {100, 180, 260, 310, 40, 535, 695}
Output: 865
Explanation: Buy the stock on day 0 and sell it on day 3 => 310 – 100 = 210
                       Buy the stock on day 4 and sell it on day 6 => 695 – 40 = 655
                       Maximum Profit  = 210 + 655 = 865

Input: arr[] = {4, 2, 2, 2, 4}
Output: 2
Explanation: Buy the stock on day 1 and sell it on day 4 => 4 – 2 = 2
                       Maximum Profit  = 2
		       
*/


#include <bits/stdc++.h>
using namespace std;

// This function finds the buy sell
// schedule for maximum profit
void stockBuySell(int price[], int n)
{
	// Prices must be given for at least two days
	if (n == 1)
		return;

	// Traverse through given price array
	int i = 0;
	while (i < n - 1) {

		// Find Local Minima
		// Note that the limit is (n-2) as we are
		// comparing present element to the next element
		while ((i < n - 1) && (price[i + 1] <= price[i]))
			i++;

		// If we reached the end, break
		// as no further solution possible
		if (i == n - 1)
			break;

		// Store the index of minima
		int buy = i++;

		// Find Local Maxima
		// Note that the limit is (n-1) as we are
		// comparing to previous element
		while ((i < n) && (price[i] >= price[i - 1]))
			i++;

		// Store the index of maxima
		int sell = i - 1;

		cout << "Buy on day: " << buy
			<< "\t Sell on day: " << sell << endl;
	}
}

// Driver code
int main()
{
	// Stock prices on consecutive days
	int price[] = { 100, 180, 260, 310, 40, 535, 695 };
	int n = sizeof(price) / sizeof(price[0]);

	// Function call
	stockBuySell(price, n);

	return 0;
}

// This is code is contributed by rathbhupendra
