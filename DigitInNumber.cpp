/*
C++ Program to Count Digits in a Number
*/

#include <iostream>

using namespace std;
 
int main()
{
    int num, count=0;
    
    cout <<"Enter number: \n";
    cin >> num;
    
    //If number is -ve, convert it to +ve
    if(num<0)
        num=num*-1;
    
    while(num>0){
        num=num/10;
        count++;
    }
    
    cout <<"Number of Digits: " << count;
    return 0;
}
