#include<iostream>
using namespace std;
int main()
{
    int ar[10],i,n,high,low,mid;
    cout<<"Enter the values in array in ascending order"<<endl;
    for(i=0;i<10;i++)
    {
        cin>>ar[i];
    }
    cout<<"Enter the number to be searched"<<endl;
    cin>>n;
    high=9;
    low=0;
    mid=(high+low)/2;
    while(low<=high)
    {                   
        if(ar[mid]==n)
        {
            cout<<"Number found"<<endl;
            break;
        }
        else if(ar[mid]>n)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
        mid=(high+low)/2;
    }
    return 0;
}