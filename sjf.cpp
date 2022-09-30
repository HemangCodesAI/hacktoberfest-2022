
#include<iostream>
using namespace std;
int main()
{
    int n,i,j;
    cout<<"enter no of processes:";
    cin>>n;
    int bt[n],p[n],wt[n],tt[n],pr[n];
    cout<<"enter burst time of each process:";
    for (i=0;i<n;i++)
    {
        cin>>bt[i];
    }
    for(i=0;i<n;i++)
    {
        p[i]=i;
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(bt[i]>bt[j])
            {
                swap(bt[i],bt[j]);
                swap(p[i],p[j]);
            }
        }
    }
    wt[0]=0;
    cout<<"waiting time of each process is:";
    for(i=1;i<n;i++)
    {
        wt[i]=wt[(i-1)]+bt[(i-1)];
    }
    for(i=0;i<n;i++)
    {
        cout<<"\nwt["<<i<<"] :"<<wt[i];
    }
    for(i=0;i<n;i++)
    {
        tt[i]=wt[i]+bt[i];
    }
    for(i=0;i<n;i++)
    {
        cout<<"\ntt["<<i<<"]  :"<<tt[i];
    }
    return 0;
}
