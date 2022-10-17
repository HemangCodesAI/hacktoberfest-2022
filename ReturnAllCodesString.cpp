// Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.

// Input Format :
// A numeric string

// Input:
// 1123

// Output:
// aabc
// kbc
// alc
// aaw
// kw

#include <iostream>
using namespace std;

#include <string.h>
using namespace std;

int getCodes(string input, string output[]) {
    if(input.length()==0)
    {
        output[0]="";
        return 1;
    }
    
    string result1[1000];
    int firstDigit=stoi(input.substr(0,1));
    char firstCharacter=96+firstDigit;
    int x=getCodes(input.substr(1),result1);
    
    for(int i=0; i<x; i++)
    {
        output[i]=firstCharacter+result1[i];
    }
    
    int firstTwoDigits=stoi(input.substr(0,2));
    if(firstTwoDigits>=10 && firstTwoDigits<=26)
    {
        firstCharacter=firstTwoDigits+96;
        string result2[1000];
    	int y=getCodes(input.substr(2),result2);
        for(int i=0; i<y; i++)
        {
            output[i+x]=firstCharacter+result2[i];
        }
        return x+y;
    }
    return x;
}

int main(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}