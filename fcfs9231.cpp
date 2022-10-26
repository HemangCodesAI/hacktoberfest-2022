#include<iostream>
#define MAX_PROCESS 10
using namespace std;
class process
{
  public:
  int process_num;
  int burst_time;
  int arrival_time;
  int response_time;
  int waiting_time;
  int turnaround_time;
  void input_process(int);
  int get_at()
  {
    return arrival_time;
  }
};
void process::input_process(int count)
{
  process_num=count+1;
  cout<<"\nENTER BURST TIME FOR PROCESS "<<count+1<<" : ";
  cin>>burst_time;
  cout<<"ENTER ARRIVAL TIME FOR PROCESS "<<count+1<<" : ";
  cin>>arrival_time;
}
void calc_wait_tat(process*,int);
void average(process*,int);
void display(process*,int);
int main()
{
  process p[MAX_PROCESS],temp;
  int num,i,j;
  cout<<"ENTER NUMBER OF PROCESSES : ";
  cin>>num;
  for(i=0;i<num;++i)
    p[i].input_process(i);
  for(i=0;i<num;++i)
  {
    for(j=i+1;j<num;++j)
    {
      if(p[i].get_at()>p[j].get_at())
      {
        temp=p[i];
        p[i]=p[j];
        p[j]=temp;
      }
    }
  }
  calc_wait_tat(p,num);
  display(p,num);
  return 0;
}
void calc_wait_tat(process *p,int n)
{
  int i;
  p[0].response_time=0;
  for(i=1;i<n;++i)
  {
    p[i].response_time=p[i-1].burst_time+p[i-1].response_time;
    if(p[i].response_time<p[i].arrival_time)
      p[i].response_time=p[i].arrival_time;
  }
  p[0].waiting_time=0;
  for(i=1;i<n;++i)
    p[i].waiting_time=p[i].response_time-p[i].arrival_time;
  for(i=0;i<n;++i)
    p[i].turnaround_time=p[i].waiting_time+p[i].burst_time;
}
void average(process *p,int n)
{
  float avg_wt=0,avg_tat=0;
  for(int i=0;i<n;++i)
  {
    avg_wt+=(float)p[i].waiting_time;
    avg_tat+=(float)p[i].turnaround_time;
  }
  avg_wt/=n;
  avg_tat/=n;
  cout<<"\n\nAVERAGE WAITING TIME : "<<avg_wt;
  cout<<"\nAVERAGE TURN AROUND TIME : "<<avg_tat;
}
void display(process *p,int n)
{
        cout<<"Processes "<<"  Burst time  "<<" Waiting time  "<<" Turn around time\n";
        for (int i=0;i<n;i++)
        {
                cout<<"\n   "<<p[i].process_num<<"\t\t"<<p[i].burst_time<<"\t     "<<p[i].waiting_time<<"\t\t      "<<p[i].turnaround_time;
        }
        average(p,n);
}
