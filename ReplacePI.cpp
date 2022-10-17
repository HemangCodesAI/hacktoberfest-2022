// Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".
 
// Input  :
// xpix
// Output :
// x3.14x

#include <iostream>
#include <cstring>
using namespace std;

void replace(char s[],int count){
    if(strlen(s)==count || strlen(s)==0 ){
        return;
    }
    if(s[count-1]=='p' && s[count]=='i'){
        s[count-1] = '3';
        s[count] = '.';
        for(int i=strlen(s)-1; i>count; i--)
        {
            s[i+2] = s[i];
        }
        s[count+1] = '1';
        s[count+2] = '4';
        count+=2;
        }
    
    
    replace(s,count+1);
    
}
void replacePi(char input[]) {
	replace(input, 1);

}



int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}
