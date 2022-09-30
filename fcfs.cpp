#include<iostream>
using namespace std;
int main()
{
    int bt[10],wt[10],i,tt[10],n;
    cout<<"enter no of processes:";
    cin>>n;
    cout<<"enter burst time of each process:";
    for (i=0;i<n;i++)
    {
        cin>>bt[i];
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
    cout<<"\n\n average waiting time:"<<avgwt;
    cout<<"\n average turn around time:"<<avgtt;
}
