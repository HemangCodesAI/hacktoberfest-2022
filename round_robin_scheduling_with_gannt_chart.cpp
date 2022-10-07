#include <iostream>
using namespace std;
 
const int N=100005;
 
int n,quantum_time;
struct process
{
    int id;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int finishing_time;
    int turn_around_time;
    int remaining_time;
};
process P[N];
 
void RoundRobin()
{
    int complete,current_time,change;
    double total_waiting_time = 0.0;
    double total_turn_around_time = 0.0;
 
    for(int i=0; i<n; i++)
        P[i].remaining_time = P[i].burst_time;
 
    complete = 0;
    current_time = 0;
 
    while(complete < n)
    {
        change = 0;
        for(int i=0; i<n; i++)
        {
            if(P[i].arrival_time <= current_time && P[i].remaining_time > 0)
            {
                if(P[i].remaining_time <= quantum_time)
                {
                    complete++;
                    current_time += P[i].remaining_time;
 
                    P[i].finishing_time = current_time;
                    P[i].turn_around_time = P[i].finishing_time - P[i].arrival_time;
                    P[i].waiting_time = P[i].turn_around_time - P[i].burst_time;
 
                    total_waiting_time += P[i].waiting_time;
                    total_turn_around_time += P[i].turn_around_time;
 
                    P[i].remaining_time = 0;
                }
                else
                {
                    current_time += quantum_time;
                    P[i].remaining_time -= quantum_time;
                }
                change++;
            }
        }
        if(change == 0)
        {
            current_time++;
        }
    }
    cout<<fixed<<setprecision(2);
    cout<<"Average Waiting Time: "<<(total_waiting_time/n)<<"\n";
    cout<<"Average Turn Around Time: "<<(total_turn_around_time/n)<<"\n";
    return;
}
 
int main()
{
    cout<<"Number of Processes: ";
    cin>>n;
 
    cout<<"Quantum time: ";
    cin>>quantum_time;
 
    cout<<"Process Ids:\n";
    for(int i=0; i<n; i++) cin>>P[i].id;
 
    cout<<"Process Burst Times:\n";
    for(int i=0; i<n; i++) cin>>P[i].burst_time;
 
    cout<<"Process Arrival Times:\n";
    for(int i=0; i<n; i++) cin>>P[i].arrival_time;
 
    RoundRobin();
 
    return 0;
}
