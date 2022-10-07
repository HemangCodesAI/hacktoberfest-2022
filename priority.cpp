
#include<iostream>
#include<conio.h>
using namespace std;
inline void swap(int &a,int &b)
{
int temp;
temp=a;
a=b;
b=temp; 
}
int main()
{
    int n,i,j;
    cout<<"Enter number of processes: ";
    cin>>n;
    int bt[n],p[n],wt[n],tt[n],pr[n];
    cout<<"Enter burst time of each process: ";
    for (i=0;i<n;i++)
    {
        cin>>bt[i];
    }
    cout<<"Enter priority of each process: ";
    for (i=0;i<n;i++)
    {
        cin>>pr[i];
    }
    for(i=0;i<n;i++)
    {
        p[i]=i;
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(pr[i]>pr[j])
            {
                swap(pr[i],pr[j]);
                swap(bt[i],bt[j]);
                swap(p[i],p[j]);
            }
        }
    }
    wt[0]=0;
    cout<<"Waiting time of each process is: ";
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
      cout<<"\n\n process\tburst time\twaiting time\tturn around time";
    for(i=0;i<n;i++)
    {
        cout<<"\n"<<i+1<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tt[i];
    }
    float avgwt=0,avgtt=0;
    for(i=0;i<n;i++)
    {
        avgwt=avgwt+wt[i];
        avgtt=avgtt+tt[i];
    }
    avgwt=avgwt/n;
    avgtt=avgtt/n;
    cout<<"\n\n Average waiting time: "<<avgwt;
    cout<<"\n Average turn around time: "<<avgtt;
}
