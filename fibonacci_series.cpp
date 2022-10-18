#include <iostream>  
using namespace std;  
int main() 
{  
  int num1=0,num2=1,sum,i,n;    
 cout<<"Enter the number of elements: ";    
 cin>>n;    
 cout<<num1<<" "<<num2<<" ";     
 for(i=2;i<n;++i)  
 {    
  sum=num1+num2;    
  cout<<sum<<" ";    
  num1=num2;    
  num2=sum;    
 }    
   return 0;  
}  
