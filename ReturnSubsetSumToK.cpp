// Given an array of size n and an integer K, return all subsets of array which sum to K.

// Integer n, Size of input array
// Array elements separated by space
// K 

// Input :
// 9 
// 5 12 3 17 1 18 15 3 17 
// 6

// Output :
// 3 3
// 5 1

#include <iostream>
using namespace std;
int subsetSumToK(int input[], int n, int output[][50], int k) {
    if(n==0)
    {
        if(k==0)
        {
            output[0][0]=0;
            return 1;
        }
        return 0;
    }
    int o1[1000][50],o2[1000][50];
    int x=subsetSumToK(input+1, n-1, o1, k);
    int y=subsetSumToK(input+1, n-1, o2, k-input[0]);
    
    for(int i=0; i<x; i++)
    {
        for(int j=0; j<=output[i][0]; j++)
        {
            output[i][j]=o1[i][j];
        }
    }
     
    for(int i=0; i<y; i++)
    {
        output[i+x][0]=o2[i][0]+1;
        output[i+x][1]=input[0];
        for(int j=2; j<=output[i+x][0]; j++)
        {
            output[i+x][j]=o2[i][j-1];
        }
    }
    return x+y;
}

int main() {
  int input[20],length, output[10000][50], k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];

  cin >> k;
  
  int size = subsetSumToK(input, length, output, k);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}
