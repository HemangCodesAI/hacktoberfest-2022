// Given a string S, find and return all the possible permutations of the input string.

// Input Format :
// String S

// Output Format :
// All permutations (in different lines)

// Input :
// abc

// Output :
// abc
// acb
// bac
// bca
// cab
// cba

#include <iostream>
#include <string>
#include <string>
using namespace std;

int returnPermutations(string input, string output[]){

    if(input.length()==0)
    {
        output[0]="";
        return 1;
    }
    string result[1000];
    int x,length=0;
    char ch;
    for(int i=0; i<input.length(); i++)
    {
        ch=input[i];
    	string restOfString=input.substr(0,i)+input.substr(i+1);
    	x=returnPermutations(restOfString,result);
    
        for(int j=0; j<x; j++)
        {
            output[length++]=ch+result[j];
        }
    }
    return length;
}


int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}

