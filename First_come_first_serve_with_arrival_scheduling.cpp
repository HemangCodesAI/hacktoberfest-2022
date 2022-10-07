#include <iostream>
#include <conio.h>
using namespace std;
int main(){
    int pnum,i,j,avgturn,avgwait;
    cout<<"Enter the number of processes: ";
    cin>>pnum;
    int x[pnum],test[pnum],turntime[pnum],waiting[pnum],arrival[pnum];
    int temp1=0,temp2=0,temp3=0,temp4=0,temp5=0,temp6=0,tempturn=0,tempwait=0;
    waiting[0]=0;
    cout<<"Enter the process time for each process: ";
    for (i=0;i<pnum;i++)
    {
        cin>>x[i];
        test[i]=i+1;
    }
    cout<<"Enter the arrival time for each process: ";
    for (i=0;i<pnum;i++)
    {
        cin>>arrival[i];
    }
    for(i=0;i<pnum;i++)
    {
        for(j=i+1;j<pnum;j++)
        {
            if(arrival[i]>arrival[j])
            {
                temp4=x[i];
                x[i]=x[j];
                x[j]=temp4;
                temp1=arrival[i];
                arrival[i]=arrival[j];
                arrival[j]=temp1;
                temp2=test[i];
                test[i]=test[j];
                test[j]=temp2;
            }
        }
    }
    for (i=0;i<pnum;i++)
    {
        temp3=temp3+x[i];
        turntime[i]=temp3-arrival[i];
        temp4+=x[i];
        waiting[i+1]=turntime[i]-arrival[i];
    }
    for (i=0;i<pnum;i++)
    {
        tempturn=+turntime[i];
        tempwait=+waiting[i];
    }
    avgturn=tempturn/pnum;
    avgwait=tempwait/pnum;
    cout<<"process\t\tcpuburst\tarrival\tturnaround\twaiting\n";
    for (int i=0;i<pnum;i++)
    {
        cout<<"p"<<test[i]<<"\t\t"<<x[i]<<"\t\t"<<arrival[i]<<"\t\t"<<turntime[i]<<"\t\t"<<waiting[i]<<"\n";
    }
    cout<<"Average waiting time: "<<avgwait<<"\n"<<"Average Turnaround time: "<<avgturn<<"\n";
}
