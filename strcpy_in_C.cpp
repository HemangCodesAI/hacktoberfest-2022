// Problem Statment: Given two Strings copy the contents of one string to another.

// Example 1:
// Input: str1="Takeuforward", str2=""
// Output: str2=Takeuforward
// Explanation: Contents of str1 is copied in str2

// Example 2:
// Input: str1="computer", str2="science"
// Output: str2=computer
// Explanation: Contents of str1 is copied in str2 


#include <stdio.h> 
#include<string.h>
int main()  
{  
    char str1[20]="take";  
    char str2[20]="uforward"; 
    strcpy(str2,str1);
    printf("After copying, the string would become: %s", str2);  
    return 0;  
}
