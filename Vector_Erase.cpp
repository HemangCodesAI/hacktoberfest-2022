// You are provided with a vector of  integers. Then, you are given  queries. For the first query, you are provided with  integer, which denotes a position in the vector. The value at this position in the vector needs to be erased. The next query consists of  integers denoting a range of the positions in the vector. The elements which fall under that range should be removed. The second query is performed on the updated vector which we get after performing the first query.
// Sample Input

// 6
// 1 4 6 2 8 9
// 2
// 2 4

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int size,pos,start,end,n,i,a,j;
    cin>>n;
    vector<int>v;
    for(i=0;i<n;i++)
    {
        cin>>a;
        v.push_back(a);
    }   
    cin>>pos>>start>>end;
    v.erase(v.begin()+(pos-1));
    v.erase(v.begin()+start-1,v.begin()+end-1);
    size=v.size();
    cout<<size<<endl;
    for(j=0;j<size;j++)
    {
        cout<<v[j]<<" ";
    }
return 0;
}
